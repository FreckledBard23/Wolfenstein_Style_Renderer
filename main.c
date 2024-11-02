#undef main
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

// To use time library of C
#include <time.h>

#define screenx 400
#define screeny 300

Uint32 pixels[screenx * screeny];

#include <world.h>
#include <textures.h>

bool keyboard[255];
 
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

float distance(float x1, float y1, float x2, float y2){
    float a = abs(x1 - x2);
    float b = abs(y1 - y2);
    return sqrt(a * a + b * b);
}

void draw_line(int x1, int y1, int x2, int y2, SDL_Color color, SDL_Renderer * render) {
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(render, x1, y1, x2, y2);
}

void setPixel(Uint32 color, int x, int y){
    pixels[y * screenx + x] = color;
}

void clear_screen(Uint32 color){
    for(int i = 0; i < screeny * screenx; ++i){pixels[i] = color;}
}

//takes in center x and y and x and y side lengths to draw a filled rectangle
void draw_box_filled(SDL_Renderer *render, int x, int y, SDL_Color color, int xside, int yside){
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = xside;
	rect.h = yside;

	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
    	SDL_RenderDrawRect(render, &rect);
}

typedef struct {
	float dist;
	int hit;
	bool vertical;
	float hit_x;
	float hit_y;
} ray_collision;

ray_collision map_ray(float source_x, float source_y, float source_direction, int range, SDL_Renderer * render){
	//fix random errors where rays shoot backwards
	float direction = source_direction;
	if(source_direction < -PI)
		direction += 2 * PI;
	if(source_direction > PI)
		direction -= 2 * PI;

	ray_collision ray = {1000, 0, false};
	
	float temp_x = source_x;
	float temp_y = source_y;

	//horizontal line checks
	float x_offset = tan(direction) * map_offset;
	float y_offset = map_offset;

	float nearest_border = map_offset - ((int)source_y % map_offset);
	
	bool flipped = false;

	//check if looking to a negative y
	if(direction > PI / 2 || direction < -PI / 2){
		y_offset = -map_offset;
		x_offset *= -1;
		nearest_border = -((int)source_y % map_offset);
		flipped = true;
	}
	
	//move to nearest horizontal line
	temp_y += nearest_border;
	if(!flipped){
		temp_x += (nearest_border / map_offset) * x_offset;
	} else {
		temp_x -= (nearest_border / map_offset) * x_offset;
		temp_y -= 1;
	}
		
	int lines_checked = 0;

	//check if not looking straight up / straight down
	if(direction != PI / 2 && direction != -PI / 2){
		//check range number of horizontal lines
		while(lines_checked < range){
			lines_checked += 1;

			if(!(temp_x < 0 || temp_x > WORLDX * map_offset || 
			     temp_y < 0 || temp_y > WORLDY * map_offset)){
				int wall = world[(int)(temp_x / map_offset) + 
					         (int)(temp_y / map_offset) * WORLDX];
				if(wall != 0){
					ray.dist = distance(source_x, source_y,
							    temp_x,   temp_y);
					ray.hit = wall;
					ray.vertical = false;

					ray.hit_x = temp_x;
					ray.hit_y = temp_y;

					lines_checked = range;
				}
			} else {lines_checked = range;}
			
			//SDL_Color c = {255, 255, 255, 255};
			//draw_box_filled(render, (temp_x / map_offset) * 10, (temp_y / map_offset) * 10, c, 3, 3); 
			temp_x += x_offset;
			temp_y += y_offset;
		}
	}

	return ray;
}

float player_x = 1.5 * map_offset;
float player_y = 1.5 * map_offset;
float player_dir = 0;
float player_speed = 0.1;
float player_turn_speed = 0.003;

void minimap(SDL_Renderer *render){
	for(int i = 0; i < WORLDX; i++){
		for(int j = 0; j < WORLDY; j++){
			draw_box_filled(render, i * 10, j * 10, map_colors[world[j * WORLDX + i]], 9, 9);
		}
	}
	
	SDL_Color player_col = {0, 255, 255, 255};
	draw_box_filled(render, (player_x / map_offset) * 10 - 2,
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

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenx, screeny, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, screenx, screeny);

    bool quit = false;

    SDL_Event event;

    for(int i = 0; i < 255; i++)
	    keyboard[i] = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                }
            }

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

        // Update the texture with the pixel data
        SDL_UpdateTexture(texture, NULL, pixels, screenx * sizeof(Uint32));

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);
          
            //----------Render code here----------//
	    clear_screen(0);
	    
	    movement();
	    minimap(renderer);

	    ray_collision ray = map_ray(player_x, player_y, player_dir, WORLDX, renderer);
		
	    SDL_Color debug_col = {255, 0, 255, 255};
	    draw_line((player_x / map_offset) * 10,
		      (player_y / map_offset) * 10,
		      (ray.hit_x / map_offset) * 10,
		      (ray.hit_y / map_offset) * 10,
		      debug_col, renderer); 
		
        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
