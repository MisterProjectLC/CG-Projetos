#include "painter.h"
#include <iostream>


int main() {
    unsigned char color[] = { 0, 170, 255 };
    
    Painter BobRusso;
    CImg<unsigned char> image = BobRusso.get_blank_canvas(100, 100, color);


    unsigned char black[] = { 0, 0, 0 };
    unsigned char white[] = { 255, 255, 255 };
    image = BobRusso.draw_horizontal_gradient(image, 0, 0, white, 50, 50, black);
    BobRusso.save(image, "my_image");
}