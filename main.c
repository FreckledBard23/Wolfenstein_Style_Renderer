#undef main
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#include <time.h>

//screen size
#define screenx 160
#define screeny 90

//pixel buffer - not really used currently but useful
Uint32 pixels[screenx * screeny];

//custom headers
#include <world.h>
#include <textures.h>

//stores ascii keys. extra keys need to be handled seperately
bool keyboard[255];
bool shift_key;
bool ctrl_key;

//not even sure if this works
void delay(float number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

int round_float(float x){
	float d = x - (int)x;
	if(d < 0.5)
		return (int)x;
	else
		return (int)x + 1;
}

float clamp(float x, float min, float max){
	if(x < min)
		return min;
	else if (x > max)
		return max;
	else
		return x;
}

float min(float x, float y){
	if(x > y)
		return y;
	return x;
}

float max(float x, float y){
	if(x > y)
		return x;
	return y;
}

//deltaTime variables  (https://gamedev.stackexchange.com/questions/110825/how-to-calculate-delta-time-with-sdl)
Uint64 dt_now = 0;
Uint64 dt_last = 0;
double deltaTime = 0;

//self explanatory
float distance(float x1, float y1, float x2, float y2){
    float a = abs(x1 - x2);
    float b = abs(y1 - y2);
    return sqrt(a * a + b * b);
}

//uses SDL draw line
void draw_line(int x1, int y1, int x2, int y2, SDL_Color color, SDL_Renderer * render) {
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(render, x1, y1, x2, y2);
}

//uses the old pixel buffer
void setPixel(Uint32 color, int x, int y){
    pixels[y * screenx + x] = color;
}

//uses old pixel buffer
void clear_screen(Uint32 color){
    for(int i = 0; i < screeny * screenx; ++i){pixels[i] = color;}
}

//takes in center x and y and x and y side lengths to draw a empty rectangle
void draw_box(SDL_Renderer *render, int x, int y, SDL_Color color, int xside, int yside){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = xside;
	rect.h = yside;

	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
    	SDL_RenderDrawRect(render, &rect);
}

//return value for map_ray
typedef struct {
	float dist;
	int hit;
	bool vertical;
	float hit_x;
	float hit_y;
	int texture_column;
	bool transparent;
	int state;
} ray_collision;

//shoots a ray out from source in a direction for a range (number of horizontal / vertical lines
//crossed), SDL_Renderer left over from debug
ray_collision map_ray(float source_x, float source_y, float source_direction, int range, bool ignore_transparents, SDL_Renderer * render){
	//fix random errors where rays shoot backwards
	float direction = source_direction;
	if(source_direction < -PI)
		direction += 2 * PI;
	if(source_direction > PI)
		direction -= 2 * PI;
	
	//init ray with extremely high starting distance
	ray_collision ray = {0xFFFFFF, 0, false, 0, 0, 0, false};
	
	//stores the temporary location of the ray
	float temp_x = source_x;
	float temp_y = source_y;

	//starting horizontal line checks
	float x_offset = tan(direction) * map_offset;
	float y_offset = map_offset;
	
	//nearest horizontal line
	float nearest_border = map_offset - (source_y - ((int)(source_y / map_offset) * map_offset));
	
	bool flipped = false;

	//check if looking to a negative y
	if(direction > PI / 2 || direction < -PI / 2){
		y_offset = -map_offset;
		x_offset *= -1;
		nearest_border = -(source_y - ((int)(source_y / map_offset) * map_offset));
		flipped = true;
	}
	
	//move to nearest horizontal line, using nearest border
	temp_y += nearest_border;
	if(!flipped){
		temp_x += (nearest_border / map_offset) * x_offset;
	} else {
		temp_x -= (nearest_border / map_offset) * x_offset;
		temp_y -= 1;
	}
		
	int lines_checked = 0;

	//check if not looking straight left / straight right
	if(direction != PI / 2 && direction != -PI / 2){
		//check range number of horizontal lines
		while(lines_checked < range){
			lines_checked += 1;
			
			//if on the map
			if(!(temp_x < 0 || temp_x > WORLDX * map_offset || 
			     temp_y < 0 || temp_y > WORLDY * map_offset)){
				//grab current cell
				int wall = world[(int)(temp_x / map_offset) + 
					         (int)(temp_y / map_offset) * WORLDX];

				//if hit
				bool transparent = transparent_walls[wall];
				bool transparent_continue = ignore_transparents ? !transparent : true;

				if(wall != 0 && transparent_continue){
					//store distance, final position, wall type, etc.
					ray.dist = distance(source_x, source_y,
							    temp_x,   temp_y);
					ray.hit = wall;
					ray.vertical = false;

					ray.hit_x = temp_x;
					ray.hit_y = temp_y;

					ray.texture_column = ((int)temp_x % map_offset) * 
							     ((float)texture_size / (float)map_offset);
					ray.transparent = transparent;

					ray.state = world_state[(int)(temp_x / map_offset) + 
					         		(int)(temp_y / map_offset) * WORLDX];

					lines_checked = range;
				}
			} else {lines_checked = range;}
			
			//SDL_Color c = {255, 255, 0, 255};
			//draw_box(render, (temp_x / map_offset) * 10, (temp_y / map_offset) * 10, c, 3, 3); 
			
			//advance ray to next line
			temp_x += x_offset;
			temp_y += y_offset;
		}
	}
	
	//reset temp position
	temp_x = source_x;
	temp_y = source_y;

	//vertical line checkshttps://stackoverflow.com/questions/14066933/direct-way-of-computing-the-clockwise-angle-between-two-vectors
	y_offset = -tan(direction + PI / 2) * map_offset;
	x_offset = map_offset;

	//nearest vertical border
	nearest_border = map_offset - (source_x - ((int)(source_x / map_offset) * map_offset));
	
	flipped = false;

	//check if looking to a negative x
	if(direction < 0){
		x_offset = -map_offset;
		y_offset *= -1;
		nearest_border = -(source_x - ((int)(source_x / map_offset) * map_offset));
		flipped = true;
	}
	
	//move to nearest vertical line
	temp_x += nearest_border;
	if(!flipped){
		temp_y += (nearest_border / map_offset) * y_offset;
	} else {
		temp_y -= (nearest_border / map_offset) * y_offset;
		temp_x -= 1;
	}
		
	lines_checked = 0;

	//check if not looking straight up / straight down
	if(direction != PI && direction != 0 && direction != -PI){
		//check range number of vertical lines
		while(lines_checked < range){
			lines_checked += 1;
			
			//if on the map
			if(!(temp_x < 0 || temp_x > WORLDX * map_offset || 
			     temp_y < 0 || temp_y > WORLDY * map_offset)){

				//get current wall
				int wall = world[(int)(temp_x / map_offset) + 
					         (int)(temp_y / map_offset) * WORLDX];
				//get distance to compare with existing distance
				float v_distance = distance(source_x, source_y,
							    temp_x  , temp_y  );

				bool transparent = transparent_walls[wall];
				bool transparent_continue = ignore_transparents ? !transparent : true;
				//if closer than horizontal line check put in all neccisary data
				if(wall != 0 && ray.dist >= v_distance && transparent_continue){
					ray.dist = v_distance;
					ray.hit = wall;
					ray.vertical = true;

					ray.hit_x = temp_x;
					ray.hit_y = temp_y;
					
					ray.texture_column = ((int)temp_y % map_offset) * 
							     ((float)texture_size / (float)map_offset);
					ray.transparent = transparent;
					
					ray.state = world_state[(int)(temp_x / map_offset) + 
					         		(int)(temp_y / map_offset) * WORLDX];

					lines_checked = range;
				}
			} else {lines_checked = range;}
			
			//SDL_Color c = {255, 255, 255, 255};
			//draw_box(render, (temp_x / map_offset) * 10, (temp_y / map_offset) * 10, c, 3, 3); 
			
			//advance temporary position
			temp_x += x_offset;
			temp_y += y_offset;
		}
	}

	return ray;
}

//player data
float player_x = 1.5 * map_offset;
float player_y = 1.5 * map_offset;
float player_dir = 0;

//player speed
float player_speed = 500;
float player_turn_speed = 1.2;

//for crouching
float player_z = 3;
float standing_z = 3;
float crouching_z = -10;
float crouch_cam_bob = 3;
float crouch_transition_speed = 0.15;
float crouch_slowness = 0.5;

//for camera bobbing
float camera_bob = 0;
float camera_bob_strength = 8;
float camera_bob_speed = 10;

//camera tilt
float forward_tilt = 0;
float side_tilt = 0;
float f_tilt_target = 0;
float s_tilt_target = 0;

//camera tilt strength
float f_tilt_strength = 10;
float s_tilt_strength = 0.03;
float f_dash_tilt_strength = 5; //regular effect multiplyer
float s_dash_tilt_strength = 12; // ^^^^

//dash control
float dash_effect = 1;
float dash_strength = 2;
float dash_falloff = 0.10;
bool dash_debounce = true;

//dash recharging
int dashes_remaining = 0;
float dash_recharger = 0;
float max_dashes = 2;
float seconds_per_dash_recharge = 1;

//mouse data
int mouseX = 0;
int mouseY = 0;

//for doors
float door_speed = 1;
float use_range = map_offset;
//checks if player movement is valid. Checks player position + check amount * delta position. returns a Uint8. 
//	if (returned_val & 1) {//x collision}
//	if (returned_val & 2) {//y collision}
//
//	takes crawlspaces into account
Uint8 player_movement_check(float dx, float dy, int check_amount){
	Uint8 hit_info = 0;

	for(float i = 1; i <= check_amount; i += 0.5){
		bool crawlspace = ctrl_key;
		int world_index_dx = (int)((player_x + dx * i) / map_offset) + WORLDX * (int)(player_y / map_offset);
		int world_index_dy = (int)(player_x / map_offset) + WORLDX * (int)((player_y + dy * i) / map_offset);

		if(world[world_index_dx] != 0 &&
		   !(crawlspace && crawlspace_walls[world[world_index_dx]]) &&
		   !(doors[world[world_index_dx]] && world_state[world_index_dx] == texture_size - 1)){
			hit_info = hit_info | 1;
		}

		if(world[world_index_dy] != 0 && 
		   !(crawlspace && crawlspace_walls[world[world_index_dy]]) && 
		   !(doors[world[world_index_dy]] && world_state[world_index_dy] == texture_size - 1)){
			hit_info = hit_info | 2;
		}
	}
	
	return hit_info;
}

//render tiny debug minimap in top left corner
void minimap(SDL_Renderer *render){
	for(int i = 0; i < WORLDX; i++){
		for(int j = 0; j < WORLDY; j++){
			draw_box(render, i * 10, j * 10, map_colors[world[j * WORLDX + i]], 9, 9);
		}
	}
	
	SDL_Color player_col = {0, 255, 255, 255};
	draw_box(render, (player_x / map_offset) * 10 - 2,
				(player_y / map_offset) * 10 - 2,
				player_col,
				5,
				5);

	draw_line((player_x / map_offset) * 10,
		  (player_y / map_offset) * 10,
		  sin(player_dir) * 10 + (player_x / map_offset) * 10,
		  cos(player_dir) * 10 + (player_y / map_offset) * 10,
		  player_col,
		  render);
}

//define keys
//basic rebinding for players
#define player_forward SDLK_w
#define player_backward SDLK_s
#define player_left SDLK_a
#define player_right SDLK_d
#define player_use SDLK_q

//handle player movement
void movement(){
	//smooth out camera tilt
	forward_tilt = (forward_tilt * 0.85) + (f_tilt_target * 0.15);
	side_tilt = (side_tilt * 0.85) + (s_tilt_target * 0.15);
	
	//make camera tilt return to zero if nothing is pressed
	f_tilt_target = 0;
	s_tilt_target = 0;
	
	//prevent camera bobbing if nothing is pressed
	bool bob_camera = false;
	
	//turning the player
	player_dir += (player_turn_speed * mouseX) * deltaTime;
	
	//standard movement
	float deltax = 0;
	float deltay = 0;
	if(keyboard[player_forward]){
		deltax += sin(player_dir);
		deltay += cos(player_dir);
		bob_camera = true;
		f_tilt_target = -f_tilt_strength;
	}
	if(keyboard[player_backward]){
		deltax += -sin(player_dir);
		deltay += -cos(player_dir);
		bob_camera = true;
		f_tilt_target = f_tilt_strength;
	}
	if(keyboard[player_left]){
		deltax += -cos(-player_dir);
		deltay += -sin(-player_dir);
		bob_camera = true;
		s_tilt_target = s_tilt_strength;
	}
	if(keyboard[player_right]){
		deltax += cos(-player_dir);
		deltay += sin(-player_dir);
		bob_camera = true;
		s_tilt_target = -s_tilt_strength;
	}
	
	//prevent weird errors in raycaster
	if(player_dir > PI)
		player_dir -= 2 * PI;
	if(player_dir < -PI)
		player_dir += 2 * PI;

	//handle dash
	dash_effect = dash_falloff + (dash_effect * (1 - dash_falloff));
	if(shift_key && dash_debounce && (deltax != 0 || deltay != 0) && dashes_remaining > 0){
		dash_debounce = false;
		dash_effect = dash_strength;
		
		f_tilt_target *= f_dash_tilt_strength;
		s_tilt_target *= s_dash_tilt_strength;

		dashes_remaining -= 1;
	}

	if(!shift_key)
		dash_debounce = true;

	if(dashes_remaining == 0){
		dash_recharger += deltaTime;

		if(dash_recharger >= seconds_per_dash_recharge){
			dashes_remaining = max_dashes;
			dash_recharger = 0;
		}
	}

	//handle crouch
	if(ctrl_key){
		player_z = crouching_z * crouch_transition_speed + player_z * (1 - crouch_transition_speed);
		f_tilt_target = 0;
		s_tilt_target = 0;
	} else {
		player_z = standing_z * crouch_transition_speed + player_z * (1 - crouch_transition_speed);
	}
	
	//normalize movement
	float normalize_factor = sqrt((deltax * deltax) + (deltay * deltay));
	if(normalize_factor == 0) {normalize_factor = 1;}
	deltax = (deltax / normalize_factor) * player_speed * dash_effect * (1 - ctrl_key * crouch_slowness) * deltaTime;
	deltay = (deltay / normalize_factor) * player_speed * dash_effect * (1 - ctrl_key * crouch_slowness) * deltaTime;
	
	if(bob_camera)
		camera_bob += camera_bob_speed * deltaTime;
	
	if(!(player_movement_check(deltax, deltay, 2) & 1)){
		player_x += deltax;
	}
	if(!(player_movement_check(deltax, deltay, 2) & 2)){
		player_y += deltay;
	}
	
	//open doors
	if(keyboard[player_use]){
		int world_index = (int)((player_x + sin(player_dir) * use_range) / map_offset) +
			       	  (int)((player_y + cos(player_dir) * use_range) / map_offset) * WORLDX;
		
		if(doors[world[world_index]] && world_state[world_index] == 0){
			world_state[world_index] = 1;
		}

		if(doors[world[world_index]] && world_state[world_index] == texture_size - 1){
			world_state[world_index] = -texture_size - 1;
		}
	}
}

void update_world(){
	//update door states
	for(int i = 0; i < WORLDX * WORLDY; i++){
		if(doors[world[i]] && world_state[i] != 0 && world_state[i] < texture_size - 1){
			world_state[i] += 1;
		}
		if(doors[world[i]] && world_state[i] != 0 && world_state[i] < 0){
			world_state[i] += 1;
		}
	}
}

float floor_tan[screenx];
int main(int argc, char* argv[]) {
	    int fov = 75;
	    float fov_pixel_width = (fov * (PI / 180.0)) / (float)screenx;
    //precompute all tangents for floor / ceiling
    for(int i = 0; i < screenx; i++)
	    floor_tan[i] = tan(fov_pixel_width * (i - screenx / 2));

	//init all SDL things
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenx * 3, screeny * 3, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, screenx, screeny);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, screenx, screeny);

    SDL_ShowCursor(SDL_FALSE);	

    bool quit = false;

    SDL_Event event;
	
    //init keyboard buffer
    for(int i = 0; i < 255; i++)
	    keyboard[i] = false;

    //main loop
    while (!quit) {
	//deltaTime calculations
	dt_last = dt_now;
   	dt_now = SDL_GetPerformanceCounter();

   	deltaTime = (double)((dt_now - dt_last)*1000 / (double)SDL_GetPerformanceFrequency() ) / 1000;

	//event handling stuff
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }

	    //keyboard logic
	    switch(event.type)
            {
            	case SDL_KEYDOWN:
			if(event.key.keysym.sym < 255)
                		keyboard[event.key.keysym.sym] = true;
			if(event.key.keysym.sym == SDLK_LSHIFT)
				shift_key = true;
			if(event.key.keysym.sym == SDLK_LCTRL)
				ctrl_key = true;

                	break;
            	case SDL_KEYUP:
			if(event.key.keysym.sym < 255)
                		keyboard[event.key.keysym.sym] = false;
			if(event.key.keysym.sym == SDLK_LSHIFT)
				shift_key = false;
			if(event.key.keysym.sym == SDLK_LCTRL)
				ctrl_key = false;
                	break;

		case SDL_MOUSEMOTION:
                	// Get the mouse movement and smooth out
			//SDL_GetRelativeMouseState(&mouseX, &mouseY);
			mouseX = event.motion.xrel;
			mouseY = event.motion.yrel;

                    	SDL_WarpMouseInWindow(window, screenx, screeny);
			break;
	    }
        }

        // Update the texture with the old pixel buffer
        SDL_UpdateTexture(texture, NULL, pixels, screenx * sizeof(Uint32));

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);
          
            //----------Render code here----------//
	    clear_screen(0);
	    
	    update_world();
	    movement();
	    
		//debug
	    //minimap(renderer);
	    
	    //rendering
		float cam_bob = ctrl_key ? crouch_cam_bob : camera_bob_strength;
		float camera_bob_offset = sin(camera_bob) * cam_bob;
		//floor
	    	//extra buffer (-30% screeny to 120% screeny) is a very dumb solution to pixels not being drawn after being shifted from camera tilt and view bobbing
		//view bobbing is depth dependant so I can't think of any way to easily pre-compute this
		//I tried to render quads for each floor but couldn't get the positions of the quads to line up at all due to my lack of trig knowledge
		
		for(int j = -(0.4 * screeny) + forward_tilt - player_z * 2; j < screeny * 1.3 + forward_tilt - player_z * 2; j++){
			float ray_angle_l = player_dir + -(screeny / 2) * fov_pixel_width;
			float ray_angle_r = player_dir + (screeny / 2) * fov_pixel_width;
			float ray_angle_fix_l = ray_angle_l < -PI ? ray_angle_l + 2 * PI : ray_angle_l;
		      	      ray_angle_fix_l = ray_angle_l >  PI ? ray_angle_l - 2 * PI : ray_angle_l;
			float ray_angle_fix_r = ray_angle_r < -PI ? ray_angle_r + 2 * PI : ray_angle_r;
		      	      ray_angle_fix_r = ray_angle_r >  PI ? ray_angle_r - 2 * PI : ray_angle_r;
			
			if(j > screeny / 2) {
				//only need one dist to pixel because it is a reflection
				float distance_to_pixel_plain = 100 * (screeny / 2) / ((float)j - screeny / 2 + 0.001);
				float distance_to_pixel = distance_to_pixel_plain / cos(screeny / 2 * fov_pixel_width);
				float floor_x_l = distance_to_pixel * sin(ray_angle_fix_l) + player_x;
				float floor_y_l = distance_to_pixel * cos(ray_angle_fix_l) + player_y;
				float floor_x_r = distance_to_pixel * sin(ray_angle_fix_r) + player_x;
				float floor_y_r = distance_to_pixel * cos(ray_angle_fix_r) + player_y;
					
				float floor_z_offset = forward_tilt + ((player_z * 100) / distance_to_pixel) + (abs(camera_bob_offset * 100) / distance_to_pixel);
				
				for(int i = -screenx / 2; i < screenx / 2; i++){
					float point_dist = distance(floor_x_l, floor_y_l, floor_x_r, floor_y_r);
					float interpolation_val = ((floor_tan[i + screenx / 2] * distance_to_pixel_plain) + point_dist / 2) / point_dist;

					float floor_x = floor_x_l + (float)(floor_x_r - floor_x_l) * interpolation_val;
					float floor_y = floor_y_l + (float)(floor_y_r - floor_y_l) * interpolation_val;

					float floor_z_offset_ = floor_z_offset + side_tilt * i;
					if(floor_x > 0 && floor_x < map_offset * WORLDX && floor_y > 0 && floor_y < map_offset * WORLDY && (int)((float)j + floor_z_offset_) > 0 && (int)((float)j + floor_z_offset_) < screeny){
						int floor_tex = (texture_size * texture_size) * world_flooring[(int)(floor_y / map_offset) * WORLDX +
												       (int)(floor_x / map_offset)];
						int floor_tex_index = floor_tex + (((int)floor_y % map_offset) / (map_offset / texture_size)) * texture_size + (((int)floor_x % map_offset) / (map_offset / texture_size));
						SDL_Color c = {((floor_textures[floor_tex_index] & 0xFF0000) >> 16),
							       ((floor_textures[floor_tex_index] & 0xFF00) >> 8),
							        (floor_textures[floor_tex_index] & 0xFF),
							       255};

						SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
						SDL_RenderDrawPoint(renderer, i + screenx / 2, (int)((float)j + floor_z_offset_));
						SDL_RenderDrawPoint(renderer, i + screenx / 2, (int)((float)j + floor_z_offset_) - 1);
					}
				}
			} else {

				//render ceiling
				float distance_to_pixel_plain = 100 * (screeny / 2) / (float)(screeny / 2 - j);
				float distance_to_pixel = distance_to_pixel_plain / cos(screeny / 2 * fov_pixel_width);
				float floor_x_l = distance_to_pixel * sin(ray_angle_fix_l) + player_x;
				float floor_y_l = distance_to_pixel * cos(ray_angle_fix_l) + player_y;
				float floor_x_r = distance_to_pixel * sin(ray_angle_fix_r) + player_x;
				float floor_y_r = distance_to_pixel * cos(ray_angle_fix_r) + player_y;
				
				float floor_z_offset = forward_tilt + ((player_z * 100) / distance_to_pixel) + (abs(camera_bob_offset * 100) / distance_to_pixel);
				
				for(int i = -screenx / 2; i < screenx / 2; i++){
					float point_dist = distance(floor_x_l, floor_y_l, floor_x_r, floor_y_r);
					float interpolation_val = ((floor_tan[i + screenx / 2] * distance_to_pixel_plain) + point_dist / 2) / point_dist;
					float floor_x = floor_x_l + (float)(floor_x_r - floor_x_l) * interpolation_val;
					float floor_y = floor_y_l + (float)(floor_y_r - floor_y_l) * interpolation_val;
					if(floor_x > 0 && floor_x < map_offset * WORLDX && floor_y > 0 && floor_y < map_offset * WORLDY){
						float floor_z_offset_ = floor_z_offset + side_tilt * i;
						int floor_tex = (texture_size * texture_size) * world_ceiling[(int)(floor_y / map_offset) * WORLDX +
												       (int)(floor_x / map_offset)];
						int floor_tex_index = floor_tex + (((int)floor_y % map_offset) / (map_offset / texture_size)) * texture_size + (((int)floor_x % map_offset) / (map_offset / texture_size));
						SDL_Color c = {((ceiling_textures[floor_tex_index] & 0xFF0000) >> 16),
							       ((ceiling_textures[floor_tex_index] & 0xFF00) >> 8),
							        (ceiling_textures[floor_tex_index] & 0xFF),
							       255};
				
						SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
						SDL_RenderDrawPoint(renderer, i + screenx / 2, (int)((float)j + floor_z_offset_));
						SDL_RenderDrawPoint(renderer, i + screenx / 2, (int)((float)j + floor_z_offset_) - 1);
					}
				}
			}
		}


	    //render walls
	    for(int i = -screenx / 2; i <= screenx / 2; i++){
		//ray
		float ray_angle = player_dir + (i * fov_pixel_width);
		float tilt_offset = forward_tilt + side_tilt * i;


		//                transparent ignored raycast to prevent parts of floors being drawn and instantly covered over
		//cast ray
    		ray_collision _ray = map_ray(player_x, player_y, ray_angle,
					WORLDX, true, renderer);

		float _fixed_ray_dist = _ray.dist * cos(i * fov_pixel_width);
	
		//calculate wall height based on screen height
		float _wall_height = screeny / ((_ray.dist * cos(i * fov_pixel_width)) / 100);

		float _z_offset = tilt_offset + ((player_z * 100) / _fixed_ray_dist) + (abs(camera_bob_offset * 100) / _fixed_ray_dist);




	    	ray_collision ray = map_ray(player_x, player_y, ray_angle,
						WORLDX, false, renderer);

		float fixed_ray_dist = ray.dist * cos(i * fov_pixel_width);
		
		//calculate wall height based on screen height
		float wall_height = screeny / ((ray.dist * cos(i * fov_pixel_width)) / 100);
		
		//open door animation check
		int texture_offset = 0;
		bool draw_nothing = false;
		if(doors[ray.hit])
			texture_offset = -abs(ray.state);

		if(ray.texture_column + texture_offset > texture_size - 1 || ray.texture_column + texture_offset < 0)
			draw_nothing = true;

		//wall texture starting index
		int texture_index = (ray.hit - 1) * (texture_size * texture_size) + clamp(ray.texture_column + texture_offset, 0, texture_size - 1);

		float dim = ray.vertical ? 1 : 0.7;

		float line_offset = (wall_height / texture_size);
		
		float z_offset = tilt_offset + ((player_z * 100) / fixed_ray_dist) + (abs(camera_bob_offset * 100) / fixed_ray_dist);
		
		//if the ray is transparent, draw anything behind it first
		if(ray.transparent){		
			//wall texture starting index
			int _texture_index = (_ray.hit - 1) * (texture_size * texture_size) + _ray.texture_column;

			float _dim = _ray.vertical ? 1 : 0.7;

			float _line_offset = (_wall_height / texture_size);
		
			for(int j = 0; j < texture_size; j++){
				SDL_Color c = {((wall_textures[_texture_index + j * texture_size] & 0xFF0000) >> 16) * _dim,
					       ((wall_textures[_texture_index + j * texture_size] & 0xFF00) >> 8) * _dim,
					        (wall_textures[_texture_index + j * texture_size] & 0xFF) * _dim,
					       255};

					//draw wall
				draw_line(i + screenx / 2, _z_offset + screeny / 2 - _wall_height / 2 + _line_offset * j,
					  i + screenx / 2, _z_offset + screeny / 2 - _wall_height / 2 + _line_offset * (j + 1),
					   c, renderer);
			}
		}

		for(int j = 0; j < texture_size; j++){
			SDL_Color c = {((wall_textures[texture_index + j * texture_size] & 0xFF0000) >> 16) * dim,
				       ((wall_textures[texture_index + j * texture_size] & 0xFF00) >> 8) * dim,
				        (wall_textures[texture_index + j * texture_size] & 0xFF) * dim,
				       255};
			
			if(draw_nothing){
				c.r = 0; c.g = 0; c.b = 0;
			}

			if(c.r != 0 || c.g != 0 || c.b != 0){
				//draw wall
				draw_line(i + screenx / 2, z_offset + screeny / 2 - wall_height / 2 + line_offset * j,
					  i + screenx / 2, z_offset + screeny / 2 - wall_height / 2 + line_offset * (j + 1),
					  c, renderer);
			}
		}
	    }
		
        // Update the screen
        SDL_RenderPresent(renderer);
	
	//printf("frames: %f\n", 1 / deltaTime);
	//clamp at 30 fps
	//	needed because the mouse bugs out at higher framerates
	//	doesn't move a full pixel per frame so it doesn't register
	if(deltaTime < 0.033)
		delay(0.033 - deltaTime);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
