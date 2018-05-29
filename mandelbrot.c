// Assignment 1 Mandelbrot
//
// Completed by
// Shunyang Li(z5139935)
// Lihuan Li (z5139949)
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

// Add your own #includes here
#include "mandelbrot.h"
#include "pixelColor.h"

// Add your own #defines here

// Add your own function prototypes here



// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// Your function "returns" this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(pixel pixels[TILE_SIZE][TILE_SIZE], complex center, int z) {
    // hint: use this array to store the result from escapeGrid.
    int grid[TILE_SIZE][TILE_SIZE];

    escapeGrid(grid, center, z);
    int i = 0;
    while(i < TILE_SIZE) {
        
        int j = 0;
        
        while(j < TILE_SIZE) {
        
            pixels[j][i] = pixelColor(grid[j][i]);
            
            ++j;
        }
        ++i;
    }
}

// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(complex c) {
    
    int steps = 0;
    complex temp;
    temp.im = 0;
    temp.re = 0;
    
    while (steps < MAX_STEPS &&  (temp.re*temp.re + temp.im*temp.im) < 4) {
        
        double temp1 = temp.re;
        temp.re = temp.re*temp.re - temp.im*temp.im + c.re;
        temp.im = 2 * temp1*temp.im + c.im;
        steps++;
    }

    return steps;
    
}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE], complex center, int z) {

    // TODO: COMPLETE THIS FUNCTION
    int x = 0;
    double deltaX = 1;
    
    //Use this loop function replace pow.
    while(x < z) {
    
        deltaX = 2 * deltaX;
        x++;
    }
    
    deltaX = 1 / deltaX;
    
    double region = deltaX*TILE_SIZE;
    double x_start = center.re - region / 2;
    double y_start = center.im - region / 2;
    
    complex c;
    
    int i = 0;
    while(i < TILE_SIZE) {
        int j = 0;
        while(j < TILE_SIZE) {
        
            c.re = x_start + deltaX*i;
            c.im = y_start + deltaX*j;
            
            grid[j][i] = escapeSteps(c);
            
            ++j;
        }
        ++i;
    }
}

// Add your own functions here.
// Remember to make them static.
