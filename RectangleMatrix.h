//
// Created by ciroso on 19/06/17.
//

#ifndef EXAMDIPRO_RECTANGLEMATRIX_H
#define EXAMDIPRO_RECTANGLEMATRIX_H

#include "Matrix.h"

template<typename T>
class RectangleMatrix : public Matrix<T> {
public:
    RectangleMatrix() {}

    RectangleMatrix(int x, int y) : Matrix<T>(x, y) {}

    virtual ~RectangleMatrix() {}

};


#endif //EXAMDIPRO_RECTANGLEMATRIX_H
