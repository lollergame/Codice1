//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H


#include <stdio.h>

#include "Matrix.h"

template<typename T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix() {}

    SquareMatrix(int x) : Matrix<T>(x, x) {
        //Matrix <int> (x,x);
        //this->setWidth(x);
        //this->setHeight(x);

    }

    virtual ~SquareMatrix() {
    }

    virtual T getValue(int x) {
        Matrix<T>::getValue(x, x);
    }
};


#endif //EXAMDIPRO_VALOMATRIX_H