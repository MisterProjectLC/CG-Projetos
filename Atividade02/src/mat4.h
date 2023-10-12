#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>
#include <string>
#include "vec4.h"

using std::sqrt;

class mat4 {
public:
    double e[4][4];

    mat4() : e{ {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} } {}
    mat4(double e0, double e1, double e2, double e3,
        double f0, double f1, double f2, double f3,
        double g0, double g1, double g2, double g3,
        double h0, double h1, double h2, double h3) :
            e{ {e0, e1, e2, e3}, {f0, f1, f2, f3}, {g0, g1, g2, g3}, {h0, h1, h2, h3} } {}

    mat4 operator-() const {
        return mat4(-e[0][0], -e[0][1], -e[0][2], -e[0][3],
            -e[1][0], -e[1][1], -e[1][2], -e[1][3],
            -e[2][0], -e[2][1], -e[2][2], -e[2][3],
            -e[3][0], -e[3][1], -e[3][2], -e[3][3]);
    }
    vec4 operator[](int i) const { return vec4(e[i][0], e[i][1], e[i][2], e[i][3]); }

    mat4& operator+=(const mat4& v) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                e[i][j] += v.e[i][j];
        return *this;
    }

    mat4& operator*=(double t) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                e[i][j] *= t;
        return *this;
    }

    mat4& operator/=(double t) {
        return *this *= 1 / t;
    }
};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream& out, const mat4& v) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            out << v.e[i][j] << ' ';
    return out;
}

inline mat4 operator+(const mat4& u, const mat4& v) {
    return mat4(u.e[0][0] + v.e[0][0], u.e[0][1] + v.e[0][1], u.e[0][2] + v.e[0][2], u.e[0][3] + v.e[0][3],
        u.e[1][0] + v.e[1][0], u.e[1][1] + v.e[1][1], u.e[1][2] + v.e[1][2], u.e[1][3] + v.e[1][3],
        u.e[2][0] + v.e[2][0], u.e[2][1] + v.e[2][1], u.e[2][2] + v.e[2][2], u.e[2][3] + v.e[2][3],
        u.e[3][0] + v.e[3][0], u.e[3][1] + v.e[3][1], u.e[3][2] + v.e[3][2], u.e[3][3] + v.e[3][3]);
}

inline mat4 operator-(const mat4& u, const mat4& v) {
    return mat4(u.e[0][0] - v.e[0][0], u.e[0][1] - v.e[0][1], u.e[0][2] - v.e[0][2], u.e[0][3] - v.e[0][3],
        u.e[1][0] - v.e[1][0], u.e[1][1] - v.e[1][1], u.e[1][2] - v.e[1][2], u.e[1][3] - v.e[1][3],
        u.e[2][0] - v.e[2][0], u.e[2][1] - v.e[2][1], u.e[2][2] - v.e[2][2], u.e[2][3] - v.e[2][3], 
        u.e[3][0] - v.e[3][0], u.e[3][1] - v.e[3][1], u.e[3][2] - v.e[3][2], u.e[3][3] - v.e[3][3]);
}

inline mat4 operator*(const mat4& u, const mat4& v) {
    return mat4(u.e[0][0] * v.e[0][0], u.e[0][1] * v.e[0][1], u.e[0][2] * v.e[0][2], u.e[0][3] * v.e[0][3],
        u.e[1][0] * v.e[1][0], u.e[1][1] * v.e[1][1], u.e[1][2] * v.e[1][2], u.e[1][3] * v.e[1][3],
        u.e[2][0] * v.e[2][0], u.e[2][1] * v.e[2][1], u.e[2][2] * v.e[2][2], u.e[2][3] * v.e[2][3],
        u.e[3][0] * v.e[3][0], u.e[3][1] * v.e[3][1], u.e[3][2] * v.e[3][2], u.e[3][3] * v.e[3][3]);
}

inline mat4 operator*(double t, const mat4& v) {
    return mat4(t * v.e[0][0], t * v.e[0][1], t * v.e[0][2], t * v.e[0][3],
        t * v.e[1][0], t * v.e[1][1], t * v.e[1][2], t * v.e[1][3],
        t * v.e[2][0], t * v.e[2][1], t * v.e[2][2], t * v.e[2][3],
        t * v.e[3][0], t * v.e[3][1], t * v.e[3][2], t * v.e[3][3]);
}

inline mat4 operator*(const mat4& v, double t) {
    return t * v;
}

inline mat4 operator/(mat4 v, double t) {
    return (1 / t) * v;
}

inline mat4 dot(const mat4& u, const mat4& v) {
    return mat4(dot_h(u, v, 0, 0), dot_h(u, v, 0, 1), dot_h(u, v, 0, 2), dot_h(u, v, 0, 3),
        dot_h(u, v, 1, 0), dot_h(u, v, 1, 1), dot_h(u, v, 1, 2), dot_h(u, v, 1, 3),
        dot_h(u, v, 2, 0), dot_h(u, v, 2, 1), dot_h(u, v, 2, 2), dot_h(u, v, 2, 3), 
        dot_h(u, v, 3, 0), dot_h(u, v, 3, 1), dot_h(u, v, 3, 2), dot_h(u, v, 3, 3));
}

inline double dot_h(const mat4& u, const mat4& v, int i, int j) {
    return u.e[i][0] * v.e[0][j] + u.e[i][1] * v.e[1][j] + u.e[i][2] * v.e[2][j] + u.e[i][3] * v.e[3][j];
}

#endif