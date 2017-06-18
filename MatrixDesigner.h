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
        Matrix<T> *matrix;
        matrix = createMatrix(x, y);
        matrix->printMatrix();
        /*..?..*/
        return matrix;
    }

    T getValue(int x, int y) {
        getValue(x, y);
    }

    virtual Matrix<T> *createMatrix(int x, int y) const = 0;

protected:
    MatrixDesigner() {}
};


#endif //EXAMDIPRO_MATRIXDESIGNER_H
