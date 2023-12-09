#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public Hittable {
public:
    std::vector<shared_ptr<Hittable>> objects;

    /// Construtor padrão.
    HittableList() {}
    /// Construtor já com .
    HittableList(shared_ptr<Hittable> object) { add(object); }

    /// Removes all objects from the object list.
    void clear() { objects.clear(); }

    /// Add a new object to the list.
    /// @param object Object to be added.
    void add(shared_ptr<Hittable> object) {
        objects.push_back(object);
    }

    /// Retorna se dado raio acertou algum destes objetos.
    /// @param ray Raio a ser testado.
    /// @param ray_t Intervalo de distância na qual o raio pode ser detectado.
    /// @param rec Valor de retorno com informações sobre o acerto.
    /// @returns Se o raio acertou. 
    bool hit(const Ray& r, Interval ray_t, HitRecord& rec) const override {
        HitRecord temp_rec;
        bool hit_anything = false;

        for (const auto& object : objects) {
            if (object->hit(r, ray_t, temp_rec)) {
                hit_anything = true;
                ray_t.max = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif

