#ifndef MATERIAL_H
#define MATERIAL_H

#include "Atividade02/src/global.h"
#include "Atividade02/src/color.h"
#include "Atividade03/src/ray.h"
#include "hittable.h"

class HitRecord;


class Material {
public:
    virtual ~Material() = default;

    /// M�todo de espalhamento deste material.
    /// @param r_in Raio de entrada.
    /// @param rec Refer�ncia para registro de acerto para informa��es.
    /// @param attenuation Cor da superf�cie.
    /// @param scattered Cor da superf�cie.
    /// @returns Se o raio foi espalhado.
    virtual bool scatter(
        const Ray& r_in, const HitRecord& rec, color& attenuation, Ray& scattered) const = 0;
};


class Lambertian : public Material {
public:
    /// Construtor de um material opaco.
    /// @param a Cor do material.
    Lambertian(const color& a) : albedo(a) {}

    /// M�todo de espalhamento deste material.
    /// @param r_in Raio de entrada.
    /// @param rec Refer�ncia para registro de acerto para informa��es.
    /// @param attenuation Cor da superf�cie.
    /// @param scattered Cor da superf�cie.
    bool scatter(const Ray& r_in, const HitRecord& rec, color& attenuation, Ray& scattered)
        const override;

private:
    color albedo;
};


class Metal : public Material {
public:
    /// Construtor de um material met�lico.
    /// @param a Cor do material.
    /// @param f N�vel de emba�amento do material, de 0 a 1.
    Metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    /// M�todo de espalhamento deste material.
    /// @param r_in Raio de entrada.
    /// @param rec Refer�ncia para registro de acerto para informa��es.
    /// @param attenuation Cor da superf�cie.
    /// @param scattered Cor da superf�cie.
    bool scatter(const Ray& r_in, const HitRecord& rec, color& attenuation, Ray& scattered)
        const override;

private:
    color albedo;
    double fuzz;
};


class Dielectric : public Material {
public:
    /// Construtor de um material de vidro.
    /// @param index_of_refraction N�vel de refra��o do material, de 0 a 1.
    Dielectric(double index_of_refraction) : ir(index_of_refraction) {}

    /// M�todo de espalhamento deste material.
    /// @param r_in Raio de entrada.
    /// @param rec Refer�ncia para registro de acerto para informa��es.
    /// @param attenuation Cor da superf�cie.
    /// @param scattered Cor da superf�cie.
    bool scatter(const Ray& r_in, const HitRecord& rec, color& attenuation, Ray& scattered)
        const override;

private:
    double ir; // Index of Refraction

    /// Fun��o de aproxima��o polinomial por Christophe Schlick.
    /// @param cosine Cosseno de theta.
    /// @param ref_idx �ndice de refra��o do material.
    /// @returns Valor de reflect�ncia.
    static double reflectance(double cosine, double ref_idx) {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0 * r0;
        return r0 + (1 - r0) * pow((1 - cosine), 5);
    }
};

#endif