#define WORLDX 10
#define WORLDY 10

SDL_Color map_colors[] = {{  0,   0,   0, 255},
	       		  {200, 200, 200, 255},
	      	          {255,   0,   0, 255},
	      		  {255, 255,   0, 255},
	      		  {  0,   0, 255, 255}};

int world[WORLDX * WORLDY] = 
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 2, 0, 3, 0, 4, 4, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 2, 3, 4, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 1, 2, 3, 4, 3, 4, 3, 2, 1};
