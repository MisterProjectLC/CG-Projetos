#include "painter.h"
#include <iostream>

const void draw_circle(Painter painter) {
    unsigned char bg_color[] = { 177, 177, 177 };
    CImg<unsigned char> image = painter.get_blank_canvas(100, 100, bg_color);

    unsigned char red[] = { 255, 150, 150 };
    painter.draw_circle(&image, 25, 25, 25, red);
    painter.save(image, "image_circle");
}


const void draw_square(Painter painter) {
    unsigned char bg_color[] = { 177, 177, 177 };
    CImg<unsigned char> image = painter.get_blank_canvas(100, 100, bg_color);

    unsigned char green[] = { 100, 255, 100 };
    painter.draw_horizontal_gradient(&image, 25, 25, green, 75, 75, green);
    painter.save(image, "image_square");
}


const void draw_gradient(Painter painter) {
    unsigned char bg_color[] = { 0, 170, 255 };
    CImg<unsigned char> image = painter.get_blank_canvas(100, 100, bg_color);

    unsigned char black[] = { 0, 0, 0 };
    unsigned char white[] = { 255, 255, 255 };
    painter.draw_horizontal_gradient(&image, 0, 0, white, 100, 100, black);
    painter.save(image, "image_gradient");
}


int main() {
    
    Painter BobRusso;
    draw_gradient(BobRusso);
    draw_square(BobRusso);
    draw_circle(BobRusso);
}