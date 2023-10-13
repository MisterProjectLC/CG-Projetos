#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec2 {
public:
    /// O vetor em si.
    double e[2];

    /// Construtor simples.
    vec2() : e{ 0,0 } {}

    /// Construtor que popula o vetor imediatamente.
    /// @param e0 Primeiro valor.
    /// @param e1 Segundo valor.
    vec2(double e0, double e1) : e{ e0, e1 } {}

    /// Retorna a primeira coordenada do vetor.
    double x() const { return e[0]; }
    /// Retorna a segunda coordenada do vetor.
    double y() const { return e[1]; }

    /// Retorna o vetor negativo.
    vec2 operator-() const { return vec2(-e[0], -e[1]); }
    /// Retorna um valor específico do vetor.
    /// NÃO checa se o valor está dentro dos limites.
    double operator[](int i) const { return e[i]; }
    /// Retorna um valor específico do vetor.
    /// NÃO checa se o valor está dentro dos limites.
    double& operator[](int i) { return e[i]; }

    /// Soma com outro vetor.
    vec2& operator+=(const vec2& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    /// Multiplicação dos elementos do vetor com um valor específico.
    vec2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    /// Divisão dos elementos do vetor com um valor específico.
    vec2& operator/=(double t) {
        return *this *= 1 / t;
    }

    /// Retorna o comprimento do vetor.
    double length() const {
        return sqrt(length_squared());
    }

    /// Retorna o comprimento do vetor, elevado ao quadrado.
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1];
    }
};

// point2 is just an alias for vec2, but useful for geometric clarity in the code.
using point2 = vec2;


// Vector Utility Functions

/// Impressão do conteúdo do vetor.
inline std::ostream& operator<<(std::ostream& out, const vec2& v) {
    return out << v.e[0] << ' ' << v.e[1];
}

/// Soma de dois vetores.
inline vec2 operator+(const vec2& u, const vec2& v) {
    return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
}

/// Subtração de dois vetores.
inline vec2 operator-(const vec2& u, const vec2& v) {
    return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
}

/// Multiplicação de dois vetores.
inline vec2 operator*(const vec2& u, const vec2& v) {
    return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
}

/// Multiplicação de dois vetores.
inline vec2 operator*(double t, const vec2& v) {
    return vec2(t * v.e[0], t * v.e[1]);
}

/// Multiplicação de um valor com um vetor.
inline vec2 operator*(const vec2& v, double t) {
    return t * v;
}

/// Divisão de um vetor com um valor.
inline vec2 operator/(vec2 v, double t) {
    return (1 / t) * v;
}

/// Retorna a multiplicação escalar entre dois vetores.
inline double dot(const vec2& u, const vec2& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1];
}

/// Retorna o vetor, com comprimento 1.
inline vec2 unit_vector(vec2 v) {
    return v / v.length();
}

#endif