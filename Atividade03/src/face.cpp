#include "face.h"


Face::Face(vector<vec3> points) {
	this->points = points;
}

vector<vec3> Face::get_points() {
	return points;
}

string Face::to_string() {
	string returned = "POINTS\n";
	for (int i = 0; i < points.size(); i++) {
		returned += points[i].to_string() + "\n";
	}
	return returned;
}