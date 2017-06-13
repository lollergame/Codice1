//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H

#include "Matrix.h"
template<typename T>
class ValoMatrix : public Matrix {
public:

    ValoMatrix(int x,int y){//, T initvalnumb = 0){
        width = x;
        height = y;
        value =  new T[width*height];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < width; j++)
                value[j*height+i] = 0;
    }

    virtual ~ValoMatrix(){
        if(value)
        delete[] value;
    }

    T getValue(int x, int y){
        if (x > 0 && x <= width && y > 0 && y <= height)
            return value[y*width+x];
    }

    void setValue(int x, int y, int val){
        if (x > 0 && x <= width && y > 0 && y <= height)
        value[y*height+x] = val;
    }

    ValoMatrix prod(ValoMatrix &rh) {
        if (this->height == rh.width) {     //Controllo se le matrici sono conformabili
            //T C[this->width * rh.height];
            ValoMatrix <T> G(this->width, rh.height);
            //ValoMatrix* temp0 = new ValoMatrix(this->width, rh.height);
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < rh.height; j++) {
                    for (int k = 0; k < this->width; k++) {
                        T op = (this->getValue(i, k)) * (rh.getValue(k, j));
                        G.setValue(i,j,op);

                    }
                }
            }
            return G;
        }

    }
/*
    ValoMatrix& operator =(ValoMatrix &rh){
        this->width = rh.width;
        this->height = rh.height;
        for (int i = 0; i < this->width; i++) {
            for (int j = 0; j < this->height; j++) {
                this->value[j*height+i] = rh.value[j*height+i];
            }
        }

        return *this;
    }
  */  T getWidth(){
        return width;
    }

    T getHeight(){
        return height;
    }
private:
    int* value;
};


#endif //EXAMDIPRO_VALOMATRIX_H
