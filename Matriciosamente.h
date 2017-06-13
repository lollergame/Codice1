//
// Created by ciroso on 12/06/17.
//

#ifndef EXAMDIPRO_MATRICIOSAMENTE_H
#define EXAMDIPRO_MATRICIOSAMENTE_H

template <class T, int R, int C> class Matrice
{
private:
    T mat[R][C]; //array bidimensionale (matrice2D) di tipo T
    int Righe,Colonne; //variabili di tipo int
    void Zero(void); //funzione che inizializza gli elementi di mat a T(0)
    Matrice	*TMP; //puntatore a un'istanza della classe Matrice
public:
    Matrice(void); //costruttore
    ~Matrice(void); //distruttore
//dichiarazioni delle funzioni
    int SonoZero(void);
    int SonoQuadrata(void);
    void MettiValori(int,int,T);
    int operator==(Matrice&);
    int operator!=(Matrice&);
    Matrice& operator=(Matrice&);
    Matrice& operator+(Matrice&);
    Matrice& operator-(Matrice&);
    Matrice& operator*(Matrice&);
    Matrice& operator/(Matrice&);
    Matrice& Trasposta(void);
    Matrice& Inversa(void);
};
