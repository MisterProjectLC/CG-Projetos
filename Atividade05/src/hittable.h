#ifndef HITTABLE_H
#define HITTABLE_H

#include "Atividade03/src/ray.h"
#include "Atividade02/src/interval.h"
#include "material.h"

class Material;

class HitRecord {
public:
    point3 p;
    vec3 normal;
    shared_ptr<Material> mat;
    double t;
    bool front_face;


    /// Configura o valor de t do registro.
    /// @param r Raio a ser registrado.
    /// @param ray_t t do registro, ou seja, a extensão de raio na intersecção.
    void set_t(const Ray& r, double ray_t) {
        t = ray_t;
        p = r.at(t);
    }

    /// Configura o valor de normal do registro.
    /// @param r Raio a ser registrado.
    /// @param outward_normal Normal extrudente do objeto acertado. Assume-se que seu tamanho é unitário.
    void set_face_normal(const Ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class Hittable {
public:
    virtual ~Hittable() = default;

    /// Retorna se dado raio acertou este objeto.
    /// @param ray Raio a ser testado.
    /// @param ray_t Intervalo de distância na qual o raio pode ser detectado.
    /// @param rec Valor de retorno com informações sobre o acerto.
    /// @returns Se o raio acertou a face. 
    virtual bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const = 0;
};

#endif