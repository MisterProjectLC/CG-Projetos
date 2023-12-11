#include "hittable_model.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

using namespace std;


int main() {
    auto material_ground = make_shared<Lambertian>(color(0.8, 0.8, 0.0));

    // Generate sphere
    HittableList world;
    world.add(make_shared<Sphere>(point3(0, 0, -1), 0.5, material_ground));
    world.add(make_shared<Sphere>(point3(0, -100.5, -1), 100, material_ground));

    std::ofstream mfile;
    mfile.open("sphere_normal_image.ppm");
    Camera cam = Camera(&mfile);

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    //cam.render(world);

    // Generate icosahedron
    ifstream myfile(".\\data\\icosahedron.obj");

    HittableList world2;
    world2.add(make_shared<HittableModel>(myfile, material_ground));
    world2.add(make_shared<Sphere>(point3(-1.2, 0.1, 0.8), 0.5, material_ground));
    world2.add(make_shared<Sphere>(point3(0, -100.5, -1), 100, material_ground));

    std::ofstream mfile2;
    mfile2.open("three_objects_image_angle1.ppm");
    Camera cam2 = Camera(&mfile2);

    cam2.aspect_ratio = 16.0 / 9.0;
    cam2.image_width = 400;
    cam2.samples_per_pixel = 10;
    cam2.max_depth = 3;
    cam2.center = vec3(0, 0, 5);

    cam2.render(world2);


    std::ofstream mfile3;
    mfile3.open("three_objects_image_angle2.ppm");
    Camera cam3 = Camera(&mfile3);

    cam3.aspect_ratio = 16.0 / 9.0;
    cam3.image_width = 400;
    cam3.samples_per_pixel = 10;
    cam3.max_depth = 3;
    cam3.center = vec3(0, 1, -2);

    cam3.render(world2);



}