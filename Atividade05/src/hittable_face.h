#include <vector>
#include "hittable.h"
#include "Atividade02/src/vec3.h"
#include "Atividade03/src/ray.h"

#pragma once

class HittableFace : public Hittable
{
private:
	vector<vec3> points;
	vec3 w;
	vec3 normal;

public:
	// Construtor de uma face, dado seus pontos.
	HittableFace(vector<vec3> points);

	/// Retorna os pontos da face.
	vector<vec3> get_points();

	/// Retorna uma vers�o impressa do vetor.
	string to_string();

	/// Retorna se dado raio acertou esta face.
	/// @param ray Raio a ser testado.
	/// @param ray_t Intervalo de dist�ncia na qual o raio pode ser detectado.
	/// @param rec Valor de retorno com informa��es sobre o acerto.
	/// @returns Se o raio acertou a face. 
	bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
};

