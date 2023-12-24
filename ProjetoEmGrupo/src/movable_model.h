#include "movable.h"
#include "Atividade05/src/hittable_model.h"

#pragma once

class MovableModel : public Movable, public HittableModel {
public:
	MovableModel(ifstream& obj_file, shared_ptr<Material> _material) : Movable(),
		HittableModel(obj_file, _material) {}

protected:

	point3 recorded_center = point3(0, 0, 0);
	void on_move() override {
		
		for (int i = 0; i < faces.size(); i++) {
			faces[i].move(_center - recorded_center);
		}
		recorded_center = _center;
	}
};