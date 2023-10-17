#include "pch.h"
#include "../../Atividade02/src/mat3.h"

TEST(mat3_Testes, mat3_Construtor) {
    mat3 t = mat3();

    EXPECT_EQ(t.e[0][0], 0);
    EXPECT_EQ(t[0][0], 0);
    EXPECT_EQ(t[0][1], 0);
    EXPECT_EQ(t[0][2], 0);
    EXPECT_EQ(t[1][0], 0);
    EXPECT_EQ(t[1][1], 0);
    EXPECT_EQ(t[1][2], 0);
    EXPECT_EQ(t[2][0], 0);
    EXPECT_EQ(t[2][1], 0);
    EXPECT_EQ(t[2][2], 0);
}

TEST(mat3_Testes, mat3_Igualdade) {
    EXPECT_EQ(mat3(), mat3(0, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat3(), mat3(1, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat3(), mat3(0, 0, 1, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat3(), mat3(0, 0, 0, 1, 0, 0, 0, 0, 0));
    EXPECT_NE(mat3(), mat3(0, 0, 0, 0, 1, 0, 0, 0, 0));
    EXPECT_NE(mat3(), mat3(0, 0, 0, 0, 0, 0, 1, 0, 0));
    EXPECT_NE(mat3(), mat3(0, 0, 0, 0, 0, 0, 0, 1, 0));
}

TEST(mat3_Testes, mat3_Operação) {
    mat3 t = mat3();
    mat3 u = mat3(3, 4, 5, 3, 4, 5, 3, 4, 5);
    mat3 v = mat3(10, 10, 10, 20, 20, 20, 30, 30, 30);
    mat3 w = mat3(100, 0, 0, 0, 0, 0, 0, 0, 0);

    t += v;
    EXPECT_EQ(t[0][0], 10);
    EXPECT_EQ(t[0][1], 10);
    EXPECT_EQ(t[0][2], 10);
    EXPECT_EQ(t[1][0], 20);
    EXPECT_EQ(t[1][1], 20);
    EXPECT_EQ(t[1][2], 20);
    EXPECT_EQ(t[2][0], 30);
    EXPECT_EQ(t[2][1], 30);
    EXPECT_EQ(t[2][2], 30);

    t *= 5;
    EXPECT_EQ(t[0][0], 50);
    EXPECT_EQ(t[0][1], 50);
    EXPECT_EQ(t[0][2], 50);
    EXPECT_EQ(t[1][0], 100);
    EXPECT_EQ(t[1][1], 100);
    EXPECT_EQ(t[1][2], 100);
    EXPECT_EQ(t[2][0], 150);
    EXPECT_EQ(t[2][1], 150);
    EXPECT_EQ(t[2][2], 150);

    t /= 10;
    EXPECT_EQ(t[0][0], 5);
    EXPECT_EQ(t[0][1], 5);
    EXPECT_EQ(t[0][2], 5);
    EXPECT_EQ(t[1][0], 10);
    EXPECT_EQ(t[1][1], 10);
    EXPECT_EQ(t[1][2], 10);
    EXPECT_EQ(t[2][0], 15);
    EXPECT_EQ(t[2][1], 15);
    EXPECT_EQ(t[2][2], 15);

    EXPECT_EQ((u + v)[0][0], 13);
    EXPECT_EQ((u + v)[0][1], 14);
    EXPECT_EQ((u + v)[0][2], 15);
    EXPECT_EQ((u + v)[1][0], 23);
    EXPECT_EQ((u + v)[1][1], 24);
    EXPECT_EQ((u + v)[1][2], 25);
    EXPECT_EQ((u + v)[2][0], 33);
    EXPECT_EQ((u + v)[2][1], 34);
    EXPECT_EQ((u + v)[2][2], 35);

    EXPECT_EQ((v - u)[0][0], 7);
    EXPECT_EQ((v - u)[0][1], 6);
    EXPECT_EQ((v - u)[0][2], 5);
    EXPECT_EQ((v - u)[1][0], 17);
    EXPECT_EQ((v - u)[1][1], 16);
    EXPECT_EQ((v - u)[1][2], 15);
    EXPECT_EQ((v - u)[2][0], 27);
    EXPECT_EQ((v - u)[2][1], 26);
    EXPECT_EQ((v - u)[2][2], 25);

    EXPECT_EQ((u * v)[0][0], 30);
    EXPECT_EQ((u * v)[0][1], 40);
    EXPECT_EQ((u * v)[0][2], 50);
    EXPECT_EQ((u * v)[1][0], 60);
    EXPECT_EQ((u * v)[1][1], 80);
    EXPECT_EQ((u * v)[1][2], 100);
    EXPECT_EQ((u * v)[2][0], 90);
    EXPECT_EQ((u * v)[2][1], 120);
    EXPECT_EQ((u * v)[2][2], 150);

    EXPECT_EQ((v / 10)[1][1], 2);
}