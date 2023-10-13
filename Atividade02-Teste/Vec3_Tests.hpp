#include "pch.h"
#include "../Atividade02/src/vec3.h"

TEST(Atividade02_Testes, vec3_Teste_Construtor) {
    vec3 t = vec3();
    vec3 u = vec3(3, 4, 5);

    EXPECT_EQ(t.e[0], 0);
    EXPECT_EQ(t.e[1], 0);
    EXPECT_EQ(t.e[2], 0);
    EXPECT_EQ(t[0], 0);
    EXPECT_EQ(t[1], 0);
    EXPECT_EQ(t[2], 0);
    EXPECT_EQ(u.length(), sqrt(50));
}

TEST(Atividade02_Testes, vec3_Teste_Operação) {
    vec3 t = vec3();
    vec3 u = vec3(3, 4, 5);
    vec3 v = vec3(10, 20, 30);
    vec3 w = vec3(100, 0, 0);

    t += v;
    EXPECT_EQ(t[0], 10);
    EXPECT_EQ(t[1], 20);
    EXPECT_EQ(t[2], 30);

    t *= 5;
    EXPECT_EQ(t[0], 50);
    EXPECT_EQ(t[1], 100);
    EXPECT_EQ(t[2], 150);

    t /= 10;
    EXPECT_EQ(t[0], 5);
    EXPECT_EQ(t[1], 10);
    EXPECT_EQ(t[2], 15);

    EXPECT_EQ((u + v)[0], 13);
    EXPECT_EQ((u + v)[1], 24);
    EXPECT_EQ((u + v)[2], 35);

    EXPECT_EQ((v - u)[0], 7);
    EXPECT_EQ((v - u)[1], 16);
    EXPECT_EQ((v - u)[2], 25);

    EXPECT_EQ((u * v)[0], 30);
    EXPECT_EQ((u * v)[1], 80);
    EXPECT_EQ((u * v)[2], 150);

    EXPECT_EQ((v / 10)[1], 2);
}


TEST(Atividade02_Testes, vec3_Teste_Função) {
    vec3 u = vec3(3, 4, 5);
    vec3 v = vec3(10, 20, 30);
    vec3 w = vec3(100, 0, 0);

    EXPECT_EQ(dot(u, v), 260);
    EXPECT_EQ(unit_vector(w)[0], 1);
    EXPECT_EQ(unit_vector(w)[1], 0);
    EXPECT_EQ(unit_vector(w)[2], 0);
}