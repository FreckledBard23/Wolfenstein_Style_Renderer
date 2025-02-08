#undef main
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926535

// To use time library of C
#include <time.h>
 
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

#define screenx 1000
#define screeny 1000

Uint32 pixels[screenx * screeny];

void draw_line(int x1, int y1, int x2, int y2, uint32_t color, SDL_Renderer * render) {
	SDL_SetRenderDrawColor(render, (color & 0xFF000000) >> 24, (color & 0xFF0000) >> 16, (color & 0xFF00) >> 8, color & 0xFF);
	SDL_RenderDrawLine(render, x1, y1, x2, y2);
}

void setPixel(Uint32 color, int x, int y){
    pixels[y * screenx + x] = color;
}

void clear_screen(Uint32 color){
    for(int i = 0; i < screeny * screenx; ++i){pixels[i] = color;}
}

//takes in center x and y and x and y side lengths to draw a filled rectangle
void draw_box_filled(int x, int y, Uint32 color, int xside, int yside){
    for(int xoff = -(xside / 2); xoff < xside / 2 + 1; ++xoff){
        for(int yoff = (yside / 2) + 1; yoff > -(yside / 2); --yoff){ 
            int newx = x + xoff;
            int newy = y + yoff;
            if(newx < screenx && newx > 0 && newy < screeny && newy > 0)
                pixels[newy * screenx + newx] = color;
        }
    }
}

float distance(int x1, int y1, int x2, int y2){
    float a = abs(x1 - x2);
    float b = abs(y1 - y2);
    return sqrt(a * a + b * b);
}

int world[1000000];

#define min_room_size 10
#define max_room_size 50
#define min_hallway 6
#define max_hallway 12
#define room_fail 1
#define hallway_chance 0.75
#define tunnel_chance 0.5
#define tunnel_max_length 40

int gen_world(int side, int start_i, int rooms){
	if(rooms == 0)
		return room_fail;

	int x_size = rand() % (max_room_size - min_room_size + 1) + min_room_size;
	int y_size = rand() % (max_room_size - min_room_size + 1) + min_room_size;
	
	bool overlapped = false;
	int og_x = start_i % 1000;
	if(side == 1){
		start_i -= (y_size * 1000) + x_size / 2;
		if(abs(og_x - start_i % 1000) > max_room_size)
			overlapped = true;
	}
	if(side == 2){
		start_i -= (y_size / 2) * 1000 + x_size;
		if(abs(og_x - start_i % 1000) > max_room_size)
			overlapped = true;
	}
	if(side == 3){
		start_i -= x_size / 2;
		if(abs(og_x - start_i % 1000) > max_room_size)
			overlapped = true;
	}
	if(side == 4){
		start_i -= (y_size / 2) * 1000;
		if(abs(og_x - start_i % 1000) > max_room_size)
			overlapped = true;
	}

	if(start_i + y_size * 1000 + x_size < 1000000 && start_i > 2001 && overlapped == false && start_i % 1000 + x_size < 999 && start_i % 1000 > 0){
		bool room_exists = false;
		for(int x = -1; x <= x_size; x++){
			for(int y = -1; y <= y_size; y++){
				if(world[start_i + x + 1000 * y] != 0)
					room_exists = true;
			}
		}
		if(!room_exists){
			for(int x = 0; x < x_size; x++){
				for(int y = 0; y < y_size; y++){
					world[start_i + x + 1000 * y] = 1;
				}
			}
		
			int hallway = rand() % (max_hallway - min_hallway + 1) + min_hallway;
			
			if((float)rand() / (float)RAND_MAX < hallway_chance){
				int r = gen_world(1, start_i + x_size / 2 - (1000 * hallway), rooms - 1);
				if(r == 0){
					world[start_i + x_size / 2 - 1000] = 2;
					for(int i = 2; i <= hallway; i++)
						world[start_i + x_size / 2 - i * 1000] = 1;
				}
			} else if((float)rand() / (float)RAND_MAX < tunnel_chance){
				world[start_i + x_size / 2 - 1000] = 3;
			}

			if((float)rand() / (float)RAND_MAX < hallway_chance){
				if(start_i % 1000 > hallway + 1){
					int r = gen_world(2, start_i + (y_size / 2) * 1000 - hallway, rooms - 1);
					if(r == 0){
						world[start_i + (y_size / 2) * 1000 - 1] = 2;
						for(int i = 2; i <= hallway; i++)
							world[start_i + (y_size / 2) * 1000 - i] = 1;
					}
				}
			} else if((float)rand() / (float)RAND_MAX < tunnel_chance){
				if(start_i % 1000 > hallway + 1)
					world[start_i + (y_size / 2) * 1000 - 1] = 3;
			}

			if((float)rand() / (float)RAND_MAX < hallway_chance){
				int r = gen_world(3, start_i + x_size / 2 + (y_size + hallway) * 1000, rooms - 1);
				if(r == 0){
					world[start_i + x_size / 2 + y_size * 1000] = 2;
					for(int i = 1; i <= hallway; i++)
						world[start_i + x_size / 2 + (i + y_size) * 1000] = 1;
				}
			} else if((float)rand() / (float)RAND_MAX < tunnel_chance){
				world[start_i + x_size / 2 + y_size * 1000] = 3;
			
			}

			if((float)rand() / (float)RAND_MAX < hallway_chance){
				if(start_i % 1000 < 1000 - (hallway + 1)){
					int r = gen_world(4, start_i + x_size + (y_size / 2) * 1000 + hallway, rooms - 1);
					if(r == 0){
						world[start_i + x_size + (y_size / 2) * 1000] = 2;
						for(int i = 1; i <= hallway; i++)
							world[start_i + x_size + (y_size / 2) * 1000 + i] = 1;
					}
				}
			} else if((float)rand() / (float)RAND_MAX < tunnel_chance){
				if(start_i % 1000 > hallway + 1)
					world[start_i + x_size + (y_size / 2) * 1000] = 3;
			}

		} else { return room_fail; }
	} else { return room_fail; }

	return 0;
}

void connect_tunnels(SDL_Renderer* render){
	for(int i = 1; i < 1000000; i++){
		if(world[i] == 3){
			for(int x = -tunnel_max_length; x < tunnel_max_length; x++){
				for(int y = -tunnel_max_length; y < tunnel_max_length; y++){
					if(abs(i % 1000 - (i + x) % 1000) < tunnel_max_length && i + y * 1000 > 1){
						if(world[i + x + y * 1000] == 3){
							int ix = i % 1000;
							int iy = i / 1000;
						//	draw_line(ix, iy, ix + x, iy + y, 0xFF00FF00, render);
						}
					}
				}
			}
		}
	}
}

int map_colors[] = {0, 0xFFFFFFFF, 0xFFFF0000, 0xFF00FF00, 0xFF0000FF};
int main(int argc, char* argv[]) {
	srand(2);
	gen_world(0, 100100, 100);
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenx, screeny, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, screenx, screeny);

    bool quit = false;

    SDL_Event event;

	connect_tunnels(renderer);
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
        }

        // Update the texture with the pixel data
        SDL_UpdateTexture(texture, NULL, pixels, screenx * sizeof(Uint32));

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);
          
            //----------Render code here----------//
	    for(int i = 0; i < 1000000; i++)
		    pixels[i] = map_colors[world[i]];

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
