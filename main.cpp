#include <iostream>
#include "ValoMatrix.h"
//#include "SimpleMatrix.h"

using namespace std;

int main() {

    cout<<"Istanzio A come 2x2"<<endl;
    ValoMatrix A(2, 2);
    int tre = 3;
    int quattro = 4;
    A.setValue(0, 0, 1);
    A.setValue(0, 1, 2);
    A.setValue(1, 0, tre);
    A.setValue(1, 1, quattro);
    A.printMatrix();

    cout<<endl<<"Istanzio B come 2x2" << endl;
    ValoMatrix B(2, 2);
    B.setValue(0, 0, 5);
    B.setValue(0, 1, 6);
    B.setValue(1, 0, 7);
    B.setValue(1, 1, 8);
    B.printMatrix();

    cout <<endl<< "Istanzio C come A + B" << endl;
    ValoMatrix C = A + B;
    C.printMatrix();

    cout<<endl<<endl<<"Istanzio D come prima riga di C "<<endl;
    ValoMatrix D = C.prendiRiga(0);
    D.printMatrix();

    cout<<endl<<"Istanzio E come seconda riga di C "<<endl;
    ValoMatrix E = C.prendiRiga(1);
    E.printMatrix();

    cout<<endl<< "Istanzio F come prima colonna di C"<<endl;
    ValoMatrix F = C.prendiColonna(0);
    F.printMatrix();

    cout<<endl<< "Istanzio G come seconda colonna di C"<<endl;
    ValoMatrix G = C.prendiColonna(1);
    G.printMatrix();

    cout << "Riecco A" << endl;
    A.printMatrix();

    cout << "Istanzio H come prodotto tra A e B" << endl;
    ValoMatrix H = A * B;
    H.printMatrix();

    cout << "Istanzio I come copia di A e traspongo" << endl;
    ValoMatrix I = A;
    I.trasp();
    I.printMatrix();

    cout << "A" << endl;
    A.printMatrix();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}