#include "CImg/CImg.h"
#include <string>

using namespace cimg_library;
using namespace std;

#pragma once

class Painter
{
private:


public:
	CImg<unsigned char> get_blank_canvas(int width, int height, unsigned char color[]);
	void draw_horizontal_gradient(CImg<unsigned char> *image, int x0, int y0, unsigned char color1[],
			int x1, int y1, unsigned char color2[]);
	void draw_circle(CImg<unsigned char>* image, int center_x, int center_y, int radius, unsigned char color[]);

	void save(CImg<unsigned char> image, string title);
};

