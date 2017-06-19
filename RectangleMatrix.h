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

    RectangleMatrix(int x, int y) : Matrix<T>(x, y) {
        this->setType("Rectangle Matrix");
    }

    virtual ~RectangleMatrix() {}

    virtual void whoAmI() const override {
        Matrix<T>::whoAmI();
        cout << this->getType() << endl;
    }
};


#endif //EXAMDIPRO_RECTANGLEMATRIX_H
