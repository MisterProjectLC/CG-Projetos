#ifndef INTERVAL_H
#define INTERVAL_H

#include "global.h"

class Interval {
public:
    double min, max;

    /// Construtor para um intervalo infinito.
    Interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    /// Construtor para um intervalo com limites definidos.
    Interval(double _min, double _max) : min(_min), max(_max) {}


    /// Retorna se um valor é contido pelo intervalo.
    /// @param x Valor a ser testado.
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /// Retorna se um valor é contido pelo intervalo (não-inclusivo).
    /// @param x Valor a ser testado.
    bool surrounds(double x) const {
        return min < x&& x < max;
    }

    /// Limita um valor para dentro do intervalo.
    /// @param x Valor a ser limitado.
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const Interval empty, universe;
};

const static Interval empty(+infinity, -infinity);
const static Interval universe(-infinity, +infinity);

#endif