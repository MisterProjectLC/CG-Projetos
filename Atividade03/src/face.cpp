#include "face.h"


Face::Face(vector<vec3> points) {
	this->points = points;

	vec3 u = points[1] - points[0];
	vec3 v = points[2] - points[0];
	auto n = cross(u, v);

	this->normal = unit_vector(n);
	this->w = n / dot(n, n);
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


bool Face::hit(Ray ray) {
	// Get the constant D;
	double D = dot(normal, points[0]);

	// Solving for the intersection of a ray and the quad-containing plane;
	double denominator = dot(normal, ray.direction());
	if (fabs(denominator) < 1e-8) // Denominator = 0, the ray is parallel;
		return false;

	// Get the intersection point;
	double t = (D - dot(normal, ray.origin())) / denominator;

	// Determine the hit point lies within the face;
	vec3 p = ray.at(t) - points[0];
	vec3 u = points[1] - points[0];
	vec3 v = points[2] - points[0];

		// Get p's position in planar space
	double a = dot(w, cross(p, v));
	double b = dot(w, cross(u, p));

	return (0 < a) && (a < 1) && (0 < b) && (b < 1) && (a + b < 1);

}