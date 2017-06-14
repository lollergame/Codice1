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
    /*int w = C.getWidth();
    int h = C.getHeight();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            int cval = C.getValue(i, j);
            std::cout << " C finale in posizione i " << i << " j " << j << " = " << C.getValue(i, j) << std::endl;

        }
    }
*/
    cout<<endl<<"Istanzio D come riga 2 di A "<<endl;
    //int D[A.getWidth()] = A.allwidth(1); //chiedo la riga 1
    //for (int i = 0; i < A.getWidth(); i++)
        //for (int j = 0; j < D.getHeight(); j++)
            //std::cout << " D finale in posizione i " << i << " j " << " = " << A.allwidth(i)<< std::endl;
    //A.allwidth(1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}