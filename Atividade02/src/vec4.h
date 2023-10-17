#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec4 {
public:
    /// O vetor em si.
    double e[4];

    /// Construtor simples.
    vec4() : e{ 0,0,0,0 } {}
    /// Construtor que popula o vetor imediatamente.
    /// @param e0 Primeiro valor.
    /// @param e1 Segundo valor.
    /// @param e2 Terceiro valor.
    /// @param e3 Quarto valor.
    vec4(double e0, double e1, double e2, double e3) : e{ e0, e1, e2, e3 } {}

    /// Retorna a primeira coordenada do vetor.
    double x() const { return e[0]; }
    /// Retorna a segunda coordenada do vetor.
    double y() const { return e[1]; }
    /// Retorna a terceira coordenada do vetor.
    double z() const { return e[2]; }
    /// Retorna a quarta coordenada do vetor.
    double w() const { return e[3]; }

    /// Retorna o vetor negativo.
    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }
    /// Retorna um valor específico do vetor.
    /// NÃO checa se o valor está dentro dos limites.
    double operator[](int i) const { return e[i]; }
    /// Retorna um valor específico do vetor.
    /// NÃO checa se o valor está dentro dos limites.
    double& operator[](int i) { return e[i]; }

    /// Soma com outro vetor.
    vec4& operator+=(const vec4& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    /// Multiplicação dos elementos do vetor com um valor específico.
    vec4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    /// Divisão dos elementos do vetor com um valor específico.
    vec4& operator/=(double t) {
        return *this *= 1 / t;
    }

    /// Retorna o comprimento do vetor.
    double length() const {
        return sqrt(length_squared());
    }

    /// Retorna o comprimento do vetor, elevado ao quadrado.
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
    }
};


// Vector Utility Functions

/// Impressão do conteúdo do vetor.
inline std::ostream& operator<<(std::ostream& out, const vec4& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

/// Soma de dois vetores.
inline vec4 operator+(const vec4& u, const vec4& v) {
    return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
}

/// Subtração de dois vetores.
inline vec4 operator-(const vec4& u, const vec4& v) {
    return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
}

/// Multiplicação de dois vetores.
inline vec4 operator*(const vec4& u, const vec4& v) {
    return vec4(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
}

/// Multiplicação de um valor com um vetor.
inline vec4 operator*(double t, const vec4& v) {
    return vec4(t * v.e[0], t * v.e[1], t * v.e[2], t * v.e[3]);
}

/// Multiplicação de um valor com um vetor.
inline vec4 operator*(const vec4& v, double t) {
    return t * v;
}

/// Divisão de um vetor com um valor.
inline vec4 operator/(vec4 v, double t) {
    return (1 / t) * v;
}

inline bool operator==(const vec4& v1, const vec4& v2)
{
    return (v1.e[0] == v2.e[0] && v1.e[1] == v2.e[1] && v1.e[2] == v2.e[2] && v1.e[3] == v2.e[3]);
}

inline bool operator!=(const vec4& v1, const vec4& v2)
{
    return !(v1 == v2);
}

/// Retorna a multiplicação escalar entre dois vetores.
inline double dot(const vec4& u, const vec4& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2]
        + u.e[3] * v.e[3];
}

/// Retorna o vetor, com comprimento 1.
inline vec4 unit_vector(vec4 v) {
    double len = v.length();
    if (len == 0)
        return vec4();
    return v / v.length();
}

#endif