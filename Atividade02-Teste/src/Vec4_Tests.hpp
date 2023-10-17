#include "pch.h"
#include "../../Atividade02/src/vec4.h"

TEST(vec4_Testes, vec4_Construtor) {
    vec4 t = vec4();
    vec4 u = vec4(3, 4, 5, 6);

    EXPECT_EQ(t.e[0], 0);
    EXPECT_EQ(t.e[1], 0);
    EXPECT_EQ(t.e[2], 0);
    EXPECT_EQ(t.e[3], 0);
    EXPECT_EQ(t[0], 0);
    EXPECT_EQ(t[1], 0);
    EXPECT_EQ(t[2], 0);
    EXPECT_EQ(t[3], 0);
    EXPECT_EQ(u.length(), sqrt(86));
}

TEST(vec4_Testes, vec4_Igualdade) {
    EXPECT_EQ(vec4(), vec4(0, 0, 0, 0));
    EXPECT_NE(vec4(), vec4(1, 0, 0, 0));
    EXPECT_NE(vec4(), vec4(0, 1, 0, 0));
    EXPECT_NE(vec4(), vec4(0, 0, 1, 0));
    EXPECT_NE(vec4(), vec4(0, 0, 0, 1));
}

TEST(vec4_Testes, vec4_Operação) {
    vec4 t = vec4();
    vec4 u = vec4(3, 4, 5, 6);
    vec4 v = vec4(10, 20, 30, 40);
    vec4 w = vec4(100, 0, 0, 0);

    t += v;
    EXPECT_EQ(t, v);

    t *= 5;
    EXPECT_EQ(t[0], 50);
    EXPECT_EQ(t[1], 100);
    EXPECT_EQ(t[2], 150);
    EXPECT_EQ(t[3], 200);

    t /= 10;
    EXPECT_EQ(t[0], 5);
    EXPECT_EQ(t[1], 10);
    EXPECT_EQ(t[2], 15);
    EXPECT_EQ(t[3], 20);

    EXPECT_EQ((u + v)[0], 13);
    EXPECT_EQ((u + v)[1], 24);
    EXPECT_EQ((u + v)[2], 35);
    EXPECT_EQ((u + v)[3], 46);

    EXPECT_EQ((v - u)[0], 7);
    EXPECT_EQ((v - u)[1], 16);
    EXPECT_EQ((v - u)[2], 25);
    EXPECT_EQ((v - u)[3], 34);

    EXPECT_EQ((u * v)[0], 30);
    EXPECT_EQ((u * v)[1], 80);
    EXPECT_EQ((u * v)[2], 150);
    EXPECT_EQ((u * v)[3], 240);

    EXPECT_EQ((v / 10)[1], 2);
}


TEST(vec4_Testes, vec4_Função) {
    vec4 u = vec4(3, 4, 5, 6);
    vec4 v = vec4(10, 20, 30, 40);
    vec4 w = vec4(100, 0, 0, 0);

    EXPECT_EQ(dot(u, v), 500);
    EXPECT_EQ(unit_vector(w), vec4(1, 0, 0, 0));
    EXPECT_EQ(unit_vector(vec4()), vec4());
}