#pragma once
#include <vector>
#include "../../Atividade02/src/vec3.h"

using namespace std;

// Representa uma face de um Modelo.
class Face
{
private:
	vector<vec3> points;
public:
	// Construtor de uma face, dado seus pontos.
	Face(vector<vec3> points);
	
	/// Retorna os pontos da face.
	vector<vec3> get_points();

	/// Retorna uma versão impressa do vetor.
	string to_string();
};

