//
// Created by Polina on 24.10.2022.
//

#ifndef MATRIX_CALCULATOR_VECTOR_H
#define MATRIX_CALCULATOR_VECTOR_H

#include <iostream>

class Vector {
    friend Vector operator - (const Vector& v);
    friend std::ostream& operator << (std::ostream& s, const Vector& r);
    friend Vector operator + (const Vector& v, const float& f);
    friend Vector operator + (const float& f, const Vector& v);
    friend Vector operator + (const Vector& v1, const Vector& v2);
    friend Vector operator - (const Vector& v, const float& f);
private:
    float* array;
    size_t N;
    bool c;
public:
    Vector();
    Vector(size_t _n, bool _c);
    Vector(const float* _array, size_t _N, bool _c);
    ~Vector();

    float* get_array();
    size_t get_size() const;
    bool get_C() const;
    Vector& operator = (const float* mas);
    float& operator [] (size_t n) const;
};


#endif //MATRIX_CALCULATOR_VECTOR_H
