#include "drawer.h"

Drawer::Drawer(std::ofstream* file, double aspect_ratio, int image_width, double focal_length, double viewport_height) {
    // Calculate the image height, and ensure that it's at least 1.
    this->aspect_ratio = aspect_ratio;
    this->image_width = image_width;
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    this->focal_length = focal_length;
    this->viewport_height = viewport_height;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    viewport_u = vec3(viewport_width, 0, 0);
    viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    viewport_upper_left = camera_center
        - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	myfile = file;
	(*myfile) << "P3\n" << image_width << " " << image_height << "\n255\n";

}

Drawer::~Drawer() {
	myfile->close();
}


void Drawer::set_camera_pos(vec3 new_camera_pos) {
    camera_center = new_camera_pos;
}


void Drawer::draw(color pixel_color) {
	write_color(*myfile, pixel_color);
}


void Drawer::draw(Face f, color face_color, color bg_color) {
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            if (f.hit(r))
                write_color(*myfile, face_color);
            else
                write_color(*myfile, bg_color);
        }
    }
    std::clog << "\rDone.                 \n";
}


void Drawer::draw(Model m, color model_color, color bg_color) {
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            if (m.hit(r))
                write_color(*myfile, model_color);
            else
                write_color(*myfile, bg_color);
        }
    }
    std::clog << "\rDone.                 \n";
}