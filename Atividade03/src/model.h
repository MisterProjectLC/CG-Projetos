#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "../../Atividade02/src/vec3.h"

using namespace std;

class Model
{
private:
	vector<vec3> points;
	vector<vector<int>> faces;
	string delimiter = "  ";

	vec3 create_point(string line);
	vector<int> create_face(string line);

public:
	Model(ifstream& obj_file);

	string print();
};

