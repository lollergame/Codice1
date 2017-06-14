//
// Created by ciroso on 13/06/17.
//

#ifndef EXAMDIPRO_SIMPLEMATRIX_H
#define EXAMDIPRO_SIMPLEMATRIX_H

//#include "Matrix.h"

class SimpleMatrix  {
public:
    SimpleMatrix(int r, int c){
        width = r;
        height = c;
        data = new int[width * height];
        /*for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                data[j * height + i] = 0;
            }
        }*/
    }

    virtual ~SimpleMatrix(){
    delete[] data;
    }

    bool setValue(int x, int y, int v){
        if ((x <= width) && (x > 0) && (y > 0) && (y <= height)) {
            data[x * width + y] = v;
            return true;
        } else return false;
    }

    bool getValue(int x, int y, int& v){
        if ((x <= width) && (x > 0) && (y > 0) && (y <= height)) {
            v = data[x * width + y];
            return true;
        } else return false;
    }

private:
    int width,height;
    int* data;
};

#endif //EXAMDIPRO_SIMPLEMATRIX_H