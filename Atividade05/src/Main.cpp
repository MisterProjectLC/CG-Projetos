#include "hittable_model.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

using namespace std;


int main() {
    // Generate sphere
    HittableList world;
    world.add(make_shared<Sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<Sphere>(point3(0, -100.5, -1), 100));

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
    world2.add(make_shared<HittableModel>(myfile));

    /*vector<vec3> v;
    v.push_back(vec3(0, 1, -1));
    v.push_back(vec3(0.5, 0.5, -2));
    v.push_back(vec3(-0.4, 0.5, -1));
    world2.add(make_shared<HittableFace>(v));
    */

    std::ofstream mfile2;
    mfile2.open("icosahedron_normal_image.ppm");
    Camera cam2 = Camera(&mfile2);

    cam2.aspect_ratio = 16.0 / 9.0;
    cam2.image_width = 400;
    cam2.samples_per_pixel = 10;
    cam2.max_depth = 3;
    cam2.center = vec3(0, 0, 2);

    cam2.render(world2);



}