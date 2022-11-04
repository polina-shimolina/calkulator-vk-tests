//
// Created by Polina on 24.10.2022.
//

#ifndef MATRIX_CALCULATOR_MATRIX_H
#define MATRIX_CALCULATOR_MATRIX_H
#include <ostream>
#include "vector.h"

class matrix {
    friend matrix operator - (const matrix&);
    friend matrix operator + (const matrix&, const matrix&);
    friend matrix operator * (const matrix&, const matrix&);
    friend matrix operator * (const matrix&, const float&);
    friend matrix operator * (const float&, const matrix&);
    friend matrix operator - (const matrix&, const matrix&);
    friend std::ostream& operator << (std::ostream&, const matrix&);
    friend matrix operator * (const matrix&, const vector&);
    friend matrix operator * (const vector&, const matrix&);
    friend matrix operator + (const matrix&, const float&);
    friend matrix operator + (const float&, const matrix&);
    friend matrix operator + (const matrix&, const vector&);
    friend matrix operator + (const vector&, const matrix&);
    friend matrix operator - (const matrix&, const vector&);
    friend matrix operator + (const float&, const matrix&);
    friend matrix operator + (const matrix&, const float&);
    friend matrix operator - (const matrix&, const float&);

private:
    int M, N;
    float** array;
public:
    matrix();
    matrix(int, int);
    matrix(float**, int, int);
    matrix(vector*, int number);
    matrix(vector);
    ~matrix();
    //matrix(float*, int); //--

    int get_M();
    int get_N();
    matrix element_multiply(matrix, matrix);

    float** get_array();
    //float get_element(int, int);
    float* get_diagonal(int);
    float* get_line(int);
    float* get_column(int);
    matrix get_transposed();
    float get_det();
    void set_line(float*, int);
    void set_column(float*, int);

    matrix inversion();

    double operator()(int index, int index2);
};


#endif //MATRIX_CALCULATOR_MATRIX_H
