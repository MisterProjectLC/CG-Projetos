#include <vector>
#include "point.h"
#include "hittable.h"
#include "Atividade02/src/vec3.h"
#include "Atividade03/src/ray.h"

#pragma once

class HittableFace : public Hittable
{
private:
	vector<Point> points;
	vec3 w;
	vec3 normal;
	shared_ptr<Material> mat;

public:
	// Construtor de uma face, dado seus pontos.
	HittableFace(vector<Point> points, shared_ptr<Material> _material);

	/// Retorna os pontos da face.
	vector<Point> get_points();

	/// Move a face, dado certo deslocamento.
	/// @param transform O deslocamento.
	void move(vec3 transform);

	/// Retorna uma versão impressa do vetor.
	string to_string();

	/// Retorna se dado raio acertou esta face.
	/// @param ray Raio a ser testado.
	/// @param ray_t Intervalo de distância na qual o raio pode ser detectado.
	/// @param rec Valor de retorno com informações sobre o acerto.
	/// @returns Se o raio acertou a face. 
	bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
};

