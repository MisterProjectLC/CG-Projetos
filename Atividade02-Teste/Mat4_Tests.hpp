#include "pch.h"
#include "../Atividade02/src/mat4.h"

TEST(Atividade02_Testes, mat4_Teste_Construtor) {
    mat4 t = mat4();

    EXPECT_EQ(t.e[0][0], 0);
    EXPECT_EQ(t[0][0], 0);
    EXPECT_EQ(t[0][1], 0);
    EXPECT_EQ(t[0][2], 0);
    EXPECT_EQ(t[0][3], 0);
    EXPECT_EQ(t[1][0], 0);
    EXPECT_EQ(t[1][1], 0);
    EXPECT_EQ(t[1][2], 0);
    EXPECT_EQ(t[1][3], 0);
    EXPECT_EQ(t[2][0], 0);
    EXPECT_EQ(t[2][1], 0);
    EXPECT_EQ(t[2][2], 0);
    EXPECT_EQ(t[2][3], 0);
    EXPECT_EQ(t[3][0], 0);
    EXPECT_EQ(t[3][1], 0);
    EXPECT_EQ(t[3][2], 0);
    EXPECT_EQ(t[3][3], 0);
}

TEST(Atividade02_Testes, mat4_Teste_Operação) {
    mat4 t = mat4();
    mat4 u = mat4(3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6);
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);
    mat4 w = mat4(100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    t += v;
    EXPECT_EQ(t[0][0], 10);
    EXPECT_EQ(t[0][1], 10);
    EXPECT_EQ(t[0][2], 10);
    EXPECT_EQ(t[0][3], 10);
    EXPECT_EQ(t[1][0], 20);
    EXPECT_EQ(t[1][1], 20);
    EXPECT_EQ(t[1][2], 20);
    EXPECT_EQ(t[1][3], 20);
    EXPECT_EQ(t[2][0], 30);
    EXPECT_EQ(t[2][1], 30);
    EXPECT_EQ(t[2][2], 30);
    EXPECT_EQ(t[2][3], 30);
    EXPECT_EQ(t[3][0], 40);
    EXPECT_EQ(t[3][1], 40);
    EXPECT_EQ(t[3][2], 40);
    EXPECT_EQ(t[3][3], 40);

    t *= 5;
    EXPECT_EQ(t[0][0], 50);
    EXPECT_EQ(t[0][1], 50);
    EXPECT_EQ(t[0][2], 50);
    EXPECT_EQ(t[0][3], 50);
    EXPECT_EQ(t[1][0], 100);
    EXPECT_EQ(t[1][1], 100);
    EXPECT_EQ(t[1][2], 100);
    EXPECT_EQ(t[1][3], 100);
    EXPECT_EQ(t[2][0], 150);
    EXPECT_EQ(t[2][1], 150);
    EXPECT_EQ(t[2][2], 150);
    EXPECT_EQ(t[2][3], 150);
    EXPECT_EQ(t[3][0], 200);
    EXPECT_EQ(t[3][1], 200);
    EXPECT_EQ(t[3][2], 200);
    EXPECT_EQ(t[3][3], 200);

    t /= 10;
    EXPECT_EQ(t[0][0], 5);
    EXPECT_EQ(t[0][1], 5);
    EXPECT_EQ(t[0][2], 5);
    EXPECT_EQ(t[0][3], 5);
    EXPECT_EQ(t[1][0], 10);
    EXPECT_EQ(t[1][1], 10);
    EXPECT_EQ(t[1][2], 10);
    EXPECT_EQ(t[1][3], 10);
    EXPECT_EQ(t[2][0], 15);
    EXPECT_EQ(t[2][1], 15);
    EXPECT_EQ(t[2][2], 15);
    EXPECT_EQ(t[2][3], 15);
    EXPECT_EQ(t[3][0], 20);
    EXPECT_EQ(t[3][1], 20);
    EXPECT_EQ(t[3][2], 20);
    EXPECT_EQ(t[3][3], 20);

    EXPECT_EQ((u + v)[0][0], 13);
    EXPECT_EQ((u + v)[0][1], 14);
    EXPECT_EQ((u + v)[0][2], 15);
    EXPECT_EQ((u + v)[0][3], 16);
    EXPECT_EQ((u + v)[1][0], 23);
    EXPECT_EQ((u + v)[1][1], 24);
    EXPECT_EQ((u + v)[1][2], 25);
    EXPECT_EQ((u + v)[1][3], 26);
    EXPECT_EQ((u + v)[2][0], 33);
    EXPECT_EQ((u + v)[2][1], 34);
    EXPECT_EQ((u + v)[2][2], 35);
    EXPECT_EQ((u + v)[2][3], 36);
    EXPECT_EQ((u + v)[3][0], 43);
    EXPECT_EQ((u + v)[3][1], 44);
    EXPECT_EQ((u + v)[3][2], 45);
    EXPECT_EQ((u + v)[3][3], 46);

    EXPECT_EQ((v - u)[0][0], 7);
    EXPECT_EQ((v - u)[0][1], 6);
    EXPECT_EQ((v - u)[0][2], 5);
    EXPECT_EQ((v - u)[0][3], 4);
    EXPECT_EQ((v - u)[1][0], 17);
    EXPECT_EQ((v - u)[1][1], 16);
    EXPECT_EQ((v - u)[1][2], 15);
    EXPECT_EQ((v - u)[1][3], 14);
    EXPECT_EQ((v - u)[2][0], 27);
    EXPECT_EQ((v - u)[2][1], 26);
    EXPECT_EQ((v - u)[2][2], 25);
    EXPECT_EQ((v - u)[2][3], 24);
    EXPECT_EQ((v - u)[3][0], 37);
    EXPECT_EQ((v - u)[3][1], 36);
    EXPECT_EQ((v - u)[3][2], 35);
    EXPECT_EQ((v - u)[3][3], 34);

    EXPECT_EQ((u * v)[0][0], 30);
    EXPECT_EQ((u * v)[0][1], 40);
    EXPECT_EQ((u * v)[0][2], 50);
    EXPECT_EQ((u * v)[0][3], 60);
    EXPECT_EQ((u * v)[1][0], 60);
    EXPECT_EQ((u * v)[1][1], 80);
    EXPECT_EQ((u * v)[1][2], 100);
    EXPECT_EQ((u * v)[1][3], 120);
    EXPECT_EQ((u * v)[2][0], 90);
    EXPECT_EQ((u * v)[2][1], 120);
    EXPECT_EQ((u * v)[2][2], 150);
    EXPECT_EQ((u * v)[2][3], 180);
    EXPECT_EQ((u * v)[3][0], 120);
    EXPECT_EQ((u * v)[3][1], 160);
    EXPECT_EQ((u * v)[3][2], 200);
    EXPECT_EQ((u * v)[3][3], 240);

    EXPECT_EQ((v / 10)[1][1], 2);
}