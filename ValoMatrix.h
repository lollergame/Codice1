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

    ValoMatrix(const int x, const int y) {
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

    int const getValue(const int x, const int y) const {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
            return value[x + y * height];
        else return 0;
    }

    bool setValue(const int x, const int y, const int val) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
            value[x + y * height] = val;
            std::cout << "imposato valore " << val << " in x " << x << " y " << y << std::endl;
            return true;
        } else {
            std::cout << "inserimento non riuscito" << std::endl;
            return false;
        }
    }

    void printMatrix() const {
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

    ValoMatrix prendiRiga(const int x) const {
        ValoMatrix temp(1, this->width);
        if (x >= 0 && x < this->width) {
            for (int i = 0; i < this->width; i++) {
                temp.setValue(0, i, this->getValue(x, i));
            }
            return temp;
        } else return temp;
    }

    ValoMatrix prendiColonna(const int y) const {
        ValoMatrix temp(this->height, 1);
        if (y >= 0 && y < this->height) {
            for (int i = 0; i < this->height; i++) {
                temp.setValue(i, 0, this->getValue(i, y));
            }
            return temp;
        } else return temp;
    }

    ValoMatrix &trasp() {
        ValoMatrix *temp = new ValoMatrix(this->width, this->height);
        temp = this;
        if (this->value) {
            for (int i = 0; i < this->width; i++)
                for (int j = i; j < this->height; j++) {
                    int tempor = temp->getValue(i, j);
                    temp->setValue(i, j, temp->getValue(j, i));
                    temp->setValue(j, i, tempor);

                }
            return *temp;
        } else {
            ValoMatrix *zero = new ValoMatrix(1, 1);
            return *zero;
        };
        //else throw
    }

    ValoMatrix operator*(const ValoMatrix &rh) {
        ValoMatrix temp(this->width, rh.height);
        if (this->height == rh.width) {
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < rh.height; j++) {
                    int tempor = 0;
                    for (int k = 0; k < this->height; k++) {
                        tempor += this->getValue(i, k) * rh.getValue(k, j);
                        temp.setValue(i, j, tempor);
                    }
                }
            }
            return temp;
        }
        return temp;
    }

    ValoMatrix operator+(const ValoMatrix &rh) {
        ValoMatrix temp(rh.width, rh.height);
        if ((this->width == rh.width) && (this->height == rh.height)) {
            for (int i = 0; i < this->width; i++)
                for (int j = 0; j < this->height; j++) {
                    temp.setValue(i, j, (this->getValue(i, j) + rh.getValue(i, j)));
                }
            return temp;
        } else return temp;
    }

    ValoMatrix operator=(const ValoMatrix &rh) const {
        ValoMatrix temp(rh.getWidth(), rh.getHeight());
        if (this != &rh) {
            temp.width = rh.width;
            temp.height = rh.height;
            if (this->value)
                delete[] value;
            for (int i = 0; i < temp.width; i++)
                for (int j = 0; j < temp.height; j++) {
                    temp.setValue(i, j, rh.getValue(i, j));
                }
            return temp;
        } else return temp;
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