#include "Atividade02/src/global.h"

#include "Atividade05/src/camera.h"
#include "Atividade02/src/color.h"
#include "Atividade05/src/hittable_list.h"
#include "Atividade05/src/material.h"
#include "Atividade05/src/sphere.h"

int main() {
    HittableList world;

    auto material_ground = make_shared<Lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<Lambertian>(color(0.1, 0.2, 0.5));
    auto material_left = make_shared<Dielectric>(1.5);
    auto material_right = make_shared<Metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<Sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<Sphere>(point3(0.0, 0.0, -1.0), 0.5, material_center));
    world.add(make_shared<Sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(make_shared<Sphere>(point3(-1.0, 0.0, -1.0), -0.4, material_left));
    world.add(make_shared<Sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

    std::ofstream mfile;
    mfile.open("material_spheres.ppm");
    Camera cam = Camera(&mfile);

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world);
}