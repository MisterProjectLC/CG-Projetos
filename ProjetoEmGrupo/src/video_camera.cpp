#include "video_camera.h"


void VideoCamera::render(const Hittable& world, vector<shared_ptr<Movable>> movables, shared_ptr<MovableTripod> tripod) {
	double time = 0;
	double time_increment = 1.0 / double(frames_per_second);
	int index = 0;
	while (time < duration_in_seconds) {
		for (shared_ptr<Movable> movable : movables) {
			movable->set_time(time);
		}
		std::ofstream file;
		file.open(video_title + std::to_string(index) + ".ppm");
		Camera camera = Camera(&file, tripod->get_center(), tripod->target->get_center());
		camera.aspect_ratio = aspect_ratio;
		camera.image_width = image_width;
		camera.samples_per_pixel = samples_per_pixel;
		camera.max_depth = max_depth;
		camera.render(world);

		time += time_increment;
		index++;
		std::clog << "\rTime: " + to_string(time);

		file.close();
	}
}