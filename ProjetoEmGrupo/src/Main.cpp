#include "Atividade02/src/global.h"

#include <vector>
#include "video_camera.h"
#include "movable_sphere.h"
#include "movable_model.h"
#include "Atividade02/src/color.h"
#include "Atividade05/src/hittable_list.h"
#include "Atividade05/src/material.h"

int main() {
    HittableList world;

    auto material_ground = make_shared<Lambertian>(color(0.8, 0.8, 0.0));
    auto material_pong1 = make_shared<Lambertian>(color(1, 0.25, 0.25));
    auto material_pong2 = make_shared<Lambertian>(color(0.25, 0.25, 1));
    auto material_ball = make_shared<Metal>(color(0.8, 0.6, 0.2), 0.0);

    // Generate icosahedron
    ifstream pong_file(".\\data\\pong_prism.obj");
    ifstream pong2_file(".\\data\\pong_prism.obj");

    auto sphere_ground = make_shared<Sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground);
    auto pong_paddle1 = make_shared<MovableModel>(pong_file, material_pong1);
    auto pong_paddle2 = make_shared<MovableModel>(pong2_file, material_pong2);
    auto sphere_game = make_shared<MovableSphere>(point3(0, 0, 0), 0.25, material_ball);

    world.add(sphere_ground);
    world.add(pong_paddle1);
    world.add(pong_paddle2);
    world.add(sphere_game);

    shared_ptr<MovableTripod> tripod = make_shared<MovableTripod>(sphere_game);
    tripod->add_keyframe(make_shared<Keyframe>(0, point3(0, 0, 50)));
    tripod->add_keyframe(make_shared<Keyframe>(2, point3(0, 10, 50)));

    pong_paddle1->add_keyframe(make_shared<Keyframe>(0, point3(-1.5, 1.5, 0)));
    pong_paddle1->add_keyframe(make_shared<Keyframe>(1.5, point3(-1.5, 0.5, 0)));
    pong_paddle1->add_keyframe(make_shared<Keyframe>(3, point3(-1.5, 3, 0)));
    pong_paddle1->add_keyframe(make_shared<Keyframe>(5, point3(-1.5, 0.5, 0)));

    pong_paddle2->add_keyframe(make_shared<Keyframe>(0, point3(1, 2, 0)));
    pong_paddle2->add_keyframe(make_shared<Keyframe>(1.5, point3(1, 0.5, 0)));
    pong_paddle2->add_keyframe(make_shared<Keyframe>(3.5, point3(1, 2, 0)));
    pong_paddle2->add_keyframe(make_shared<Keyframe>(6, point3(1, 0.5, 0)));

    sphere_game->add_keyframe(make_shared<Keyframe>(0, point3(0, 1, 0)));
    sphere_game->add_keyframe(make_shared<Keyframe>(1.5, point3(-1, 0.5, 0)));
    sphere_game->add_keyframe(make_shared<Keyframe>(3, point3(1, 0, 0)));
    sphere_game->add_keyframe(make_shared<Keyframe>(5, point3(2, 1, 0)));

    vector<shared_ptr<Movable>> movables;
    movables.push_back(tripod);
    movables.push_back(pong_paddle1);
    movables.push_back(pong_paddle2);
    movables.push_back(sphere_game);

    VideoCamera cam = VideoCamera("video_teste");
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 550;
    cam.samples_per_pixel = 4;
    cam.max_depth = 3;

    cam.frames_per_second = 5;
    cam.duration_in_seconds = 5;

    cam.render(world, movables, tripod);
}