#include "hittable_face.h"


HittableFace::HittableFace(vector<Point> points, shared_ptr<Material> _material) {
	this->points = points;
	this->mat = _material;

	vec3 u = points[1].pos - points[0].pos;
	vec3 v = points[2].pos - points[0].pos;
	auto n = cross(u, v);

	this->normal = unit_vector(n);

	for (int i = 0; i < 3; i++)
	{
		if (!points[i].has_custom_normal)
			points[i].norm = this->normal;
	}

	this->w = n / dot(n, n);
}

vector<Point> HittableFace::get_points() {
	return points;
}

void HittableFace::move(vec3 transform) {
	for (int i = 0; i < points.size(); i++) {
		points[i].pos += transform;
	}
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
	double D = dot(normal, points[0].pos);

	// Solving for the intersection of a ray and the quad-containing plane;
	double denominator = dot(normal, r.direction());
	if (fabs(denominator) < 1e-8) // Denominator = 0, the ray is parallel;
		return false;

	// Get the intersection point;
	double t = (D - dot(normal, r.origin())) / denominator;

	if (!ray_t.contains(t))
		return false;

	// Determine the hit point lies within the face;
	vec3 p = r.at(t) - points[0].pos;
	vec3 u = points[1].pos - points[0].pos;
	vec3 v = points[2].pos - points[0].pos;

	// Get p's position in planar space
	double a = dot(w, cross(p, v));
	double b = dot(w, cross(u, p));

	rec.set_t(r, t);

	double d0 = r.at(t).distance_to(points[0].pos);
	double d1 = r.at(t).distance_to(points[1].pos);
	double d2 = r.at(t).distance_to(points[2].pos);
	double d_sum = d0 + d1 + d2;
	vec3 return_normal = (d0 * points[0].norm + d1 * points[1].norm + d2 * points[2].norm)/d_sum;

	rec.set_face_normal(r, return_normal);
	rec.mat = mat;

	return (0 < a) && (a < 1) && (0 < b) && (b < 1) && (a + b < 1);

}