#include "Atividade02/src/vec3.h"

#pragma once

class Point {
public:
	vec3 pos;
	vec3 norm;
	bool has_custom_normal = false;

	/// Construtor básico do Ponto. Para definir uma normal customizada, utilize set_custom_normal.
	/// @param position Posição do ponto.
	Point(vec3 position) {
		pos = position;
	}

	/// Define uma normal dada por arquivo para este ponto.
	/// @param normal Normal dada.
	void set_custom_normal(vec3 normal) {
		norm = normal;
		has_custom_normal = true;
	}

	/// Retorna uma versão escrita deste ponto.
	/// @returns A versão escrita deste ponto.
	string to_string() {
		return pos.to_string();
	}
};