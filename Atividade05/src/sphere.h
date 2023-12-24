#ifndef Sphere_H
#define Sphere_H

#include "hittable.h"
#include "Atividade02/src/vec3.h"

class Sphere : public Hittable {
public:
    Sphere() {
        center = point3(0, 0, 0);
        radius = 1;
    }

    Sphere(point3 _center, double _radius, shared_ptr<Material> _material) : center(_center), radius(_radius), mat(_material) {}

    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;

protected:
    point3 center;
    double radius;
    shared_ptr<Material> mat;
};

#endif

