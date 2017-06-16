//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H

#include "Matrix.h"
//TODO unit testing urgente

//template<typename T>
class ValoMatrix : public Matrix {
public:

    ValoMatrix(int x, int y) {        //, T initvalnumb = 0){
        width = x;
        height = y;
        value = new int[width * height];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < width; j++)
                value[i + j * height] = 0;
    }

    ~ValoMatrix() {
        delete[] value;
    }

    int getValue(int x, int y) const {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
            return value[x + y * height];
        else return 0;
    }

    bool setValue(int x, int y, int val) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
            value[x + y * height] = val;
            std::cout << "imposato valore " << val << " in x " << x << " y " << y << std::endl;
            return true;
        } else {
            std::cout << "inserimento non riuscito" << std::endl;
            return false;
        }
    }

    ValoMatrix sum(ValoMatrix &rh) {
        if ((this->width == rh.width) && (this->height == rh.height)) {
            //ValoMatrix temp(this->width, this->height);
            for (int i = 0; i < width; i++)
                for (int j = 0; j < height; j++) {
                    int a = (this->getValue(i, j) + rh.getValue(i, j));
                    this->setValue(i, j, a);
                }
            return *this;
        } else {
            ValoMatrix zero(1, 1);
            return zero;
        }
    }

    void printMatrix() {
        for (int i = 0; i < width; i++) {
            std::cout << std::endl;
            for (int j = 0; j < height; j++) {
                std::cout << this->getValue(i, j);
                if (j <= i)
                    std::cout << " ";
                else if (j >= i)
                    std::cout << std::endl;
            }
        }
        std::cout << std::endl << std::endl;

    }

    ValoMatrix prendiRiga(const int x) {
        ValoMatrix temp(1, this->width);
        if (x >= 0 && x < this->width) {
            for (int i = 0; i < this->width; i++) {
                //int a = this->getValue(x,i);
                temp.setValue(0, i, this->getValue(x, i));
            }
            return temp;
        } else return temp;
    }

    ValoMatrix prendiColonna(int y) {
        ValoMatrix temp(this->height, 1);
        if (y >= 0 && y < this->height) {
            for (int i = 0; i < this->height; i++) {
                temp.setValue(i, 0, this->getValue(i, y));
            }
            return temp;
        } else return temp;
    }

    ValoMatrix prod(ValoMatrix &rh) {
        ValoMatrix temp(width, rh.height);
        if (this->height == rh.width) {
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < rh.height; j++) {
                    int tempor = 0;
                    for (int k = 0; k < this->height; k++) {
                        int val1 = this->getValue(i, k);
                        int val2 = rh.getValue(k, j);
                        tempor += this->getValue(i, k) * rh.getValue(k, j);
                        temp.setValue(i, j, tempor);
                    }
                }
            }
            return temp;
        }
        return temp;
    }

    /**   if (this->height == rh.width) {     //Controllo se le matrici sono conformabili

                   for (int k = 0; k < this->width; k++) {
                       int op = (this->getValue(i, k)) * (rh.getValue(k, j));
                       G.setValue(i, j, op);
                   }
               }
           }
           return G;
       } else return rh;
   }
   */

    ValoMatrix &operator=(const ValoMatrix &rh) {
        if (this != &rh) {
            this->width = rh.width;
            this->height = rh.height;
            if (this->value)
                delete[] value;
            for (int i = 0; i < this->width; i++)
                for (int j = 0; j < this->height; j++) {
                    this->setValue(i, j, rh.value[i + j * height]);
                }
            return *this;
        } else return *this;
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

private:
    int *value;
};


#endif //EXAMDIPRO_VALOMATRIX_H
