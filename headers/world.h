#define WORLDX 10
#define WORLDY 10

SDL_Color map_colors[] = {{  0,   0,   0, 255},
	       		  {200, 200, 200, 255},
	      	          {255,   0,   0, 255},
	      		  {255, 255,   0, 255},
	      		  {  0, 255,   0, 255},
			  {  0,   0, 255, 255},
			  { 40,  40,  40, 255}};

int world[WORLDX * WORLDY] = 
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 1, 7, 1, 6, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	 1, 1, 2, 3, 4, 5, 4, 3, 2, 1};

int world_state[WORLDX * WORLDY];

int world_flooring[WORLDX * WORLDY] = 
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
	 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int world_ceiling[WORLDX * WORLDY] = 
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 1, 1, 2, 2, 1, 1, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 1, 1, 2, 2, 1, 1, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
