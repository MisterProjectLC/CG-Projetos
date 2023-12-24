#include "Atividade05/src/camera.h"
#include "movable.h"

#pragma once

class MovableTripod : public Movable {
public:
	shared_ptr<Movable> target;
	MovableTripod(shared_ptr<Movable> target) : Movable() {
		this->target = target;
	}
};
