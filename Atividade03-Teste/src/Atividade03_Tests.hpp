#include <iostream>
#include <fstream>
#include "..\..\Atividade02\src\vec3.h"
#include "..\..\Atividade03\src\face.h"
#include "..\..\Atividade03\src\model.h"

TEST(Atividade03_Testes, Atividade03_Points) {
    ifstream myfile(".\\data\\icosahedron.obj");

    if (myfile.is_open()) {
        Model m = Model(myfile);

        EXPECT_EQ(m.get_point(0), vec3(0, -0.525731, 0.850651));
        EXPECT_EQ(m.get_point(1), vec3(0.850651, 0, 0.525731));
    }
}


TEST(Atividade03_Testes, Atividade03_Faces) {
    ifstream ico_file(".\\data\\icosahedron.obj");

    if (ico_file.is_open()) {
        Model m = Model(ico_file);

        EXPECT_EQ(m.get_face(0).get_points()[0], vec3(0.850651, 0, -0.525731));
    }

    ifstream boat_file(".\\data\\airboat.obj");

    if (boat_file.is_open()) {
        Model m = Model(boat_file);

        EXPECT_EQ(m.get_face(0).get_points().size(), 8);
    }
}