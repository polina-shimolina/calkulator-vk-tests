//
// Created by Polina on 24.10.2022.
//

#include "Matrix.h"

void allocate_mem(float** array, size_t lines, size_t columns){
    array = new float* [lines];
    for (int i = 0; i < lines; i++)
        array[i] = new float[columns];
}

Matrix::Matrix(): columns(0), lines(0), array(nullptr) {}

Matrix::Matrix(size_t _m, size_t _n) {
    columns = _n, lines = _m;
    allocate_mem(array, lines, columns);
}

Matrix::Matrix(float** values, size_t _m, size_t _n) {
    columns = _n, lines = _m;
    allocate_mem(array, lines, columns);
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            array[i][j] = values[i][j];
}

Matrix::Matrix(Vector* v, size_t number) {
    lines = 0, columns = 0, array = nullptr;
    size_t size = v[0].get_size();
    int _c = v[0].get_C();
    bool check_c = true;
    for (int i = 1; i < number; i++)
        if (v[i].get_C() != _c)
            check_c = false;

    bool check_size = true;
    for(int i = 1; i < number; i++)
        if(v[i].operator[](i)!=size)
            check_size = false;

    if (check_c && check_size) {
        lines = number;
        columns = size;
        for (int i = 0; i < lines; i++)
            if (v[i].get_size() < size)
                size = v[i].get_size();

        if (_c) {
            lines = number;
            columns = size;
            allocate_mem(array, lines, columns);
            for (int i = 0; i < lines; i++)
                for (int j = 0; j < columns; j++)
                    array[i][j] = v[i][j];
        }
        else {
            columns = number;
            lines = size;
            array = new float* [lines];
            for (int i = 0; i < lines; i++)
                array[i] = new float[columns];

            for (int i = 0; i < lines; i++)
                for (int j = 0; j < columns; j++)
                    array[j][i] = v[i][j];
        }
    } else throw "Unable to create matrix";

}

Matrix::Matrix (Vector v) {
    if (v.get_C()) {
        columns = v.get_size();
        lines = 1;
        allocate_mem(array, lines, columns);
        for (int i = 0; i < columns; i++)
            array[0][i] = v[i];
    }
    else {
        columns = 1;
        lines = v.get_size();
        allocate_mem(array, lines, columns);
        for (int i = 0; i < columns; i++) array[i][0] = v[i];
    }
}


Matrix::~Matrix() {
    for (int i = 0; i < lines; i++)
        delete[] array[i];
    delete[] array;
}

size_t Matrix::get_lines() const {
    return lines;
}

size_t Matrix::get_columns() const {
    return columns;
}


float Matrix::get_det() {
    Matrix m(array, lines, columns);
    if(lines == columns){
        float tmp;
        for (int k = 0; k < columns - 1; k++)
            for (int i = k + 1; i < columns; i++) {
                tmp = -m.array[i][k] / m.array[k][k];
                for (int j = 0; j < columns; j++)
                    m.array[i][j] += m.array[k][j] * tmp;
            }
        std::cout << std::endl << m << std::endl;
        float d = 1;
        for (int i = 0; i < columns; i++)
            d *= m.array[i][i];
        return d;
    } else throw "Unable to get determinator";
}

Matrix Matrix::element_multiply(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix res;
    if (matrix1.columns == matrix2.columns && matrix1.lines == matrix2.lines) {
        size_t n = matrix1.columns, m = matrix1.lines;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res.array[i][j] = matrix1.array[i][j] * matrix2.array[i][j];
        return res;
    } else throw "Unable to multiply elements";
}

float** Matrix::get_array() {
    return array;
}


float* Matrix::get_diagonal(int type) {
    float* temp = new float;
    if (columns == lines)
        if (type) {
            for (int i = 0; i < columns; i++)
                temp[i] = array[i][i];
        }
        else {
            for (int i = 0; i < columns; ++i) {
                temp[i] = array[i][columns - i - 1];
            }
        }
    else return nullptr;
    return temp;
}

float* Matrix::get_column(int num) { //lines*columns - line*column

    float* temp = new float;
    for (int i = 0; i < lines; i++)
        temp[i] = array[i][num];
    return temp;
}

float* Matrix::get_line(int num) {
    float* temp = new float;
    for (int i = 0; i < columns; i++)
        temp[i] = array[num][i];
    return temp;
}

Matrix Matrix::get_transposed() {
    Matrix transposed(columns, lines);
    for (int i = 0; i < lines; i++) {
        transposed.set_column(get_line(i), i);
    }
    return transposed;
}

void Matrix::set_line(const float* temp_array, int num) {
    for (int i = 0; i < columns; i++) {
        array[num][i] = temp_array[i];
    }
}

void Matrix::set_column(const float* temp_array, int num) {
    for (int i = 0; i < lines; i++) {
        array[i][num] = temp_array[i];
    }
}

float& Matrix::operator()(int index1, int index2) {
    return array[index1][index2];
}

Matrix operator-(const Matrix& matrix) {
    Matrix temp;
    allocate_mem(temp.array, matrix.lines, matrix.columns);
    for (int i = 0; i < matrix.lines; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            temp.array[i][j] = -matrix.array[i][j];
        }
    }
    return temp;
}

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix res;
    if (matrix1.columns == matrix2.columns && matrix1.lines == matrix2.lines) {
        size_t n = matrix1.columns, m = matrix1.lines;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.array[i][j] = matrix1.array[i][j] + matrix2.array[i][j];
            }
        }
    }
    return res;
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix res(matrix1.lines, matrix2.columns);
    size_t M = matrix1.lines;
    size_t N = matrix2.columns;

    if (matrix1.columns == matrix2.lines)
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                res.array[i][j] = 0;
                for (int k = 0; k < N; k++)
                    res.array[i][j] += matrix1.array[i][k] * matrix2.array[k][j];
            }
    return res;
}

Matrix operator*(const Matrix& m, const float& value) {
    Matrix res(m.lines, m.columns);
    size_t M = m.lines;
    size_t N = m.columns;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            res.array[i][j] = m.array[i][j] * value;

    return res;
}

Matrix operator*(const float& value, const Matrix& matrix) {
    return matrix * value;
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
    return matrix1 + (-matrix2);
}

std::ostream& operator << (std::ostream& s, const Matrix& m) {
    for (int i = 0; i < m.lines; i++) {
        for (int j = 0; j < m.columns; j++)
            s << m.array[i][j] << " ";
        s << std::endl;
    }
    return s;
}

Matrix operator*(const Matrix& m, const Vector& v) {
    Matrix vec(v);
    return m*vec;
}

Matrix operator*(const Vector& v, const Matrix& m) {
    Matrix vec(v);
    return vec*m;
}

Matrix operator + (const Matrix& m, const float& f) {
    for (int i = 0; i < m.lines; i++)
        for (int j = 0; j < m.columns; j++)
            m.array[i][j] += f;
    return m;
}

Matrix operator + (const float& f, const Matrix& m) {
    return m + f;
}

Matrix operator + (const Matrix& m, const Vector& v) {
    Matrix vec(v);
    return m + vec;
}
Matrix operator + (const Vector& v, const Matrix& m) {
    Matrix vec(v);
    return m + vec;
}
Matrix operator - (const Matrix& m, const Vector& v) {
    Matrix vec(v);
    return m + (-vec);
}

Matrix operator - (const Matrix& m, const float& f) {
    return m + (-f);
}

Matrix Matrix::inversion() {
if(columns == lines) throw "Unable to invert matrix";
else {
    float temp;
    float **A = new float *[columns];
    for (int i = 0; i < columns; i++)
        A[i] = new float[columns];

    A = array;

    float **E = new float *[columns];
    for (int i = 0; i < columns; i++)
        E[i] = new float[columns];

    for (int i = 0; i < columns; i++)
        for (int j = 0; j < columns; j++) {
            E[i][j] = 0.0;

            if (i == j)
                E[i][j] = 1.0;
        }

    for (int k = 0; k < columns; k++) {
        temp = A[k][k];

        for (int j = 0; j < columns; j++) {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (int i = k + 1; i < columns; i++) {
            temp = A[i][k];

            for (int j = 0; j < columns; j++) {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int k = columns - 1; k > 0; k--)
        for (int i = k - 1; i >= 0; i--) {
            temp = A[i][k];
            for (int j = 0; j < columns; j++) {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }


    for (int i = 0; i < columns; i++)
        for (int j = 0; j < columns; j++)
            A[i][j] = E[i][j];

    for (int i = 0; i < columns; i++)
        delete[] E[i];

    delete[] E;
    return {A, columns, columns};
}
}

Matrix& operator+=(Matrix& m1, const Matrix& m2) {
    return m1 = m1 + m2;
}
