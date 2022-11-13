#include "gtest/gtest.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"


TEST(MatrixInit, withArgs) {
float** array = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
array[0] = mas1;
array[1] = mas2;
array[2] = mas3;
Matrix m(array, 3, 3);


EXPECT_EQ(m.get_det(), -263);
}

TEST(MatrixInit, withArgs) {
float** array = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
array[0] = mas1;
array[1] = mas2;
array[2] = mas3;
Matrix m(array, 3, 3);
float* diagonal = {6, 3, 7};

EXPECT_EQ(m.get_diagonal(1), diagonal);
}

TEST(VectorInit, withArgs) {
float mas[3] = { 1, 2, 3 };
Vector v(mas, 3, 1);

EXPECT_EQ(v.get_c, 1);
}

TEST(VectorInit, withArgs) {
float mas[3] = { 1, 2, 3 };
Vector v(mas, 3, 1);
Vector nv(3, 1);
nv = v + v;

float resmas[3] = { 2, 4, 6 };
Vector res(resmas, 3, 1)

EXPECT_EQ(res.get_array(), nv.get_array());
}

TEST(VectorInit, withArgs) {
float mas[3] = { 1, 2, 3 };
Vector v(mas, 3, 1);
Vector nv(3, 1);
nv = v + 2;

float resmas[3] = { 3, 4, 5 };
Vector res(resmas, 3, 1)
EXPECT_EQ(res.get_array(), nv.get_array());
}

TEST(MatrixInit, withArgs) {
float** array = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
array[0] = mas1;
array[1] = mas2;
array[2] = mas3;
Matrix m(array, 3, 3);
Matrix newm(3, 3);
newm = m*2;

float** array1 = new float* [3];
float mass1[3] = { 12, 18, 10 };
float mass2[3] = { 16, 6, 4 };
float mass3[3] = { 2, 8, 14 };
array1[0] = mass1;
array1[1] = mass2;
array1[2] = mass3;

Matrix res(array1, 3, 3);

EXPECT_EQ(newm(0,0), res(0,0));
}

TEST(MatrixInit, withArgs) {
float** array = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
array[0] = mas1;
array[1] = mas2;
array[2] = mas3;
Matrix m(array, 3, 3);


float** array1 = new float* [3];
float mass1[3] = { 12, 16, 2 };
float mass2[3] = { 18, 6, 8 };
float mass3[3] = { 10, 4, 14 };
array1[0] = mass1;
array1[1] = mass2;
array1[2] = mass3;

Matrix res(array1, 3, 3);
EXPECT_EQ(m.get_transposed()(0, 1), res(0, 1));
}

TEST(MatrixInit, withArgs) {
float** array = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
array[0] = mas1;
array[1] = mas2;
array[2] = mas3;
Matrix m(array, 3, 3);

EXPECT_EQ(m.get_det(), -263);

float** array1 = new float* [2];
array1[0] = mas1;
array1[1] = mas2;
Matrix m1(array1, 2, 3);

EXPECT_NE(m1.get_det(), -263);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
