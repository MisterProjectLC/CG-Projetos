#include "painter.h"


CImg<unsigned char> Painter::get_blank_canvas(int width, int height, unsigned char color[]) {
	CImg<unsigned char> image(width, height, 1, 3, 255);
	image.draw_rectangle(0, 0, width, height, color);
	image.display();
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


CImg<unsigned char> Painter::draw_horizontal_gradient(CImg<unsigned char> image, 
		int x0, int y0, unsigned char color1[],	
		int x1, int y1, unsigned char color2[]) {

	for (int x = x0; x < x1; x++) {
		float percentage = ((float)x - (float)x0) / ((float)x1 - (float)x0);
		unsigned char color[] = { 0, 0, 0 };
		color_lerp(color, color1, color2, percentage);

		for (int y = y0; y < y1; y++) {
			image = image.draw_point(x, y, color, 1);
		}
	}

	return image;

}


CImg<unsigned char> Painter::draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned char color[]) {
	CImg<unsigned char> image(100, 100, 1, 3, 0);
	return image;
}


void Painter::save(CImg<unsigned char> image, string title) {
	image.save((title + ".bmp").c_str());
}
