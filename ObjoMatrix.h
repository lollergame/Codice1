//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_OBJOMATRIX_H
#define EXAMDIPRO_OBJOMATRIX_H


#include "Matrix.h"
template<typename T>
class ObjoMatrix : public Matrix {
public:
    ObjoMatrix(int x,int y, T initvalobj){
        width = x;
        height = y;
        value =  new T[x*y];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < width; j++)
                value[j*height+i] = initvalobj;
    }

    virtual ~ObjoMatrix(){
        delete[] value;
    }

    T getValue(int x, int y){
        return this->value[y*width+x];
    }
private:
    T value;
};


#endif //EXAMDIPRO_OBJOMATRIX_H
