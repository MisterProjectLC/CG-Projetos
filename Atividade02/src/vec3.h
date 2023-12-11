#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
#include <string>
#include "global.h"

using std::sqrt;
using namespace std;

/// Classe representando vetores de 3 dimensões. Obtida diretamente do tutorial de Raytracing.
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
    /// Retorna um valor específico do vetor.
    /// NÃO checa se o valor está dentro dos limites.
    double operator[](int i) const { return e[i]; }
    /// Retorna um valor específico do vetor.
    /// NÃO checa se o valor está dentro dos limites.
    double& operator[](int i) { return e[i]; }

    /// Soma com outro vetor.
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    /// Multiplicação dos elementos do vetor com um valor específico.
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    /// Divisão dos elementos do vetor com um valor específico.
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

    /// Retorna verdadeiro se o vetor estiver próximo de zero nas 3 dimensões.
    bool near_zero() const {
        // Return true if the vector is close to zero in all dimensions.
        auto s = 1e-8;
        return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
    }

    /// Retorna um vetor com valores completamente aleatorizados.
    static vec3 random() {
        return vec3(random_double(), random_double(), random_double());
    }

    /// Retorna um vetor com valores aleatorizados dentro de um intervalo.
    static vec3 random(double min, double max) {
        return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
    }

    /// Retorna uma versão impressa do vetor.
    string to_string() {
        return std::to_string(e[0]) + " " + std::to_string(e[1]) + " " + std::to_string(e[2]);
    }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;


// Vector Utility Functions

/// Impressão do conteúdo do vetor.
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

/// Soma de dois vetores.
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/// Soma de vetor com valor.
inline vec3 operator+(double t, const vec3& v) {
    return vec3(t + v.e[0], t + v.e[1], t + v.e[2]);
}

/// Soma de vetor com valor.
inline vec3 operator+(const vec3& v, double t) {
    return t + v;
}

/// Subtração de dois vetores.
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/// Multiplicação de dois vetores.
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/// Multiplicação de um valor com um vetor.
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

/// Multiplicação de um valor com um vetor.
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

/// Divisão de dois vetores.
inline vec3 operator/(const vec3& u, const vec3& v) {
    return vec3(u.e[0] / v.e[0], u.e[1] / v.e[1], u.e[2] / v.e[2]);
}

/// Divisão de um vetor com um valor.
inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}

inline bool operator==(const vec3& v1, const vec3& v2)
{
    return (v1.e[0] == v2.e[0] && v1.e[1] == v2.e[1] && v1.e[2] == v2.e[2]);
}

inline bool operator!=(const vec3& v1, const vec3& v2)
{
    return !(v1 == v2);
}


/// Retorna a multiplicação escalar entre dois vetores.
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

/// Retorna a multiplicação vetorial entre dois vetores.
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

/// Retorna o vetor, com comprimento 1.
inline vec3 unit_vector(vec3 v) {
    double len = v.length();
    if (len == 0)
        return vec3();
    return v / v.length();
}

inline vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1, 1);
        if (p.length_squared() < 1)
            return p;
    }
}

inline vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2 * dot(v, n) * n;
}

inline vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

#endif