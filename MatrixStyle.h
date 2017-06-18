//
// Created by ciroso on 18/06/17.
//

#ifndef EXAMDIPRO_MATRIXSTYLE_H
#define EXAMDIPRO_MATRIXSTYLE_H


#include "MatrixDesigner.h"
#include "SquareMatrix.h"

template<typename T>
class MatrixStyle : public MatrixDesigner<T> {
public:
    Matrix<T> *createMatrix(int x, int y) const {
        if (x == y)
            return new SquareMatrix<T>(x);
            /*else if ( x == 1 && y >= 0 )
                return new RowVector<T>(x,y);
            else if ( x >= 0 && y == 1)
                return new ColVector<T>(x,y);
            else if ( x >= 0 && y >= 0 && x != y)
                return new RectangleMatrix<T>(x,y);
            */else return 0;
    }
};


#endif //EXAMDIPRO_MATRIXSTYLE_H
