#include "hittable_face.h"


HittableFace::HittableFace(vector<vec3> points, shared_ptr<Material> _material) {
	this->points = points;
	this->mat = _material;

	vec3 u = points[1] - points[0];
	vec3 v = points[2] - points[0];
	auto n = cross(u, v);

	this->normal = unit_vector(n);
	this->w = n / dot(n, n);
}

vector<vec3> HittableFace::get_points() {
	return points;
}

string HittableFace::to_string() {
	string returned = "POINTS\n";
	for (int i = 0; i < points.size(); i++) {
		returned += points[i].to_string() + "\n";
	}
	return returned;
}


bool HittableFace::hit(const Ray& r, Interval ray_t, HitRecord& rec) const {
	// Get the constant D;
	double D = dot(normal, points[0]);

	// Solving for the intersection of a ray and the quad-containing plane;
	double denominator = dot(normal, r.direction());
	if (fabs(denominator) < 1e-8) // Denominator = 0, the ray is parallel;
		return false;

	// Get the intersection point;
	double t = (D - dot(normal, r.origin())) / denominator;

	if (!ray_t.contains(t))
		return false;

	// Determine the hit point lies within the face;
	vec3 p = r.at(t) - points[0];
	vec3 u = points[1] - points[0];
	vec3 v = points[2] - points[0];

	// Get p's position in planar space
	double a = dot(w, cross(p, v));
	double b = dot(w, cross(u, p));

	rec.set_t(r, t);
	rec.set_face_normal(r, normal);
	rec.mat = mat;

	return (0 < a) && (a < 1) && (0 < b) && (b < 1) && (a + b < 1);

}