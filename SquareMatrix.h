//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H



#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix() {}

    SquareMatrix(int x) : Matrix<T>(x, x) {}

    virtual ~SquareMatrix() {}

};


#endif //EXAMDIPRO_VALOMATRIX_H