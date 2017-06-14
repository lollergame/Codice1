//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H

#include "Matrix.h"

//template<typename T>
class ValoMatrix : public Matrix {
public:

    ValoMatrix(int x, int y) {        //, T initvalnumb = 0){
        width = x;
        height = y;
        value = new int[width * height];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < width; j++)
                value[i+j*height] = 0;
    }

    ~ValoMatrix() {
        delete[] value;
    }

    int getValue(int x, int y) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
            return value[x+y*height];
        else return 0;
    }

    bool setValue(int x, int y, int val) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
            value[x+y*height] = val;
            std::cout << "imposato valore " << val << " in x " << x << " y " << y << std::endl;
            return true;
        } else {
         std::cout<<"inserimento non riuscito"<<std::endl;
         return false;
        }
    }

    ValoMatrix sum(ValoMatrix &rh) {
        if ((this->width == rh.width) && (this->height == rh.height)) {
            //ValoMatrix temp(this->width, this->height);
            for (int i = 0; i < width; i++)
                for (int j = 0; j < height; j++) {
                    int a = (this->getValue(i,j) + rh.getValue(i,j));
                    this->setValue(i,j,a);
                }
            return *this;
        } else {
            ValoMatrix zero(1, 1);
            return zero;
        }
    }

    void printMatrix() {
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++) {
                std::cout << "posizione i " << i << " j " << j << " valore " << this->getValue(i, j) << std::endl;
            }
    }

    int allwidth(int x) {
        if (x >= 0 && x < this->width) {
            //ValoMatrix temp(this->width,1);
            int tempo[this->width];
            for (int i = 0; i < this->width; i++) {
                int a = this->getValue(i,0);
                //temp.setValue(i,0,a);
                tempo[i] = a;
                std::cout<<tempo[i]<<std::endl;
            }
            return *tempo;
        }
    }

    ValoMatrix prod(ValoMatrix &rh) {
        if (this->height == rh.width) {     //Controllo se le matrici sono conformabili
            //T C[this->width * rh.height];
            ValoMatrix G(width, rh.height);
            //ValoMatrix* temp0 = new ValoMatrix(this->width, rh.height);
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < rh.height; j++) {
                    for (int k = 0; k < this->width; k++) {
                        int op = (this->getValue(i, k)) * (rh.getValue(k, j));
                        G.setValue(i, j, op);
                    }
                }
            }
            return G;
        } else return rh;
    }

    ValoMatrix& operator=(ValoMatrix &rh) {
        this->width = rh.width;
        this->height = rh.height;
        if(this->value)
            delete[] value;
        for (int i = 0; i < this->width; i++) {
            for (int j = 0; j < this->height; j++) {
                this->setValue(i,j,rh.value[i+j*height]);
            }
        }

        return *this;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

private:
    int *value;
};


#endif //EXAMDIPRO_VALOMATRIX_H
