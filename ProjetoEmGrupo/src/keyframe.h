#include "Atividade02/src/vec3.h"

#pragma once
class Keyframe
{
public:
	double time;
	point3 pos;


	/// Construtor padr�o de Movement.
	/// @param time Tempo do keyframe.
	/// @param pos Posi��o do keyframe.
	Keyframe(double time, point3 pos) {
		this->time = time;
		this->pos = pos;
	}
};

