//
// Created by Polina on 24.10.2022.
//

#include "matrix.h"
#include <iostream>
#include <math.h>

matrix::matrix() {
    N = 0, M = 0;
    array = nullptr;
}

matrix::matrix(int _m, int _n) {
    N = _n, M = _m;
    array = new float* [M];
    for (int i = 0; i < M; i++)
        array[i] = new float[N];
}

matrix::matrix(float** values, int _m, int _n) {
    N = _n, M = _m;
    array = new float * [M];
    for (int i = 0; i < M; i++)
        array[i] = new float[N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            array[i][j] = values[i][j];
}


matrix::matrix(vector* v, int number) {
    M = 0, N = 0, array = nullptr;
    int size = v[0].get_size();
    int _c = v[0].get_C();
    bool check_c = true;
    for (int i = 0; i < number; i++) {
        if (v[i].get_C() != _c)
            check_c = !check_c;
    }
    if (check_c) {
        M = number;
        N = size;
        for (int i = 0; i < M; i++) {
            if (v[i].get_size() < size) {
                size = v[i].get_size();
            }
        }
        if (_c) {
            M = number;
            N = size;
            array = new float* [M];
            for (int i = 0; i < M; i++)
                array[i] = new float[N];

            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    array[i][j] = v[i][j];
        }
        else {
            N = number;
            M = size;
            array = new float* [M];
            for (int i = 0; i < M; i++)
                array[i] = new float[N];

            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    array[j][i] = v[i][j];

        }


    }

}

matrix::matrix (vector v) {
    if (v.get_C()) {
        N = v.get_N();
        M = 1;
        for (int i = 0; i < N; i++) array[0][i] = v[i];
    }
    else {
        N = 1;
        M = v.get_N();
        for (int i = 0; i < N; i++) array[i][0] = v[i];
    }
}


matrix::~matrix() {
    for (int i = 0; i < M; i++)
        delete[] array[i];
    delete[] array;
}

int matrix::get_M() {
    return M;
}

int matrix::get_N() {
    return N;
}

float matrix::get_det()
{
    matrix m(array, M, N);
    float tmp;
    for (int k = 0; k < N - 1; k++) {
        for (int i = k + 1; i < N; i++) {
            tmp = -m.array[i][k] / m.array[k][k];
            for (int j = 0; j < N; j++) {
                m.array[i][j] += m.array[k][j] * tmp;
            }
        }
    }
    std::cout << std::endl << m << std::endl;
    float d = 1;
    for (int i = 0; i < N; i++) {
        d *= m.array[i][i];
    }
    return d;
}

int Gauss(double** matrica_a, int n, double* massiv_b, double* x)
{
    int i, j, k, r;
    double c, M, max, s, ** a, * b; a = new double* [n];
    for (i = 0; i < n; i++) a[i] = new double[n];
    b = new double[n]; for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) a[i][j] = matrica_a[i][j];
    for (i = 0; i < n; i++) b[i] = massiv_b[i];
    for (k = 0; k < n; k++) {
        max = fabs(a[k][k]);
        r = k;
        for (i = k + 1; i < n; i++)
            if (fabs(a[i][k]) > max) {
                max = fabs(a[i][k]);
                r = i;
            }
        for (j = 0; j < n; j++) {
            c = a[k][j];
            a[k][j] = a[r][j];
            a[r][j] = c;
        }
        c = b[k]; b[k] = b[r]; b[r] = c; for (i = k + 1; i < n; i++) {
            for (M = a[i][k] / a[k][k], j = k; j < n; j++)
                a[i][j] -= M * a[k][j]; b[i] -= M * b[k];
        }

    }
    if (a[n - 1][n - 1] == 0) if (b[n - 1] == 0)return-1; else return-2;
    else {
        for (i = n - 1; i >= 0; i--) {
            for (s = 0, j = i + 1; j < n; j++)
                s += a[i][j] * x[j]; x[i] = (b[i] - s) / a[i][i];
        }return 0;
    } for (i = 0; i < n; i++) delete[] a[i]; delete[] a;
    delete[] b;

}



matrix matrix::element_multiply(matrix matrix1, matrix matrix2)
{
    matrix res;
    if (matrix1.N == matrix2.N && matrix1.M == matrix2.M) {
        int n = matrix1.N, m = matrix1.M;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.array[i][j] = matrix1.array[i][j] * matrix2.array[i][j];
            }
        }
    }
    return res;
}

float** matrix::get_array() {
    return array;
}

//float matrix::get_element(int i, int j)
//{
//	return array[i][j];
//}

float* matrix::get_diagonal(int type)
{
    float* temp = new float;
    if (N == M)
        if (type) {
            for (int i = 0; i < N; i++)
                temp[i] = array[i][i];
        }
        else {
            for (int i = 0; i < N; ++i)
            {
                temp[i] = array[i][N - i - 1];
            }
        }
    else return nullptr;
    return temp;
}

float* matrix::get_column(int num) //M*N - ������*�������
{
    float* temp = new float;
    for (int i = 0; i < M; i++) {
        temp[i] = array[i][num];
    }

    return temp;
}

float* matrix::get_line(int num)
{
    float* temp = new float;
    for (int i = 0; i < N; i++)
        temp[i] = array[num][i];
    return temp;
}

matrix matrix::get_transposed()
{
    matrix transposed(N, M);
    for (int i = 0; i < M; i++) {
        transposed.set_column(get_line(i), i);
    }
    return transposed;
}

void matrix::set_line(float* temp_array, int num)
{
    for (int i = 0; i < N; i++) {
        array[num][i] = temp_array[i];
    }
}

void matrix::set_column(float* temp_array, int num)
{
    for (int i = 0; i < M; i++) {
        array[i][num] = temp_array[i];
    }

}

double matrix::operator()(int index1, int index2)
{
    return array[index1][index2];
}

matrix operator-(const matrix& matrix)
{
    for (int i = 0; i < matrix.M; i++) {
        for (int j = 0; j < matrix.N; j++) {
            matrix.array[i][j] = -matrix.array[i][j];
        }
    }
    return matrix;

}

matrix operator+(const matrix& matrix1, const matrix& matrix2)
{
    matrix res;
    if (matrix1.N == matrix2.N && matrix1.M == matrix2.M) {
        int n = matrix1.N, m = matrix1.M;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.array[i][j] = matrix1.array[i][j] + matrix2.array[i][j];
            }
        }
    }
    return res;
}

matrix operator*(const matrix& matrix1, const matrix& matrix2)
{
    matrix res(matrix1.M, matrix2.N);
    int M = matrix1.M;
    int N = matrix1.N;

    if (matrix1.N == matrix2.M) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                res.array[i][j] = 0;
                for (int k = 0; k < N; k++)
                    res.array[i][j] += matrix1.array[i][k] * matrix2.array[k][j];
            }
        }
    }
    return res;
}

matrix operator*(const matrix& m, const float& value)
{
    matrix res(m.M, m.N);
    int M = m.M;
    int N = m.N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            res.array[i][j] = m.array[i][j] * value;
        }
    }
    return res;
}

matrix operator*(const float& value, const matrix& matrix)
{
    return matrix * value;
}

matrix operator-(const matrix& matrix1, const matrix& matrix2)
{
    return matrix1 + (-matrix2);
}


std::ostream& operator << (std::ostream& s, const matrix& m)
{
    for (int i = 0; i < m.M; i++) {
        for (int j = 0; j < m.N; j++)
            s << m.array[i][j] << " ";
        s << std::endl;
    }

    return s;
}

matrix operator*(const matrix& m, const vector& v)
{
    matrix vec(v);
    return m*vec;
}

matrix operator*(const vector& v, const matrix& m)
{
    matrix vec(v);
    return vec*m;
}

matrix operator + (const matrix& m, const float& f) {
    for (int i = 0; i < m.M; i++)
        for (int j = 0; j < m.N; j++)
            m.array[i][j] += f;
    return m;
}

matrix operator + (const float& f, const matrix& m) {
    return m + f;
}

matrix operator + (const matrix& m, const vector& v) {
    matrix vec(v);
    return m + vec;
}
matrix operator + (const vector& v, const matrix& m) {
    matrix vec(v);
    return m + vec;
}
matrix operator - (const matrix& m, const vector& v) {
    matrix vec(v);
    return m + (-vec);
}
//matrix operator + (const float& f, const matrix& m) {
//	matrix res(m.M, m.N);
//	for (int i = 0; i < m.M; i++)
//		for (int j = 0; j < m.N; j++)
//			res.array[i][j] = m.array[i][j] + f;
//	return res;
//}
//matrix operator + (const matrix& m, const float& f) {
//	return f + m;
//}
matrix operator - (const matrix& m, const float& f) {
    return m + (-f);
}

matrix matrix::inversion()
{
    double temp;
    float** A = new float* [N];
    for (int i = 0; i < N; i++)
        A[i] = new float[N];

    A = array;

    float** E = new float* [N];
    for (int i = 0; i < N; i++)
        E[i] = new float[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            E[i][j] = 0.0;

            if (i == j)
                E[i][j] = 1.0;
        }

    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];

    for (int i = 0; i < N; i++)
        delete[] E[i];
    delete[] E;
    return matrix(A, N, N);
}
