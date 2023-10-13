#include <catch.hpp>
#include "../src/vec2.h"

TEST_CASE("Vec2 Tests") {
    vec2 t = vec2();
    vec2 u = vec2(3, 4);
    vec2 v = vec2(10, 20);
    vec2 w = vec2(100, 0);

    REQUIRE(t.e[0] == 0);
    REQUIRE(t.e[1] == 0);
    REQUIRE(t[0] == 0);
    REQUIRE(t[1] == 0);
    REQUIRE(u.length() == 5);

    t += u;
    REQUIRE(t[0] == 10);
    REQUIRE(t[1] == 20);

    t *= 5;
    REQUIRE(t[0] == 50);
    REQUIRE(t[1] == 100);

    t /= 10;
    REQUIRE(t[0] == 5);
    REQUIRE(t[1] == 10);

    REQUIRE((u + v)[0] == 13);
    REQUIRE((u + v)[1] == 24);
    REQUIRE((v - u)[0] == 7);
    REQUIRE((v - u)[0] == 16);
    REQUIRE((u * v)[0] == 30);
    REQUIRE((u * v)[1] == 80);
    REQUIRE((v / 10)[1] == 2);

    REQUIRE(dot(u, v) == 110);
    REQUIRE(unit_vector(w)[0] == 1);
}
