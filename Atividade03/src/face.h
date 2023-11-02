#ifndef FACE_H
#define FACE_H

#pragma once

#include <vector>
#include "Atividade02/src/vec3.h"
#include "ray.h"

using namespace std;

// Representa uma face de um Modelo.
class Face
{
private:
	vector<vec3> points;
	vec3 w;
	vec3 normal;

public:
	// Construtor de uma face, dado seus pontos.
	Face(vector<vec3> points);
	
	/// Retorna os pontos da face.
	vector<vec3> get_points();

	/// Retorna uma versão impressa do vetor.
	string to_string();

	/// Retorna se dado raio acertou esta face.
	/// @param ray Raio a ser testado.
	/// @returns Se o raio acertou a face. 
	bool hit(Ray ray);
};

#endif