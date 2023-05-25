#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    if (x < 0 || x >= im.w){
        x = (x < 0) ? 0 : im.w - 1;
    }
    else{
        x = x;
    }
    if (y < 0 || y >= im.h){
        y = (y < 0) ? 0 : im.h - 1;
    }
    else{
        y = y;
    }
    if (c < 0 || c >= im.c){
        c = (c < 0) ? 0 : im.c - 1;
    }
    else{
        c = c;
    }
    int value = x + y * im.w + c * im.w * im.h;
    return im.data[value];
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
    for (int i = 0; i < im.h; i++){
        for (int j = 0; j < im.w; j++){
            float r = get_pixel(im, j, i, 0);
            float g = get_pixel(im, j, i, 1);
            float b = get_pixel(im, j, i, 2);
            double gdash = powf((double)g, 1.0 / 2.2);
            double rdash = pow((double)r, 1.0 / 2.2);
            double bdash = powf((double)b, 1.0 / 2.2);

            float value = (0.299 * (float)rdash + 0.587 * (float)gdash + 0.114 * (float)bdash);

            value = (value < 0.0) ? 0.0 : ((value > 1.0) ? 1.0 : value);
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

void clamp_image(image im){
    // TODO Fill this in
        for (int i = 0; i < im.c; i++){
            for (int j = 0; j < im.h; j++){
            for (int k = 0; k < im.w; k++){
                float v = get_pixel(im, k, j, i);
                float new_value = (v < 0) ? 0 : (v > 1 ? 1 : v);
                set_pixel(im, k, j, i, new_value);
            }
            }
        }
}
            // These might be handy
float three_way_max(float a, float b, float c){
                return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
            }

float three_way_min(float a, float b, float c){
                return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
            }

void rgb_to_hsv(image im){
    // TODO Fill this in
    image rgb_to_hsv = make_image(im.w, im.h, im.c);
    for (int i; i < im.h; i++){
        for (int j; j < im.w;j++){
            float r = get_pixel(im, j, i, 0);
            float g = get_pixel(im, j, i, 1);
            float b = get_pixel(im, j, i, 2);
            float V = three_way_max(r, g, b);
            float m = three_way_min(r, g, b);
            float C = V - m;
            float S,H;
            if(V==0){
                S = 0;
            }
            else{
                S = C / V;
            }
            if(C!=0){
                float Hdash;
                if(V==r)
                    Hdash = (g - b) / C;
                else if(V==g)
                    Hdash = (b - r) / C + 2;
                else if(V==b)
                    Hdash = (r - g) / C + 4;
                H = (Hdash < 0) ? (Hdash / 6 + 1) : (Hdash / 6);
            }
            else{
                H = 0;
            } 
            set_pixel(rgb_to_hsv, j, i, 0, H);
            set_pixel(rgb_to_hsv, j, i, 1, S);
            set_pixel(rgb_to_hsv, j, i, 2, V);
         }
    }
    return rgb_to_hsv;
}
void hsv_to_rgb(image im){
    // TODO Fill this in
    image rgb = make_image(im.w, im.h, im.c);
    for (int i = 0; i < im.h;i++){
         for (int j = 0; j < im.w;j++){
            float h = get_pixel(im, j, i, 0);
            float s = get_pixel(im, j, i, 1);
            float v = get_pixel(im, j, i, 2);
            float r, g, b,Hdash;
            if(v==0){
                r = g = b = 0;
            }
            else if(h==0){
                r = g = b = v;
            }
            else{
                Hdash = h * 6;

            }
         }
    }
}
