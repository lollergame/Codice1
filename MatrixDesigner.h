//
// Created by ciroso on 18/06/17.
//

#ifndef EXAMDIPRO_MATRIXDESIGNER_H
#define EXAMDIPRO_MATRIXDESIGNER_H

#include "Matrix.h"

template<typename T>
class MatrixDesigner {
public:
    virtual ~MatrixDesigner() {}

    Matrix<T> *choiceMatrixType(int x, int y) const {
        Matrix<T> *mtx;
        mtx = createMatrix(x, y);
        return mtx;
    }

    virtual Matrix<T> *createMatrix(int x, int y) const = 0;

protected:
    MatrixDesigner() {}
};

#endif //EXAMDIPRO_MATRIXDESIGNER_H