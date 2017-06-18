//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_MATRIX_H
#define EXAMDIPRO_MATRIX_H

#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Matrix {
public:
    Matrix() {
        width = 1;
        height = 1;
        value = new T[width * height];
        value[width + height * width] = 0;
    }

    Matrix(int x, int y) {
        width = x;
        height = y;
        value = new T[width * height];
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++)
                value[i + j * width] = 0;
    }

    virtual ~Matrix() {
        if (value)
        delete[] value;
    }

    virtual T const getValue(const int x, const int y) const throw(std::out_of_range) {
        if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
            return value[x + y * width];
        else
            throw (std::out_of_range(
                    "Out Of Range per la selezione degli indici di riga e/o di colonna, La Matrice ha dimensioni diverse"));
    }

/*
    virtual void setValue(const int x, const int y, const int val) throw(std::out_of_range) {
        if ((x >= 0) && (y >= 0) && (x < width) && (y < height)) {
            value[x + y * width] = val;
        } else
            throw (std::out_of_range(
                    "Out Of Range per la selezione degli indici di riga e/o di colonna, la Matrice ha dimensioni diverse"));
    }
*/
    virtual void printMatrix() const {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++)
                std::cout << this->getValue(i, j) << "\t";
            std::cout << std::endl << std::endl;
        }
    }

/** Matrix prendiRiga(const int x) const throw(std::out_of_range) {
    Matrix temp(1, this->width);
    if (x >= 0 && x < this->width) {
        for (int i = 0; i < this->width; i++) {
            temp.setValue(0, i, this->getValue(x, i));
        }
        return temp;
    } else throw (std::out_of_range("Out Of Range con il valore x"));
}

Matrix prendiColonna(const int y) const throw(std::out_of_range) {
    Matrix temp(this->height, 1);
    if (y >= 0 && y < this->height) {
        for (int i = 0; i < this->height; i++) {
            temp.setValue(i, 0, this->getValue(i, y));
        }
        return temp;
    } else throw (std::out_of_range("Out Of Range con il valore y"));
}

    virtual Matrix &trasp() throw(std::out_of_range) {
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

    virtual Matrix &underScale(const int x, const int y) throw(std::out_of_range) {
        if ((this->width > 1) && (this->height > 1)) {
            if (x <= this->width && y <= this->height) {
                this->width = x;
                this->height = y;
                for (int i = x; i < this->width; ++i)
                    for (int j = y; j < this->height; ++j)
                        this->setValue(i, j, 0);
                return *this;
            } else
                throw (std::out_of_range(
                        "I valori inseriti vanno oltre la dimensione della Matrice, impossibile genereare Matrice orlata!"));
        } else throw (std::out_of_range("La Matrice e' gia alla dimensione minima! Impossibile scalare di dimensione"));
    }

    virtual Matrix operator*(const Matrix &rh) throw(std::out_of_range) {
        Matrix temp(this->width, rh.height);
        if (this->height == rh.width) {
            for (int i = 0; i < this->width; i++) {
                for (int j = 0; j < rh.height; j++) {
                    T tempor = 0;
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

    virtual Matrix operator+(const Matrix &rh) const throw(std::out_of_range) {
        Matrix temp(rh.width, rh.height);
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

    virtual Matrix &operator=(const Matrix &rh) throw(std::logic_error) {
        if (this != &rh) {
            this->width = rh.width;
            this->height = rh.height;
            for (int i = 0; i < this->width; i++)
                for (int j = 0; j < this->height; j++)
                    this->setValue(i, j, rh.getValue(i, j));
            return *this;
        } else throw (std::logic_error("Impossibile utilizzare la stessa Matrice per l'assegnazione"));
    }

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    void setWidth(int width) {
        this->width = width;
    }

    void setHeight(int height) {
        this->height = height;
    }
*/
private:
    int width, height;
    int *value;
};


#endif //EXAMDIPRO_MATRIX_H
