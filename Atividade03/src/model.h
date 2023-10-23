#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "face.h"

using namespace std;

/// Classe representando um modelo tridimensional, formado por pontos e faces.
class Model
{
private:
	/// Vetor dos pontos do modelo.
	vector<vec3> points;
	/// Vetor das faces do modelo.
	vector<Face> faces;

	/// Delimitador de leitura para o arquivo .obj.
	string delimiter = "  ";

	/// Função auxiliar do construtor. Gera um ponto.
	/// @param line Linha de ponto de um arquivo .obj.
	/// @returns Um ponto gerado pela linha do .obj.
	vec3 create_point(string line);
	/// Função auxiliar do construtor. Gera uma face.
	/// @param line Linha de face de um arquivo .obj.
	/// @returns Uma face gerada pela linha do .obj.
	Face create_face(string line);

public:
	/// Construtor do modelo.
	/// @param obj_file Stream de um arquivo .obj.
	Model(ifstream& obj_file);

	/// Retorna um texto de impressão com a lista de pontos e faces do modelo.
	/// @returns Texto de impressão.
	string print();

	/// Retorna um ponto do modelo, dado seu índice.
	/// @param index Índice do ponto a ser obtido.
	/// @returns Ponto a ser obtido.
	vec3 get_point(int index);

	/// Retorna uma face.
	/// @param index Índice da face a ser obtida.
	/// @returns Face a ser obtida.
	Face get_face(int index);
};
