//
// Created by Polina on 24.10.2022.
//

#include "vector.h"
#include <iostream>

vector::vector() {
    N = 0; c = NULL; array = nullptr;
}

vector::vector(float* _array, int _N, int _c) {
    N = _N;
    c = _c;
    array = new float[N];
    for (int i = 0; i < N; i++) {
        array[i] = _array[i];
    }
}

vector::vector(int _n, int _c) {
    N = _n, c = _c;
    array = new float[N];
}

vector::~vector() {
    delete[] array;
}

float* vector::get_array() {
    float* temp = new float[N];
    for (int i = 0; i < N; i++) {
        temp[i] = array[i];
    }
    return temp;
}

int vector::get_N() {
    return N;
}

int vector::get_C()
{
    return c;
}
//
//float vector::get_element(int pos) {
//	return array[pos];
//}

std::ostream& operator << (std::ostream& s, const vector& v) {
    for (int i = 0; i < v.N; i++)
        s << v.array[i] << " ";
    return s;
}

int vector::get_size() {
    return N;
}

vector vector::operator = (float* mas)
{
    int l = sizeof(mas) / sizeof(mas[0]);
    this->array = new float[l];
    for (int i = 0; i < l; i++) {
        this->array[i] = mas[i];
    }
    this->N = l;
    this->c = 1;
    return vector(this->array, this->N, this->c);
}

float vector::operator[](int n)
{
    return array[n];
}

vector operator + (const vector& v, const float& f) {
    vector res(v.N, v.c);
    for (int i = 0; i < v.N; i++) {
        res.array[i] = v.array[i] + f;
    }
    return res;
}

vector operator + (const float& f, const vector& v) {
    return v + f;
}

vector operator + (const vector& v1, const vector& v2)
{
    vector res;
    if (v1.c == v2.c) {
        if (v1.N == v2.N) {
            vector res(v1.N, v1.c);
            for (int i = 0; i < v1.N; i++) {
                res.array[i] = v1.array[i] + v2.array[i];
            }
            return res;
        }
    }
    return vector(1, 1);

}

vector operator - (const vector& v, const float& f) {
    return v + (-f);
}

vector operator - (const vector& v) {
    for (int i = 0; i < v.N; i++) {
        v.array[i] = -v.array[i];
    }
    return v;
}
