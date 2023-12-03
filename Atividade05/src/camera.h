#ifndef CAMERA_H
#define CAMERA_H

#include <fstream>

#include "hittable.h"
#include "Atividade02/src/global.h"
#include "Atividade02/src/color.h"
#include "Atividade02/src/interval.h"

using namespace std;

class Camera {
public:
    /// Ratio of image width over height
    double aspect_ratio = 1.0;
    /// Rendered image width in pixel count
    int    image_width = 100;
    /// Count of random samples for each pixel
    int    samples_per_pixel = 10;
    /// Maximum number of ray bounces into scene
    int    max_depth = 10;
    /// Camera center
    point3 center = point3(0, 0, 0);


    Camera(std::ofstream* this_file) {
        file = this_file;
    }


    void render(const Hittable& world);

private:
    int    image_height;   // Rendered image height
    point3 pixel00_loc;    // Location of pixel 0, 0
    vec3   pixel_delta_u;  // Offset to pixel to the right
    vec3   pixel_delta_v;  // Offset to pixel below
    std::ofstream* file;


    void initialize();

    Ray get_ray(int i, int j) const;

    vec3 pixel_sample_square() const;

    color ray_color(const Ray& r, int depth, const Hittable& world) const;
};

#endif