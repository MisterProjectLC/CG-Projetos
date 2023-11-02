#ifndef RAY_H
#define RAY_H

#include "../../Atividade02/src/vec3.h"


class Ray {
private:
    point3 orig;
    vec3 dir;
public:
    /// Construtor base.
    Ray() {}

    /// Construtor de um Ray.
    /// @param origin Ponto de origem do raio.
    /// @param direction Vetor de direção do raio.
    Ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    /// Retorna o ponto de origem do raio.
    point3 origin() const { return orig; }
    /// Retorna o vetor de direção do raio.
    vec3 direction() const { return dir; }

    /// Retorna um ponto percorrido pelo raio.
    /// @param t Distância a se percorrer no raio.
    /// @returns Ponto encontrado.
    point3 at(double t) const {
        return orig + t * dir;
    }
};

#endif