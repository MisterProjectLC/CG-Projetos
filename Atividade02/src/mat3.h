#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>
#include <string>
#include "vec3.h"

using std::sqrt;

class mat3 {
public:
    /// A matriz em si.
    double e[3][3];

    /// Construtor simples.
    mat3() : e{ {0,0,0}, {0,0,0}, {0,0,0} } {}

    /// Construtor que popula a matriz imediatamente.
    /// @param e0 Valor no índice 0,0.
    /// @param e1 Valor no índice 0,1.
    /// @param e2 Valor no índice 0,2.
    /// @param f0 Valor no índice 1,0.
    /// @param f1 Valor no índice 1,1.
    /// @param f2 Valor no índice 1,2.
    /// @param g0 Valor no índice 2,0.
    /// @param g1 Valor no índice 2,1.
    /// @param g2 Valor no índice 2,2.
    mat3(double e0, double e1, double e2, 
        double f0, double f1, double f2,
        double g0, double g1, double g2) : e{ {e0, e1, e2}, {f0, f1, f2}, {g0, g1, g2} } {}

    /// Retorna a matriz negativa.
    mat3 operator-() const { return mat3(-e[0][0], -e[0][1], -e[0][2], 
        -e[1][0], -e[1][1], -e[1][2],
        -e[2][0], -e[2][1], -e[2][2]); }
    /// Retorna um vetor da linha especificada.
    /// NÃO checa se o valor está dentro dos limites.
    vec3 operator[](int i) const { return vec3(e[i][0], e[i][1], e[i][2]); }

    /// Soma com outra matriz.
    mat3& operator+=(const mat3& v) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                e[i][j] += v.e[i][j];
        return *this;
    }

    /// Multiplicação dos elementos do vetor com um valor específico.
    mat3& operator*=(double t) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                e[i][j] *= t;
        return *this;
    }

    /// Divisão dos elementos do vetor com um valor específico.
    mat3& operator/=(double t) {
        return *this *= 1 / t;
    }
};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream& out, const mat3& v) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            out << v.e[i][j] << ' ';
    return out;
}

inline mat3 operator+(const mat3& u, const mat3& v) {
    return mat3(u.e[0][0] + v.e[0][0], u.e[0][1] + v.e[0][1], u.e[0][2] + v.e[0][2],
        u.e[1][0] + v.e[1][0], u.e[1][1] + v.e[1][1], u.e[1][2] + v.e[1][2],
        u.e[2][0] + v.e[2][0], u.e[2][1] + v.e[2][1], u.e[2][2] + v.e[2][2]);
}

inline mat3 operator-(const mat3& u, const mat3& v) {
    return mat3(u.e[0][0] - v.e[0][0], u.e[0][1] - v.e[0][1], u.e[0][2] - v.e[0][2],
        u.e[1][0] - v.e[1][0], u.e[1][1] - v.e[1][1], u.e[1][2] - v.e[1][2],
        u.e[2][0] - v.e[2][0], u.e[2][1] - v.e[2][1], u.e[2][2] - v.e[2][2]);
}

inline mat3 operator*(const mat3& u, const mat3& v) {
    return mat3(u.e[0][0] * v.e[0][0], u.e[0][1] * v.e[0][1], u.e[0][2] * v.e[0][2],
        u.e[1][0] * v.e[1][0], u.e[1][1] * v.e[1][1], u.e[1][2] * v.e[1][2],
        u.e[2][0] * v.e[2][0], u.e[2][1] * v.e[2][1], u.e[2][2] * v.e[2][2]);
}

inline mat3 operator*(double t, const mat3& v) {
    return mat3(t * v.e[0][0], t * v.e[0][1], t * v.e[0][2],
        t * v.e[1][0], t * v.e[1][1], t * v.e[1][2],
        t * v.e[2][0], t * v.e[2][1], t * v.e[2][2]);
}

inline mat3 operator*(const mat3& v, double t) {
    return t * v;
}

inline mat3 operator/(mat3 v, double t) {
    return (1 / t) * v;
}

inline double dot_h(const mat3& u, const mat3& v, int i, int j) {
    return u.e[i][0] * v.e[0][j] + u.e[i][1] * v.e[1][j] + u.e[i][2] * v.e[2][j];
}

inline mat3 dot(const mat3& u, const mat3& v) {
    return mat3(dot_h(u, v, 0, 0), dot_h(u, v, 0, 1), dot_h(u, v, 0, 2),
        dot_h(u, v, 1, 0), dot_h(u, v, 1, 1), dot_h(u, v, 1, 2), 
        dot_h(u, v, 2, 0), dot_h(u, v, 2, 1), dot_h(u, v, 2, 2));
}

#endif