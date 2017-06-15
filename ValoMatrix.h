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

    ValoMatrix &allWidth(const ValoMatrix &M, int x) {
        if (x >= 0 && x < M.getWidth()) {
            for (int i = 0; i < M.getWidth(); i++) {
                this->setValue(0, i, M.getValue(x, i));
            }
            return *this;
        }
    }

    ValoMatrix &allHeight(const ValoMatrix &M, int y) {
        if (y >= 0 && y < M.getHeight()) {
            for (int i = 0; i < M.getHeight(); i++) {
                this->setValue(i, 0, M.getValue(i, y));
            }
            return *this;
        }
    }

    ValoMatrix prodWxH(const ValoMatrix &first, const ValoMatrix &second) { //da completare~
        if (this->width == first.width && this->height == second.height)
            for (int i = 0; i < first.width; i++) {
                for (int j = 0; j < second.height; j++) {
                    this->value[i + j * height] = (first.value[i + j * height] + second.value[j + i * width]);
                }
            }
    }

    ValoMatrix prod(ValoMatrix &rh) {
        if (this->height == rh.width) {     //Controllo se le matrici sono conformabili
            ValoMatrix G(width, rh.height);
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

    ValoMatrix &operator=(const ValoMatrix &rh) {
        //TODO evitare autoassegnazione
        this->width = rh.width;
        this->height = rh.height;
        if (this->value)
            delete[] value;
        for (int i = 0; i < this->width; i++)
            for (int j = 0; j < this->height; j++) {
                this->setValue(i, j, rh.value[i + j * height]);
            }
        return *this;
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
