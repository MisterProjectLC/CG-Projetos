#include "painter.h"


CImg<unsigned char> Painter::get_blank_canvas(int width, int height, unsigned char color[]) {
	CImg<unsigned char> image(width, height, 1, 3, 255);
	image.draw_rectangle(0, 0, width, height, color);
	return image;
}

unsigned char lerp(unsigned char a, unsigned char b, float t) {
	return a + t * (b - a);
}

unsigned char* color_lerp(unsigned char* color, unsigned char* a, unsigned char* b, float t) {
	color[0] = lerp(a[0], b[0], t);
	color[1] = lerp(a[1], b[1], t);
	color[2] = lerp(a[2], b[2], t);
	return color;
}


void Painter::draw_horizontal_gradient(CImg<unsigned char> *image, 
		int x0, int y0, unsigned char color1[],	
		int x1, int y1, unsigned char color2[]) {

	for (int x = x0; x < x1; x++) {
		float percentage = ((float)x - (float)x0) / ((float)x1 - (float)x0);
		unsigned char color[] = { 0, 0, 0 };
		color_lerp(color, color1, color2, percentage);

		for (int y = y0; y < y1; y++) {
			image->draw_point(x, y, color, 1);
		}
	}
}


const float calculate_distance(int x0, int y0, int x1, int y1) {
	return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}


void Painter::draw_circle(CImg<unsigned char>* image, int center_x, int center_y, int radius, unsigned char color[]) {
	for (int x = center_x - radius; x < center_x + radius; x++) {
		for (int y = center_y - radius; y < center_y + radius; y++) {
			if (calculate_distance(x, y, center_x, center_y) <= radius)
				image->draw_point(x, y, color, 1);
		}
	}
}


void Painter::save(CImg<unsigned char> image, string title) {
	image.save((title + ".bmp").c_str());
}
