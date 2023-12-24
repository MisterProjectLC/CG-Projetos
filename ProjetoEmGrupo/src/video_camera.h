#include <vector>
#include "movable.h"
#include "movable_tripod.h"
#include "Atividade05/src/camera.h"

#pragma once
class VideoCamera
{
public:
    /// Ratio of image width over height
    double aspect_ratio = 1.0;
    /// Rendered image width in pixel count
    int    image_width = 100;
    /// Count of random samples for each pixel
    int    samples_per_pixel = 10;
    /// Maximum number of ray bounces into scene
    int    max_depth = 10;
    /// Frames rendered per second
    int    frames_per_second = 1;
    /// Seconds rendered
    int    duration_in_seconds = 2;


    VideoCamera(string video_title) {
        this->video_title = video_title;
    }


    void render(const Hittable& world, vector<shared_ptr<Movable>> movables, shared_ptr<MovableTripod> tripod);

private:
    int    image_height;   // Rendered image height
    point3 pixel00_loc;    // Location of pixel 0, 0
    vec3   pixel_delta_u;  // Offset to pixel to the right
    vec3   pixel_delta_v;  // Offset to pixel below

    string video_title;
    point3 camera_position = point3(0, 0, 0);
};

