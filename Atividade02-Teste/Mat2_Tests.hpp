#include "pch.h"
#include "../Atividade02/src/mat2.h"

TEST(Atividade02_Testes, mat2_Teste_Construtor) {
    mat2 t = mat2();
    mat2 u = mat2(3, 4, 5, 6);

    EXPECT_EQ(t.e[0][0], 0);
    EXPECT_EQ(t.e[0][1], 0);
    EXPECT_EQ(t.e[1][0], 0);
    EXPECT_EQ(t.e[1][1], 0);
    EXPECT_EQ(t[0][0], 0);
    EXPECT_EQ(t[0][1], 0);
    EXPECT_EQ(t[1][0], 0);
    EXPECT_EQ(t[1][1], 0);
}

TEST(Atividade02_Testes, mat2_Teste_Operação) {
    mat2 t = mat2();
    mat2 u = mat2(3, 4, 5, 6);
    mat2 v = mat2(10, 20, 30, 40);
    mat2 w = mat2(100, 0, 0, 0);

    t += v;
    EXPECT_EQ(t[0][0], 10);
    EXPECT_EQ(t[0][1], 20);
    EXPECT_EQ(t[1][0], 30);
    EXPECT_EQ(t[1][1], 40);

    t *= 5;
    EXPECT_EQ(t[0][0], 50);
    EXPECT_EQ(t[0][1], 100);
    EXPECT_EQ(t[1][0], 150);
    EXPECT_EQ(t[1][1], 200);

    t /= 10;
    EXPECT_EQ(t[0][0], 5);
    EXPECT_EQ(t[0][1], 10);
    EXPECT_EQ(t[1][0], 15);
    EXPECT_EQ(t[1][1], 20);

    EXPECT_EQ((u + v)[0][0], 13);
    EXPECT_EQ((u + v)[0][1], 24);
    EXPECT_EQ((u + v)[1][0], 35);
    EXPECT_EQ((u + v)[1][1], 46);

    EXPECT_EQ((v - u)[0][0], 7);
    EXPECT_EQ((v - u)[0][1], 16);
    EXPECT_EQ((v - u)[1][0], 25);
    EXPECT_EQ((v - u)[1][1], 34);

    EXPECT_EQ((u * v)[0][0], 30);
    EXPECT_EQ((u * v)[0][1], 80);
    EXPECT_EQ((u * v)[1][0], 150);
    EXPECT_EQ((u * v)[1][1], 240);

    EXPECT_EQ((v / 10)[0][1], 2);
}