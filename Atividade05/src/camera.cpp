#include "camera.h"


void Camera::render(const Hittable& world) {
    initialize();

    (*file) << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int sample = 0; sample < samples_per_pixel; ++sample) {
                Ray r = get_ray(i, j);
                pixel_color += ray_color(r, max_depth, world);
            }
            write_color(*file, pixel_color, samples_per_pixel);
        }
    }

    std::clog << "\rDone.                 \n";
}



void Camera::initialize() {
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Determine viewport dimensions.
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_v = vec3(0, -viewport_height, 0);
    auto camera_direction = unit_vector(target - center);
    
    auto viewport_u = unit_vector(cross(viewport_v, camera_direction))*viewport_width;

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_direction*focal_length - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}



Ray Camera::get_ray(int i, int j) const {
    // Get a randomly sampled camera ray for the pixel at location i,j.
    auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
    auto pixel_sample = pixel_center + pixel_sample_square();

    auto ray_direction = pixel_sample - center;

    return Ray(center, ray_direction);
}

vec3 Camera::pixel_sample_square() const {
    // Returns a random point in the square surrounding a pixel at the origin.
    auto px = -0.5 + random_double();
    auto py = -0.5 + random_double();
    return (px * pixel_delta_u) + (py * pixel_delta_v);
}

color Camera::ray_color(const Ray& r, int depth, const Hittable& world) const {
    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0, 0, 0);

    // Hittable
    HitRecord rec;
    if (world.hit(r, Interval(0.001, infinity), rec)) {
        Ray scattered;
        color attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, depth - 1, world);
        return color(0, 0, 0);
    }

    // Sky
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}