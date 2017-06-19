#include <iostream>

#include "MatrixDesigner.h"
#include "MatrixStyle.h"

using namespace std;

int main() {
    try {
        cout << "Quadrata" << endl;
        MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
        Matrix<int> *matrix1 = mtp1->choiceMatrixType(5, 5);
        matrix1->printMatrix();
        matrix1->whoAmI();

        cout << "Vettore colonna" << endl;
        MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
        Matrix<int> *matrix2 = mtp2->choiceMatrixType(3, 1);
        matrix2->printMatrix();
        matrix2->whoAmI();

        cout << "Vettore riga" << endl;
        MatrixDesigner<int> *mtp3 = new MatrixStyle<int>();
        Matrix<int> *matrix3 = mtp3->choiceMatrixType(1, 3);
        matrix3->printMatrix();
        matrix3->whoAmI();

        cout << "Rettangolare" << endl;
        MatrixDesigner<int> *mtp4 = new MatrixStyle<int>();
        Matrix<int> *matrix4 = mtp4->choiceMatrixType(3, 4);
        matrix4->printMatrix();
        matrix4->whoAmI();

    }
    catch (std::out_of_range &e) {
        cerr << e.what() << endl;
        return 42;
    }
    catch (std::logic_error &e) {
        cerr << e.what() << endl;
        return 101;
    }
}