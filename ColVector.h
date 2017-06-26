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

    ColVector(int x, int y) : Matrix<T>(x, 1) {
        this->setType("Column Vector");
    }

    virtual ~ColVector() {}

    virtual void whoAmI() const override {
        Matrix<T>::whoAmI();
        cout << this->getType() << endl << endl;
    }
};


#endif //EXAMDIPRO_COLVECTOR_H
