#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    return im.data[x+y*im.w+c*im.w*im.h];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    if (x >= 0 && x < im.w && y >= 0 && y < im.h && c >= 0 && c < im.c){
        int value = (x + y * im.w + c * im.w * im.h);
        im.data[value] = v;
    }
    else{
        if (x < 0 || x >= im.w)
            x = (x < 0) ? 0 : im.w - 1;
        if (y < 0 || y >= im.h)
            y = (y < 0) ? 0 : im.h - 1;
        if (c < 0 || c >= im.c)
            c = (c < 0) ? 0 : im.c - 1;
        int value = (x + y * im.w + c * im.w * im.h);
        im.data[value] = v;
    }
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    // TODO Fill this in
    for (int i = 0; i < im.c;i++){
        for (int j = 0; j < im.h;j++){
            for (int k = 0; k < im.w;k++){
                float v = get_pixel(im, k, j, i);
                set_pixel(copy, k, j, i, v);
            }
        }
    }
        return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    // TODO Fill this in
    for (int i = 0; i < im.h;i++){
        for (int j = 0; j < im.w;j++){
            float r = get_pixel(im, j, i, 0);
            float g = get_pixel(im, j, i, 1);
            float b = get_pixel(im, j, i, 2);

            int value = (0.299 * r + 0.587 * g + 0.114 * b);
            set_pixel(gray, j, i, 0, value);
        }
    }

        return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
        for (int i = 0; i < im.h;i++){
            for (int j = 0; j < im.w;j++){
            float value = get_pixel(im, j, i, c);
            float shift = value + v;
            set_pixel(im, j, i, c, shift);
            }
        }
}

void clamp_image(image im)
{
    // TODO Fill this in
        
}
// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
