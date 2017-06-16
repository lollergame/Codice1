#include <iostream>
#include "ValoMatrix.h"
//#include "SimpleMatrix.h"

using namespace std;

int main() {

    cout<<"Istanzio A come 2x2"<<endl;
    ValoMatrix A(2, 2);
    int dieci = 10;
    int cinque = 5;
    A.setValue(0, 0, 1);
    A.setValue(0, 1, 2);
    A.setValue(1, 0, cinque);
    A.setValue(1, 1, dieci);
    for (int i = 0; i < A.getWidth(); i++)
        for (int j = 0; j < A.getHeight(); j++)
            std::cout << " A finale in posizione i " << i << " j " << j << " = " << A.getValue(i, j) << std::endl;

    cout<<endl<<"Istanzio B come 2x2" << endl;
    ValoMatrix B(2, 2);
    B.setValue(0, 0, 100);
    B.setValue(0, 1, 50);
    B.setValue(1, 0, 500);
    B.setValue(1, 1, 1000);
    for (int i = 0; i < B.getWidth(); i++)
        for (int j = 0; j < B.getHeight(); j++)
            std::cout << " B finale in posizione i " << i << " j " << j << " = " << B.getValue(i, j) << std::endl;

    cout <<endl<< "Istanzio C come A + B" << endl;
    ValoMatrix C = A.sum(B);
    C.printMatrix();

    cout<<endl<<endl<<"Istanzio D come prima riga di C "<<endl;
    ValoMatrix D(1,C.getWidth());
    D = C.prendiRiga(0); //D.allWidth(C,0);
    D.printMatrix();

    cout<<endl<<"Istanzio E come seconda riga di C "<<endl;
    ValoMatrix E(1,C.getWidth());
    E = C.prendiRiga(1);
    E.printMatrix();

    cout<<endl<< "Istanzio F come prima colonna di C"<<endl;
    ValoMatrix F(C.getHeight(),1);
    F = C.prendiColonna(0);
    F.printMatrix();

    cout<<endl<< "Istanzio G come seconda colonna di C"<<endl;
    ValoMatrix G(C.getHeight(),1);
    G = C.prendiColonna(1);
    G.printMatrix();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}