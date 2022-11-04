#include <iostream>
#include "vector.h"
#include "matrix.h"

int main() {
    float mas[3] = { 1, 2, 3 };
    vector v(mas, 3, 1);
    std::cout << v << std::endl;
    float** masiv = new float* [3];
    float mas1[3] = { 6, 9, 5 };
    float mas2[3] = { 8, 3, 2 };
    float mas3[3] = { 1, 4, 7 };
    masiv[0] = mas1;
    masiv[1] = mas2;
    masiv[2] = mas3;
    matrix m(masiv, 3, 3);
    //std::cout << m << std::endl;
    //std::cout << m(0, 2);
    //std::cout << v << std::endl;
    //vector k = v + v;
    //std::cout << v << std::endl << k;
    //std::cout << m.inversion();
    std::cout << v;
}
