//
// Created by ciroso on 19/06/17.
//

#ifndef EXAMDIPRO_ROWVECTOR_H
#define EXAMDIPRO_ROWVECTOR_H

#include "Matrix.h"

template<typename T>
class RowVector : public Matrix<T> {
public:
    RowVector() {}

    RowVector(int x, int y) : Matrix<T>(1, y) {}

    virtual ~RowVector() {}
};


#endif //EXAMDIPRO_ROWVECTOR_H