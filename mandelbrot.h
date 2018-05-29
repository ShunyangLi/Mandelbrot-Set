// Mandelbrot generation functions
//
// You can compile the full server with the command
// dcc -o mandelbrotServer server.c mandelbrot.c pixelColor.c
//
// Don't change this file

#ifndef _MANDELBROT_H_
#define _MANDELBROT_H_

// Size of each image
#define TILE_SIZE 512

// Escape Steps
#define MAX_STEPS 256
#define NO_ESCAPE -1

// Structs used by the program

// BMP is made of pixels
typedef struct _pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

// Complex Numbers
// Complex number is (re + im * i)
typedef struct _complex {
    double re;
    double im;
} complex;

// Functions you need to implement:
void drawMandelbrot(pixel pixels[TILE_SIZE][TILE_SIZE],
    complex center, int z);
int escapeSteps(complex c);
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE],
    complex center, int z);

#endif // !defined(_MANDELBROT_H_)
