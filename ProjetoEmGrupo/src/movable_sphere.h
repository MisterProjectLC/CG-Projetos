#include "movable.h"
#include "Atividade05/src/sphere.h"

#pragma once

class MovableSphere : public Movable, public Sphere {
public:
	MovableSphere(point3 _center, double _radius, shared_ptr<Material> _material) : Movable(), 
		Sphere(_center, _radius,  _material) {}

protected:
	void on_move() override {
		center = get_center();
	}
};