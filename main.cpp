#include <iostream>
#include "ValoMatrix.h"
//#include "SimpleMatrix.h"

using namespace std;

int main() {
    try {
        cout << "Istanzio A come 2x2" << endl;
        ValoMatrix<int> A(2, 2);
        int tre = 3;
        int quattro = 4;
        A.setValue(0, 0, 1);
        A.setValue(0, 1, 2);
        A.setValue(1, 0, tre);
        A.setValue(1, 1, quattro);
        A.printMatrix();

        cout << endl << "Istanzio B come 2x2" << endl;
        ValoMatrix<int> B(2, 2);
        B.setValue(0, 0, 5);
        B.setValue(0, 1, 6);
        B.setValue(1, 0, 7);
        B.setValue(1, 1, 8);
        B.printMatrix();

        cout << endl << "Istanzio C come A + B" << endl;
        ValoMatrix<int> C = A + B;
        C.printMatrix();

        cout << endl << endl << "Istanzio D come prima riga di C " << endl;
        ValoMatrix<int> D = C.prendiRiga(0);
        D.printMatrix();

        cout << endl << "Istanzio E come seconda riga di C " << endl;
        ValoMatrix<int> E = C.prendiRiga(1);
        E.printMatrix();

        cout << endl << "Istanzio F come prima colonna di C" << endl;
        ValoMatrix<int> F = C.prendiColonna(0);
        F.printMatrix();

        cout << endl << "Istanzio G come seconda colonna di C" << endl;
        ValoMatrix<int> G(C.getWidth(), C.getHeight());
        G = C.prendiColonna(1);
        G.printMatrix();

        cout << "Istanzio H come prodotto tra A e B" << endl;
        ValoMatrix<int> H = A * B;
        H.printMatrix();

        cout << "Istanzio I come copia di A e traspongo" << endl;
        ValoMatrix<int> I(2, 2);
        cout << "Copio A in I" << endl;
        I = A;
        cout << "Traspongo I" << endl;
        I.trasp();
        cout << "Printo I" << endl;
        I.printMatrix();

        cout << "A" << endl;
        A.printMatrix();
        cout << "traspongo A" << endl;
        A.trasp();
        A.printMatrix();

        cout << "Orlata 1x1 di A" << endl;
        A.underScale(1, 1);
        A.printMatrix();

        cout << "Orlata 10x10 di A" << endl;
        A.underScale(10, 10);
        A.printMatrix();

        std::cout << "Hello, World!" << std::endl;
        return 0;
    }
    catch (std::out_of_range &e) { cerr << e.what() << endl; }
}