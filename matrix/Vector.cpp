//
// Created by Polina on 24.10.2022.
//

#include "vector.h"
#include <iostream>

#include "Vector.h"

Vector::Vector() :N(0), c(false), array(nullptr) {}

Vector::Vector(const float* _array, size_t _N, bool _c) {
    N = _N;
    c = _c;
    array = new float[N];
    for (int i = 0; i < N; i++) {
        array[i] = _array[i];
    }
}

Vector::Vector(size_t _n, bool _c) {
    N = _n, c = _c;
    array = new float[N];
}

Vector::~Vector() {
    delete[] array;
}

float* Vector::get_array() {
    float* temp = new float[N];
    for (int i = 0; i < N; i++) {
        temp[i] = array[i];
    }
    return temp;
}


bool Vector::get_C() const {
    return c;
}

std::ostream& operator << (std::ostream& s, const Vector& v) {
    for (int i = 0; i < v.N; i++)
        s << v.array[i] << " ";
    return s;
}

size_t Vector::get_size() const {
    return N;
}

Vector& Vector::operator = (const float* mas) {
    int l = sizeof(mas) / sizeof(mas[0]);
    this->array = new float[l];
    for (int i = 0; i < l; i++) {
        this->array[i] = mas[i];
    }
    this->N = l;
    this->c = true;
    return *this;
}

float& Vector::operator[](size_t n) const {
    return array[n];
}

Vector operator + (const Vector& v, const float& f) {
    Vector res(v.N, v.c);
    for (int i = 0; i < v.N; i++) {
        res.array[i] = v.array[i] + f;
    }
    return res;
}

Vector operator + (const float& f, const Vector& v) {
    return v + f;
}

Vector operator + (const Vector& v1, const Vector& v2) {
    if (v1.c == v2.c && v1.N == v2.N) {
            Vector res(v1.N, v1.c);
            for (int i = 0; i < v1.N; i++) {
                res.array[i] = v1.array[i] + v2.array[i];
            }
            return res;
    }
    throw "Unable to sum vectors!";
}

Vector operator - (const Vector& v, const float& f) {
    return v + (-f);
}

Vector operator - (const Vector& v) {
    for (int i = 0; i < v.N; i++) {
        v.array[i] = -v.array[i];
    }
    return v;
}

Vector& operator+=(Vector& v1, const Vector& v2) {
    return v1 = v1 + v2;
}
