//
// Created by Polina on 24.10.2022.
//

#ifndef MATRIX_CALCULATOR_VECTOR_H
#define MATRIX_CALCULATOR_VECTOR_H

#include <iostream>
class vector {
    friend vector operator - (const vector&);
    friend std::ostream& operator << (std::ostream& s, const vector& r);
    friend vector operator + (const vector&, const float&);
    friend vector operator + (const float&, const vector&);
    friend vector operator + (const vector& v1, const vector& v2);
    friend vector operator - (const vector&, const float&);
private:
    float* array;
    int N, c; //c = 1 => ������, � = 0 => �������
public:
    vector();
    vector(int, int);
    vector(float*, int, int);
    ~vector();

    float* get_array();
    //float get_element(int); //����������
    int get_size();
    int get_N();
    int get_C();
    vector operator = (float*);
    float operator [] (int n);
};


#endif //MATRIX_CALCULATOR_VECTOR_H
