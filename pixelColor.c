// Assignment 1 Mandelbrot: Pixel Color
//
// Completed by
// Shunyang Li (z5139935)
// Lihuan Li (z5139949)
//
// Modified on 2017-??-??
// Tutor's name (dayHH-lab)

#include "mandelbrot.h"
#include "pixelColor.h"

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
//
// You have artistic licence here, so make your Mandelbrot look amazing.
pixel pixelColor(int steps) {
    pixel color = {
        .red = 2 * steps % 256,
        .green = 3 * steps % 256,
        .blue = 4 * steps % 256
    };
    
    return color;
}
