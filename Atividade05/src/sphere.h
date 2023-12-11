#ifndef Sphere_H
#define Sphere_H

#include "hittable.h"
#include "Atividade02/src/vec3.h"

class Sphere : public Hittable {
public:
    Sphere(point3 _center, double _radius, shared_ptr<Material> _material) : center(_center), radius(_radius), mat(_material) {}

    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

private:
    point3 center;
    double radius;
    shared_ptr<Material> mat;
};

#endif

