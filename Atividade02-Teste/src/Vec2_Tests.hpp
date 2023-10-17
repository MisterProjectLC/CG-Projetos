#include "pch.h"
#include "../../Atividade02/src/vec2.h"

TEST(vec2_Testes, vec2_Construtor) {
    vec2 t = vec2();
    vec2 u = vec2(3, 4);

    EXPECT_EQ(t.e[0], 0);
    EXPECT_EQ(t.e[1], 0);
    EXPECT_EQ(t[0], 0);
    EXPECT_EQ(t[1], 0);
    EXPECT_EQ(u.length(), 5);
}

TEST(vec2_Testes, vec2_Igualdade) {
    EXPECT_EQ(vec2(), vec2(0,0));
    EXPECT_NE(vec2(), vec2(1, 0));
    EXPECT_NE(vec2(), vec2(0, 1));
}

TEST(vec2_Testes, vec2_Operação) {
    vec2 t = vec2();
    vec2 u = vec2(3, 4);
    vec2 v = vec2(10, 20);
    vec2 w = vec2(100, 0);

    t += v;
    EXPECT_EQ(t[0], 10);
    EXPECT_EQ(t[1], 20);

    t *= 5;
    EXPECT_EQ(t[0], 50);
    EXPECT_EQ(t[1], 100);

    t /= 10;
    EXPECT_EQ(t[0], 5);
    EXPECT_EQ(t[1], 10);

    EXPECT_EQ((u + v)[0], 13);
    EXPECT_EQ((u + v)[1], 24);
    EXPECT_EQ((v - u)[0], 7);
    EXPECT_EQ((v - u)[1], 16);
    EXPECT_EQ((u * v)[0], 30);
    EXPECT_EQ((u * v)[1], 80);
    EXPECT_EQ((v / 10)[1], 2);
}


TEST(vec2_Testes, vec2_Função) {
    vec2 u = vec2(3, 4);
    vec2 v = vec2(10, 20);
    vec2 w = vec2(100, 0);

    EXPECT_EQ(dot(u, v), 110);
    EXPECT_EQ(unit_vector(w), vec2(1, 0));
    EXPECT_EQ(unit_vector(vec2()), vec2());

}