#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>
#include "vec2.h"

using std::sqrt;

class mat2 {
public:
    /// A matriz em si.
    double e[2][2];

    /// Construtor simples.
    mat2() : e{ {0,0}, {0,0} } {}

    /// Construtor que popula a matriz imediatamente.
    /// @param e0 Valor no índice 0,0.
    /// @param e1 Valor no índice 0,1.
    /// @param f0 Valor no índice 1,0.
    /// @param f1 Valor no índice 1,1.
    mat2(double e0, double e1, double f0, double f1) : e{ {e0, e1}, {f0, f1} } {}

    /// Retorna a matriz negativa.
    mat2 operator-() const { return mat2(-e[0][0], -e[0][1], -e[1][0], -e[1][1]); }
    /// Retorna um vetor da linha especificada.
    /// NÃO checa se o valor está dentro dos limites.
    vec2 operator[](int i) const { return vec2(e[i][0], e[i][1]); }

    /// Soma com outra matriz.
    mat2& operator+=(const mat2& v) {
        e[0][0] += v.e[0][0];
        e[0][1] += v.e[0][1];
        e[1][0] += v.e[1][0];
        e[1][1] += v.e[1][1];
        return *this;
    }

    /// Multiplicação dos elementos do vetor com um valor específico.
    mat2& operator*=(double t) {
        e[0][0] *= t;
        e[0][1] *= t;
        e[1][0] *= t;
        e[1][1] *= t;
        return *this;
    }

    /// Divisão dos elementos do vetor com um valor específico.
    mat2& operator/=(double t) {
        return *this *= 1 / t;
    }
};

// Matrix Utility Functions

inline std::ostream& operator<<(std::ostream& out, const mat2& v) {
    return out << v.e[0][0] << ' ' << v.e[0][1] << ' ' << v.e[1][0] << ' ' << v.e[1][1];
}

inline mat2 operator+(const mat2& u, const mat2& v) {
    return mat2(u.e[0][0] + v.e[0][0], u.e[0][1] + v.e[0][1], u.e[1][0] + v.e[1][0], u.e[1][1] + v.e[1][1]);
}

inline mat2 operator-(const mat2& u, const mat2& v) {
    return mat2(u.e[0][0] - v.e[0][0], u.e[0][1] - v.e[0][1], u.e[1][0] - v.e[1][0], u.e[1][1] - v.e[1][1]);
}

inline mat2 operator*(const mat2& u, const mat2& v) {
    return mat2(u.e[0][0] * v.e[0][0], u.e[0][1] * v.e[0][1], u.e[1][0] * v.e[1][0], u.e[1][1] * v.e[1][1]);
}

inline mat2 operator*(double t, const mat2& v) {
    return mat2(t * v.e[0][0], t * v.e[0][1], t * v.e[1][0], t * v.e[1][1]);
}

inline mat2 operator*(const mat2& v, double t) {
    return t * v;
}

inline mat2 operator/(mat2 v, double t) {
    return (1 / t) * v;
}

inline double dot_h(const mat2& u, const mat2& v, int i, int j) {
    return u.e[i][0] * v.e[0][j] + u.e[i][1] * v.e[1][j];
}

inline mat2 dot(const mat2& u, const mat2& v) {
    return mat2(dot_h(u, v, 0, 0), dot_h(u, v, 0, 1), dot_h(u, v, 1, 0), dot_h(u, v, 1, 1));
}

#endif