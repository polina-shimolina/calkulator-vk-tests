//
// Created by Polina on 24.10.2022.
//

#ifndef MATRIX_CALCULATOR_MATRIX_H
#define MATRIX_CALCULATOR_MATRIX_H

#include <iostream>
#include "Vector.h"

class Matrix {
    friend Matrix operator - (const Matrix& matrix);
    friend Matrix operator + (const Matrix& matrix1, const Matrix& matrix2);
    friend Matrix operator * (const Matrix& matrix1, const Matrix& matrix2);
    friend Matrix operator * (const Matrix& m, const float& value);
    friend Matrix operator * (const float& value, const Matrix& matrix);
    friend Matrix operator - (const Matrix& matrix1, const Matrix& matrix2);
    friend std::ostream& operator << (std::ostream& s, const Matrix& m);
    friend Matrix operator * (const Matrix& m, const Vector& v);
    friend Matrix operator * (const Vector& v, const Matrix& m);
    friend Matrix operator + (const Matrix& m, const float& f);
    friend Matrix operator + (const float& f, const Matrix& m);
    friend Matrix operator + (const Matrix& m, const Vector& v);
    friend Matrix operator + (const Vector& v, const Matrix& m);
    friend Matrix operator - (const Matrix& m, const Vector& v);
    friend Matrix operator - (const Matrix& m, const float& f);
private:
    size_t lines, columns;
    float** array{};
public:
    Matrix();
    Matrix(size_t _m, size_t _n);
    Matrix(float** values, size_t _m, size_t _n);
    Matrix(Vector* v, size_t number);
    Matrix(Vector v);
    ~Matrix();
    size_t get_lines() const;
    size_t get_columns() const;
    Matrix element_multiply(const Matrix& matrix1, const Matrix& matrix2);

    float** get_array();
    float* get_diagonal(int type);
    float* get_line(int num);
    float* get_column(int num);
    Matrix get_transposed();
    float get_det();
    void set_line(const float* temp_array, int num);
    void set_column(const float* temp_array, int num);

    Matrix inversion();

    float& operator()(int index, int index2);
};


#endif //MATRIX_CALCULATOR_MATRIX_H
