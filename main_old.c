/*  ---------- TODO ----------
 * Fix raycast system
 * SDL draw line
*/

#undef main
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
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

#define screenx 1920
#define screeny 1080

Uint32 pixels[screenx * screeny];

#define map_x 30
#define map_y 30
#include "textures.h"

#include "soundmanager.h"

int map[map_x * map_y] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,6,6,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

Uint32 map_colors[] = {
    0x00000000, //null
    0xFFaaaaaa, //gray
    0xFFFF0000, //red
    0xFFFFFF00, //yellow
    0xFF00FF00, //green
    0xFF0000FF, //blue
    0xFF999999, //door
    0xFF777777, //open door
};

Uint32 null_col = 0x00000000;

void draw_line(int x1, int y1, int x2, int y2, uint32_t color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; ++i) {
        int pixelX = (int)x;
        int pixelY = (int)y;

        // Check if the pixel coordinates are within the image bounds
        if (pixelX >= 0 && pixelX < screenx && pixelY >= 0 && pixelY < screeny) {
            int index = pixelY * screenx + pixelX;
            pixels[index] = color;
        }

        x += xIncrement;
        y += yIncrement;

        if(SDL_clamp(x, 0, screenx - 1) != x || SDL_clamp(y, 0, screeny - 1) != y) {
            return;
        }
    }
}

void setPixel(Uint32 color, int x, int y){
    pixels[y * screeny + x] = color;
}

void clear_screen(Uint32 color){
    for(int i = 0; i < screeny * screenx; ++i){pixels[i] = color;}
}

void draw_box_filled(int x, int y, Uint32 color, int xside, int yside){
    for(int xoff = 0; xoff < xside; ++xoff){
        for(int yoff = yside; yoff > 0; --yoff){ 
            int newx = x + xoff;
            int newy = y + yoff;
            if(newx < screenx && newx > 0 && newy < screeny && newy > 0)
                pixels[newy * screenx + newx] = color;
        }
    }
}

void draw_box_frame(int x, int y, Uint32 color, int xside, int yside){
    draw_line(x, y, x + xside, y, color);
    draw_line(x + xside, y, x + xside, y + yside, color);
    draw_line(x + xside, y + yside, x, y + yside, color);
    draw_line(x, y + yside, x, y, color);
}

float distance(int x1, int y1, int x2, int y2){
    float a = abs(x1 - x2);
    float b = abs(y1 - y2);
    return sqrt(a * a + b * b);
}

void draw_map(){
    for(int i = 0; i < map_x; i++){
        for(int j = 0; j < map_y; j++){
            draw_box_filled(i * texture_size / 2, j * texture_size / 2, 0x00000000, texture_size / 2, texture_size / 2);

            int col = map[j * map_y + i];
            draw_box_filled(i * texture_size / 2, j * texture_size / 2, map_colors[col], (texture_size / 2) - 1, (texture_size / 2) - 1);
        }
    }
}

float player_x = 180;
float player_y = 180;

float player_direction = 0.01;

float speed = 2;

void draw_player(){
    draw_box_filled((player_x / 2) - 2, (player_y / 2) - 2, 0xFF00FFFF, 4, 4);

    draw_line(player_x / 2, player_y / 2, player_x / 2 + cos(player_direction) * 10, player_y / 2 + sin(player_direction) * 10, 0xFF00FFFF);
}

int collision_check(int x, int y){
    int mapy = (y / map_offset);
    int mapx = (x / map_offset);
    return map[SDL_clamp((mapy) * map_y + (mapx), 0, map_x * map_y)];
}

#define fog_strength 0.05
uint32_t dimColor(uint32_t originalColor, float dimmingFactor) {
    // Extract RGB and A components
    uint8_t originalR = (originalColor >> 16) & 0xFF;
    uint8_t originalG = (originalColor >> 8) & 0xFF;
    uint8_t originalB = (originalColor >> 0) & 0xFF;
    uint8_t originalA = (originalColor >> 24) & 0xFF;

    // Dim each RGB component
    uint8_t dimmedR = (uint8_t)(originalR * dimmingFactor);
    uint8_t dimmedG = (uint8_t)(originalG * dimmingFactor);
    uint8_t dimmedB = (uint8_t)(originalB * dimmingFactor);

    // Recreate the dimmed color
    uint32_t dimmedColor = (originalA << 24) | (dimmedR << 16) | (dimmedG << 8) | dimmedB;

    return dimmedColor;
}

int wall_texture = 0;
int column = 0;
void new_map_ray(SDL_Renderer *render, int x1, int y1, float dir, int range, float *dist, int screen_x_coord){
    float x = x1 + cos(dir);
    float y = y1 + sin(dir);

    for (int i = 0; i <= range; ++i) {
        int int_x = (int)x;
        int int_y = (int)y;

        int col = collision_check(int_x, int_y);
        if(col != 0 && col != 7){
            wall_texture = col;
            if(int_y % map_offset == 0 || int_y % map_offset == map_offset - 1){
                column = int_x % map_offset;
            } else {
                column = int_y % map_offset;
            }
            *dist = distance(x1, y1, x, y);
            return;
        } else {
            *dist = distance(x1, y1, x, y) * cos(dir - player_direction);
            float next_dist = distance(x1, y1, x + cos(dir) * 2, y + sin(dir) * 2) * cos(dir - player_direction);
            float lower_y = screeny / 2 + (screeny / 2 / (*dist / 10));
            float upper_y = screeny / 2 + (screeny / 2 / (next_dist / 10));
            int wall_height = SDL_clamp(lower_y - upper_y, 0, screeny / 2) + 1;
	    
	    Uint32 color = dimColor(floor_texture[((int_y % texture_size) * map_offset) + (int_x % texture_size)], SDL_clamp(1 / (*dist * fog_strength), 0, 1));

	    SDL_SetRenderDrawColor(render, (color & 0xFF0000) >> 16, (color & 0xFF00) >> 8, (color & 0xFF), (color & 0xFF000000) >> 24);
	    SDL_RenderDrawLine(render, (screen_x_coord) + screenx / 2, SDL_clamp(upper_y, 0, screeny / 2), (screen_x_coord) + screenx / 2, lower_y);
            //draw_box_filled((screen_x_coord * 3) + screenx / 2, upper_y,
            //              dimColor(floor_texture[((int_y % map_offset) * map_offset) + (int_x % map_offset)], SDL_clamp(1 / (*dist * fog_strength), 0, 1)),
	    //              3, wall_height);
        }

        //incresing rate causes artifacts, but they are only noticable at a close range, so if far, increase rate
        //optimizaton 100
        if(i < 48){
            x += cos(dir);
            y += sin(dir);
        } else {
            x += 2 * cos(dir);
            y += 2 * sin(dir);
        }

        if(SDL_clamp(x, 0, screenx - 1) != x || SDL_clamp(y, 0, screeny - 1) != y) {
            return;
        }
    }
}

void render_screen(SDL_Renderer * render){
    for(int i = -screenx / 2; i < screenx / 2; i++){
        float dir = (0.0008 * i);
        float dist = 0;
        new_map_ray(render, player_x, player_y, dir + player_direction, 360, &dist, i);
                
        dist = dist * cos(dir);
                
        //map debug
        //draw_line(player_x / 2, player_y / 2, (player_x + cos(dir + player_direction) * dist) / 2, (player_y + sin(dir + player_direction) * dist) / 2, 0xFFFFFF00);

        int column_num = i + screenx / 2;
        float wall_height = screeny / (dist / 10);

        float bottom_y = (screeny - wall_height) / 2;
        float top_y = screeny - (screeny - wall_height) / 2;

        if(SDL_clamp(1 / (dist * fog_strength), 0, 1) > 0.07){
            for(int y = 0; y < texture_size; y++){
                float offset = ((top_y - bottom_y) / texture_size) * y;

                //good luck decoding this
		Uint32 color = dimColor(wall_textures[(y * texture_size + column) + ((texture_size - 1) * (texture_size * texture_size))], SDL_clamp(1 / (dist * fog_strength), 0, 1));

		SDL_SetRenderDrawColor(render, (color & 0xFF0000) >> 16, (color & 0xFF00) >> 8, (color & 0xFF), (color & 0xFF000000) >> 24);
	    	SDL_RenderDrawLine(render, column_num, bottom_y + offset, column_num, bottom_y + offset + ((top_y - bottom_y) / texture_size));
            }
        }
    }
}

void toggle_door(int x, int y){
    int mapy = (y / map_offset);
    int mapx = (x / map_offset);

    if(map[mapy * map_y + mapx] == 6){
        map[mapy * map_y + mapx] = 7;
        return;
    }
}

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenx, screeny, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, screenx, screeny);

    bool quit = false;

    SDL_ShowCursor(0);

    SDL_Event event;

    clock_t start_t, end_t;

    bool forward_movement = false;
    bool backward_movement = false;
    bool left_movement = false;
    bool right_movement = false;

    sound_close_id current_music;
    current_music = playSound("test_music.wav");
    current_music.start_time = clock();

    while (!quit) {
        start_t = clock();

        if((start_t - current_music.start_time) / CLOCKS_PER_SEC >= current_music.seconds){
            freeAudioResources(&current_music);

            current_music = playSound("test_beat.wav");
            current_music.start_time = start_t;
        }

        float player_x_offset = cos(player_direction) * speed;
        float player_y_offset = sin(player_direction) * speed;

        float side_player_x_offset = sin(-player_direction) * speed;
        float side_player_y_offset = cos(-player_direction) * speed;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            
            if (event.type == SDL_MOUSEMOTION) {
                // Get the x-coordinate of mouse movement
                int mouseX = event.motion.xrel;

                // Update player_direction based on mouseX
                player_direction += 0.01 * mouseX; // Move right

                if(mouseX != 0){
                    // Clamp the mouse to the center of the screen
                    SDL_WarpMouseInWindow(window, screenx / 2, screeny / 2);
                }
            }
            
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    quit = true;
                } else if (event.key.keysym.sym == SDLK_w) {
                    forward_movement = true;
                } else if (event.key.keysym.sym == SDLK_s) {
                    backward_movement = true;
                } else if (event.key.keysym.sym == SDLK_a) {
                    left_movement = true;
                } else if (event.key.keysym.sym == SDLK_d) {
                    right_movement = true;
                } else if (event.key.keysym.sym == SDLK_e) {
                    toggle_door(player_x + player_x_offset * 4, player_y + player_y_offset * 4);
                }
            }
            if (event.type == SDL_KEYUP){
                if (event.key.keysym.sym == SDLK_w) {
                    forward_movement = false;
                } else if (event.key.keysym.sym == SDLK_s) {
                    backward_movement = false;
                } else if (event.key.keysym.sym == SDLK_a) {
                    left_movement = false;
                } else if (event.key.keysym.sym == SDLK_d) {
                    right_movement = false;
                }
            }
        }

        // Update the texture with the pixel data
        SDL_UpdateTexture(texture, NULL, pixels, screenx * sizeof(Uint32));

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render the texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);

            //movement
            int forward_collision =  collision_check(player_x + player_x_offset * 4,      player_y + player_y_offset * 4);
            int backward_collision = collision_check(player_x - player_x_offset * 4,      player_y - player_y_offset * 4);
            int left_collision =     collision_check(player_x - side_player_x_offset * 4, player_y - side_player_y_offset * 4);
            int right_collision =    collision_check(player_x + side_player_x_offset * 4, player_y + side_player_y_offset * 4);

            if((forward_collision == 0 || forward_collision == 7) && forward_movement){
                player_x += player_x_offset;
                player_y += player_y_offset;
            }
            if((backward_collision == 0 || backward_collision == 7) && backward_movement){
                player_x -= player_x_offset;
                player_y -= player_y_offset;
            }
            if((left_collision == 0 || left_collision == 7) && left_movement){
                player_x -= side_player_x_offset;
                player_y -= side_player_y_offset;
            }
            if((right_collision == 0 || right_collision == 7) && right_movement){
                player_x += side_player_x_offset;
                player_y += side_player_y_offset;
            }
          
            //----------Render code here----------//
            clear_screen(null_col);

            draw_map();
            draw_player();

            render_screen(renderer);

            if(player_direction > 2 * PI){
                player_direction -= 2 * PI;
            } else if(player_direction < 0) {
                player_direction += 2 * PI;
            }
            
            end_t = clock();

            double time_elapsed = (double)(end_t - start_t) / CLOCKS_PER_SEC;

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    freeAudioResources(&current_music);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
