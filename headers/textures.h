#define texture_size 12
#define map_offset 60
#include <stdio.h>

Uint32 floor_textures[] = {
	//null
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    
    	//stone brick
    0xFF111111, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF565656, 0xFF888888, 0xFF111111, 0xFF111111,
    0xFF111111, 0xFF202020, 0xFF111111, 0xFF888888, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF888888, 0xFF111111, 0xFF111111,
    0xFF111111, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF444444, 0xFF555555, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF888888, 0xFF161616, 0xFF111111,
    0xFF111111, 0xFF444444, 0xFF444444, 0xFF888888, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF111111, 0xFF111111,
    0xFF111111, 0xFF444444, 0xFF444444, 0xFF888888, 0xFF606060, 0xFF444444, 0xFF444444, 0xFF171717, 0xFF111111, 0xFF888888, 0xFF111111, 0xFF111111,
    0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFF303030, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF111111, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
    0xFF888888, 0xFF444444, 0xFF111111, 0xFF242424, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF111111, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
    0xFF888888, 0xFF444444, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF111111, 0xFF444444, 0xFF3f3f3f, 0xFF444444, 0xFF444444,
    0xFF888888, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF888888, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
    0xFF888888, 0xFF111111, 0xFF111111, 0xFF111111, 0xFF070707, 0xFF111111, 0xFF888888, 0xFF545454, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
    0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888,
};

Uint32 ceiling_textures[] = {
	//null
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000,

	//rectangular light
    0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFFFDFD96, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944,
    0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944,
	
    	//tiled ceiling
    0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999944, 0xFF999977,
    0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977, 0xFF999977,
};

//index is wall index, value is if the wall is transparent
bool transparent_walls[] = {false, false, false, false, false, false, true, true, true};
bool crawlspace_walls[] = {false, false, false, false, false, false, false, true, false};
bool doors[] = {false, false, false, false, false, false, true, false, false};
Uint32 wall_textures[] = {
	//grey reinforced metal wall
    0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888,
     
	//red reinforced metal wall
    0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000,
    0xFFbb0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFdd0000, 0xFFbb0000,
    0xFFbb0000, 0xFFbb0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFdd0000, 0xFFbb0000, 0xFFbb0000,
    0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000, 0xFFbb0000,

	//yellow reinforced metal wall
    0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFdddd00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFbbbb00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFdddd00, 0xFFbbbb00, 0xFFbbbb00,
    0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00, 0xFFbbbb00,

    	//green reinforced metal wall
    0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00,
    0xFF00bb00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00dd00, 0xFF00bb00,
    0xFF00bb00, 0xFF00bb00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00dd00, 0xFF00bb00, 0xFF00bb00,
    0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00, 0xFF00bb00,

	//blue reinforced metal wall
    0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb,
    0xFF0000bb, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000dd, 0xFF0000bb,
    0xFF0000bb, 0xFF0000bb, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000dd, 0xFF0000bb, 0xFF0000bb,
    0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb, 0xFF0000bb,

	//door
    0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFaaaaaa, 0xFF333333, 0xFF333333,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFF222222, 0xFF222222, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF333333, 0xFF333333,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,

    	//gray metal crawlspace
    0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888,
    0xFF888888, 0xFF888888, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888, 0xFF888888,
    0xFF888888, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF888888,
    0xFF888888, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF888888,
    0xFF888888, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF888888,
    0xFF888888, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF888888,
    0xFF888888, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF888888,
    0xFF888888, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF888888,

    	//mesh wall
    0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000,
    0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060,
    0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000,
    0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060,
    0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000,
    0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060,
    0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000,
    0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060,
    0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000,
    0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060,
    0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000,
    0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060, 0xFF000000, 0xFF606060,
};
