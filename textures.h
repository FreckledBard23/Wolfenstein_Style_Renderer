#define map_offset 12
#include <stdio.h>

Uint32 floor_texture[] = {
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
    0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFFFF00FF, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000, 0xFF000000
};

Uint32 wall_textures[] = {
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



    0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFF9999aa, 0xFF9999aa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF666666, 0xFF666666, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFFaaaaaa, 0xFF444444,
    0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444, 0xFF444444,
};