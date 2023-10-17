#include "pch.h"
#include "../../Atividade02/src/mat4.h"

TEST(Mat4_Testes, mat4_Construtor) {
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

TEST(mat4_Testes, mat4_Igualdade) {
    EXPECT_EQ(mat4(), mat4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat4(), mat4(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat4(), mat4(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat4(), mat4(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat4(), mat4(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat4(), mat4(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0));
    EXPECT_NE(mat4(), mat4(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0));
}

TEST(mat4_Testes, mat4_soma) {
    mat4 t = mat4();
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    t += v;
    EXPECT_EQ(t, v);
}

TEST(mat4_Testes, mat4_multi) {
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    v *= 5;
    EXPECT_EQ(v, mat4(50, 50, 50, 50, 100, 100, 100, 100, 150, 150, 150, 150, 200, 200, 200, 200));
}

TEST(mat4_Testes, mat4_div) {
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    v /= 10;
    EXPECT_EQ(v, mat4(1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4));
}

TEST(mat4_Testes, mat4_soma_entre_dois) {
    mat4 u = mat4(3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6);
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    EXPECT_EQ((u + v), mat4(13, 14, 15, 16, 23, 24, 25, 26, 33, 34, 35, 36, 43, 44, 45, 46));
}

TEST(mat4_Testes, mat4_sub_entre_dois) {
    mat4 u = mat4(3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6);
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    EXPECT_EQ((v - u), mat4(7, 6, 5, 4, 17, 16, 15, 14, 27, 26, 25, 24, 37, 36, 35, 34));
}

TEST(mat4_Testes, mat4_mult_entre_dois) {
    mat4 u = mat4(3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6);
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    EXPECT_EQ((u * v), mat4(30, 40, 50, 60, 60, 80, 100, 120, 90, 120, 150, 180, 120, 160, 200, 240));
}

TEST(mat4_Testes, mat4_div_entre_dois) {
    mat4 u = mat4(3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6, 3, 4, 5, 6);
    mat4 v = mat4(10, 10, 10, 10, 20, 20, 20, 20, 30, 30, 30, 30, 40, 40, 40, 40);

    EXPECT_EQ((v / 10), mat4(1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4));
}