//
// Created by ciroso on 19/06/17.
//

#ifndef EXAMDIPRO_COLVECTOR_H
#define EXAMDIPRO_COLVECTOR_H

#include "Matrix.h"

template<typename T>
class ColVector : public Matrix<T> {
public:
    ColVector() {}

    ColVector(int x, int y) : Matrix<T>(x, 1) {}

    virtual ~ColVector() {}
};


#endif //EXAMDIPRO_COLVECTOR_H
