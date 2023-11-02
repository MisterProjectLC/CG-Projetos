#include "Atividade03/src/face.h"
#include "Atividade03/src/model.h"
#include "drawer.h"

using namespace std;

bool hit_sphere(const point3& center, double radius, const Ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

color ray_sphere_color(const Ray& r) {
    if (hit_sphere(point3(0, 0, -1), 0.5, r))
        return color(1, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}


color ray_triangle_color(const Ray& r, Face f) {
    if (f.hit(r))
        return color(1, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}


color ray_model_color(const Ray& r, Model m) {
    if (m.hit(r))
        return color(1, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}


int main() {

    // Image

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
        - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render sphere
    std::ofstream file;
    file.open("sphere_image.ppm");
    Drawer BobRusso = Drawer(&file, aspect_ratio, image_width, focal_length, viewport_height);

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            color pixel_color = ray_sphere_color(r);
            BobRusso.draw(pixel_color);
        }
    }


    // Render triangle
    std::ofstream trifile;
    trifile.open("triangle_image.ppm");
    Drawer Picasso = Drawer(&trifile, aspect_ratio, image_width, focal_length, viewport_height);

    vector<vec3> v;
    v.push_back(vec3(0, 1, -1));
    v.push_back(vec3(0.5, 0.5, -2));
    v.push_back(vec3(-0.4, 0.5, -1));
    Face f = Face(v);

    Picasso.draw(f, color(0, 0, 0), color(1, 0, 0));

    // Render Model
    ifstream myfile(".\\data\\icosahedron.obj");
    Model m = Model(myfile);

    std::ofstream mfile;
    mfile.open("model_image.ppm");
    Drawer DaVinci = Drawer(&mfile, aspect_ratio, image_width, focal_length, viewport_height);

    DaVinci.set_camera_pos(vec3(0, 0, -2));
    DaVinci.draw(m, color(0, 0, 0), color(1, 0, 0));

    return 0;
}