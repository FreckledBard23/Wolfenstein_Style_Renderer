#undef main
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#include <time.h>

//screen size
#define screenx 400
#define screeny 300

//pixel buffer - not really used currently but useful
Uint32 pixels[screenx * screeny];

//custom headers
#include <world.h>
#include <textures.h>

//stores ascii keys. extra keys need to be handled seperately
bool keyboard[255];

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
} ray_collision;

//shoots a ray out from source in a direction for a range (number of horizontal / vertical lines
//crossed), SDL_Renderer left over from debug
ray_collision map_ray(float source_x, float source_y, float source_direction, int range, SDL_Renderer * render){
	//fix random errors where rays shoot backwards
	float direction = source_direction;
	if(source_direction < -PI)
		direction += 2 * PI;
	if(source_direction > PI)
		direction -= 2 * PI;
	
	//init ray with extremely high starting distance
	ray_collision ray = {0xFFFFFF, 0, false};
	
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
				if(wall != 0){
					//store distance, final position, wall type, etc.
					ray.dist = distance(source_x, source_y,
							    temp_x,   temp_y);
					ray.hit = wall;
					ray.vertical = false;

					ray.hit_x = temp_x;
					ray.hit_y = temp_y;

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

	//vertical line checks
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

				//if closer than horizontal line check put in all neccisary data
				if(wall != 0 && ray.dist >= v_distance){
					ray.dist = v_distance;
					ray.hit = wall;
					ray.vertical = true;

					ray.hit_x = temp_x;
					ray.hit_y = temp_y;

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
float player_speed = 1;
float player_turn_speed = 0.003;

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

//handle player movement
void movement(){
	float deltax = 0;
	float deltay = 0;
	if(keyboard[SDLK_w]){
		deltax = sin(player_dir) * player_speed;
		deltay = cos(player_dir) * player_speed;
	}
	if(keyboard[SDLK_s]){
		deltax = -sin(player_dir) * player_speed;
		deltay = -cos(player_dir) * player_speed;
	}
	if(keyboard[SDLK_a])
		player_dir -= player_turn_speed;
	if(keyboard[SDLK_d])
		player_dir += player_turn_speed;

	if(player_dir > PI)
		player_dir -= 2 * PI;
	if(player_dir < -PI)
		player_dir += 2 * PI;
	
	if(world[
				(int)((player_x + deltax) / map_offset) + 
				(int)(player_y / map_offset) * WORLDX
			   ] == 0){
		player_x += deltax;
	}
	if(world[
				(int)(player_x / map_offset) + 
				(int)((player_y + deltay) / map_offset) * WORLDX
			   ] == 0){
		player_y += deltay;
	}
}

int main(int argc, char* argv[]) {
	//init all SDL things
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenx, screeny, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, screenx, screeny);

    bool quit = false;

    SDL_Event event;
	
    //init keyboard buffer
    for(int i = 0; i < 255; i++)
	    keyboard[i] = false;

    //main loop
    while (!quit) {
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
                	break;
            	case SDL_KEYUP:
			if(event.key.keysym.sym < 255)
                		keyboard[event.key.keysym.sym] = false;
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
	    
	    movement();
	    
		//debug
	    minimap(renderer);
	    
	    //render walls
	    for(int i = -screenx / 2; i < screenx / 2; i++){
		//calculate angle between each ray based on fov
		int fov = 90;
		float fov_pixel_width = (90 * (PI / 360)) / screenx;
		
		//cast ray
	    	ray_collision ray = map_ray(player_x, player_y, player_dir + (i * fov_pixel_width),
						WORLDX, renderer);
		
		//calculate wall height based on screen height
		int wall_height = screeny / ((ray.dist * cos(i * fov_pixel_width)) / 100);
		
		//get color (will be removed or changed when textured walls)
		float dim = ray.vertical ? 1 : 0.7;
		SDL_Color c = {map_colors[ray.hit].r * dim,
			       map_colors[ray.hit].g * dim,
			       map_colors[ray.hit].b * dim,
			       map_colors[ray.hit].a};
		
		//draw wall
		draw_line(i + screenx / 2, screeny / 2 + wall_height / 2,
			  i + screenx / 2, screeny / 2 - wall_height / 2,
			  c, renderer);
	    }
		
        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
