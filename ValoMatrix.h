//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_VALOMATRIX_H
#define EXAMDIPRO_VALOMATRIX_H

#include <stdexcept>
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

    virtual ~ValoMatrix() {
        delete[] value;
    }

    int const getValue(const int x, const int y) const throw(std::out_of_range) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
            return value[x + y * height];
        else
            throw (std::out_of_range(
                    "Out Of Range per la selezione degli indici di riga e/o di colonna, La Matrice ha dimensioni diverse"));
    }

    void setValue(const int x, const int y, const int val) throw(std::out_of_range) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height)) {
            value[x + y * height] = val;
            std::cout << "imposato valore " << val << " in x " << x << " y " << y << std::endl;
        } else
            throw (std::out_of_range(
                    "Out Of Range per la selezione degli indici di riga e/o di colonna, la Matrice ha dimensioni diverse"));
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

    ValoMatrix prendiRiga(const int x) const throw(std::out_of_range) {
        ValoMatrix temp(1, this->width);
        if (x >= 0 && x < this->width) {
            for (int i = 0; i < this->width; i++) {
                temp.setValue(0, i, this->getValue(x, i));
            }
            return temp;
        } else throw (std::out_of_range("Out Of Range con il valore x"));
    }

    ValoMatrix prendiColonna(const int y) const throw(std::out_of_range) {
        ValoMatrix temp(this->height, 1);
        if (y >= 0 && y < this->height) {
            for (int i = 0; i < this->height; i++) {
                temp.setValue(i, 0, this->getValue(i, y));
            }
            return temp;
        } else throw (std::out_of_range("Out Of Range con il valore y"));
    }

    ValoMatrix &trasp() throw(std::out_of_range) {
        if (this->value) {
            for (int i = 0; i < this->width; i++)
                for (int j = i; j < this->height; j++) {
                    int tempor = this->getValue(i, j);
                    this->setValue(i, j, this->getValue(j, i));
                    this->setValue(j, i, tempor);
                }
            return *this;
        } else throw (std::out_of_range("La Matrice non contiene valori"));
    }

    ValoMatrix &underScale(const int x, const int y) throw(std::out_of_range) {
        if ((this->width > 1) && (this->width > 1)) {
            if (x < this->width && y < this->height) {
                this->width = x;
                this->height = y;
                for (int i = x; i < this->width; ++i)
                    for (int j = y; j < this->height; ++j)
                        this->setValue(i, j, 0);
                return *this;
            } else throw (std::out_of_range("Fuori Range"));
        } else throw (std::out_of_range("La Matrice e' gia alla dimensione minima! Impossibile scalare di dimensione"));
    }

    ValoMatrix operator*(const ValoMatrix &rh) throw(std::out_of_range) {
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
        } else
            throw (std::out_of_range(
                    "La Matrice non e' conformabile! La dimensione delle righe della prima Matrice e delle colonne della seconda devono essere uguali!!"));
    }

    ValoMatrix operator+(const ValoMatrix &rh) const throw(std::out_of_range) {
        ValoMatrix temp(rh.width, rh.height);
        if ((this->width == rh.width) && (this->height == rh.height)) {
            for (int i = 0; i < this->width; i++)
                for (int j = 0; j < this->height; j++) {
                    temp.setValue(i, j, (this->getValue(i, j) + rh.getValue(i, j)));
                }
            return temp;
        } else
            throw (std::out_of_range(
                    "La Matrice non e' conformabile!! La dimensione delle righe e delle colonne delle due Matrici deve esere uguale!! "));
    }

    ValoMatrix &operator=(const ValoMatrix &rh) {
        if (this != &rh) {
            this->width = rh.width;
            this->height = rh.height;
            for (int i = 0; i < this->width; i++)
                for (int j = 0; j < this->height; j++)
                    this->setValue(i, j, rh.getValue(i, j));
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