#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

/// Classe representando vetores de 3 dimens�es. Obtida diretamente do tutorial de Raytracing.
/// https://raytracing.github.io/books/RayTracingInOneWeekend.html?authuser=1
class vec3 {
public:
    /// O vetor em si.
    double e[3];

    /// Construtor simples.
    vec3() : e{ 0,0,0 } {}

    /// Construtor que popula o vetor imediatamente.
    /// @param e0 Primeiro valor.
	/// @param e1 Segundo valor.
	/// @param e2 Terceiro valor.
    vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

    /// Retorna a primeira coordenada do vetor.
    double x() const { return e[0]; }
    /// Retorna a segunda coordenada do vetor.
    double y() const { return e[1]; }
    /// Retorna a terceira coordenada do vetor.
    double z() const { return e[2]; }

    /// Retorna o vetor negativo.
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    /// Retorna um valor espec�fico do vetor.
    /// N�O checa se o valor est� dentro dos limites.
    double operator[](int i) const { return e[i]; }
    /// Retorna um valor espec�fico do vetor.
    /// N�O checa se o valor est� dentro dos limites.
    double& operator[](int i) { return e[i]; }

    /// Soma com outro vetor.
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    /// Multiplica��o dos elementos do vetor com um valor espec�fico.
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    /// Divis�o dos elementos do vetor com um valor espec�fico.
    vec3& operator/=(double t) {
        return *this *= 1 / t;
    }

    /// Retorna o comprimento do vetor.
    double length() const {
        return sqrt(length_squared());
    }

    /// Retorna o comprimento do vetor, elevado ao quadrado.
    double length_squared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;


// Vector Utility Functions

/// Impress�o do conte�do do vetor.
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

/// Soma de dois vetores.
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/// Subtra��o de dois vetores.
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/// Multiplica��o de dois vetores.
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/// Multiplica��o de um valor com um vetor.
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

/// Multiplica��o de um valor com um vetor.
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

/// Divis�o de um vetor com um valor.
inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}

/// Retorna a multiplica��o escalar entre dois vetores.
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

/// Retorna a multiplica��o vetorial entre dois vetores.
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

/// Retorna o vetor, com comprimento 1.
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif