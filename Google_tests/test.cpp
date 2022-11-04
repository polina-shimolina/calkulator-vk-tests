//
// Created by Polina on 24.10.2022.
//

#include "gtest/gtest.h"
#include <iostream>
#include "matrix.h"
#include "vector.h"

class matrixClass : public testing::Test {
protected:
    matrix *_matrix;
    vector *_vector;
    void SetUp() {
        float** masiv = new float* [3];
        float mas1[3] = { 6, 9, 5 };
        float mas2[3] = { 8, 3, 2 };
        float mas3[3] = { 1, 4, 7 };
        masiv[0] = mas1;
        masiv[1] = mas2;
        masiv[2] = mas3;
        matrix m(masiv, 3, 3);
        _matrix = new matrix(masiv, 3, 3);

        float mas[3] = { 1, 2, 3 };
        _vector = new vector(mas, 3, 1);
    }
    void TearDown() {
        delete _matrix;
    }
};

TEST(MatrixInit, withArgs) {
float** masiv = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
masiv[0] = mas1;
masiv[1] = mas2;
masiv[2] = mas3;
matrix m(masiv, 3, 3);


EXPECT_EQ(m.get_det(), -263);
}

TEST(MatrixInit, withArgs) {
float** masiv = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
masiv[0] = mas1;
masiv[1] = mas2;
masiv[2] = mas3;
matrix m(masiv, 3, 3);
float* diagonal == {6, 3, 7};

EXPECT_EQ(m.get_diagonal(1), diagonal);
}

TEST(VectorInit, withArgs) {
float mas[3] = { 1, 2, 3 };
vector v(mas, 3, 1);

EXPECT_EQ(v.get_c, 1);
}

TEST(VectorInit, withArgs) {
float mas[3] = { 1, 2, 3 };
vector v(mas, 3, 1);
vector nv(3, 1);
nv = v + v;

float resmas[3] = { 2, 4, 6 };
vector res(resmas, 3, 1)
EXPECT_EQ(res.get_array(), nv.get_array());
}

TEST(VectorInit, withArgs) {
float mas[3] = { 1, 2, 3 };
vector v(mas, 3, 1);
vector nv(3, 1);
nv = v + 2;

float resmas[3] = { 3, 4, 5 };
vector res(resmas, 3, 1)
EXPECT_EQ(res.get_array(), nv.get_array());
}

TEST(MatrixInit, withArgs) {
float** masiv = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
masiv[0] = mas1;
masiv[1] = mas2;
masiv[2] = mas3;
matrix m(masiv, 3, 3);
matrix newm(3, 3);
newm = m*2;

float** masivv = new float* [3];
float mass1[3] = { 12, 18, 10 };
float mass2[3] = { 16, 6, 4 };
float mass3[3] = { 2, 8, 14 };
masivv[0] = mass1;
masivv[1] = mass2;
masivv[2] = mass3;

matrix res(masivv, 3, 3);
EXPECT_EQ(newm(0,0), res(0,0));
}

TEST(MatrixInit, withArgs) {
float** masiv = new float* [3];
float mas1[3] = { 6, 9, 5 };
float mas2[3] = { 8, 3, 2 };
float mas3[3] = { 1, 4, 7 };
masiv[0] = mas1;
masiv[1] = mas2;
masiv[2] = mas3;
matrix m(masiv, 3, 3);


float** masivv = new float* [3];
float mass1[3] = { 12, 16, 2 };
float mass2[3] = { 18, 6, 8 };
float mass3[3] = { 10, 4, 14 };
masivv[0] = mass1;
masivv[1] = mass2;
masivv[2] = mass3;

matrix res(masivv, 3, 3);
EXPECT_EQ(m.get_transposed()(0, 1), res(0, 1));
}
