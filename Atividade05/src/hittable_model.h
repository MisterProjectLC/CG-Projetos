#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "hittable.h"
#include "hittable_face.h"
#include "Atividade02/src/vec3.h"
#include "Atividade03/src/ray.h"

#pragma once

class HittableModel : public Hittable {
private:
	/// Vetor dos pontos do modelo.
	vector<vec3> points;
	/// Vetor das faces do modelo.
	vector<HittableFace> faces;
	/// Material do modelo.
	shared_ptr<Material> mat;

	/// Delimitador de leitura para o arquivo .obj.
	string delimiter = "  ";

	/// Função auxiliar do construtor. Gera um ponto.
	/// @param line Linha de ponto de um arquivo .obj.
	/// @returns Um ponto gerado pela linha do .obj.
	vec3 create_point(string line);
	/// Função auxiliar do construtor. Gera uma face.
	/// @param line Linha de face de um arquivo .obj.
	/// @returns Uma face gerada pela linha do .obj.
	HittableFace create_face(string line);

public:
	/// Construtor do modelo.
	/// @param obj_file Stream de um arquivo .obj.
	/// @param _material Material do modelo.
	HittableModel(ifstream& obj_file, shared_ptr<Material> _material);

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
	HittableFace get_face(int index);

	/// Retorna se dado raio acertou este modelo.
	/// @param ray Raio a ser testado.
	/// @param ray_t Intervalo de distância na qual o raio pode ser detectado.
	/// @param rec Valor de retorno com informações sobre o acerto.
	/// @returns Se o raio acertou a face. 
	bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override;
};

