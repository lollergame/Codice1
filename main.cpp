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

        cout << endl << "Vettore colonna" << endl;
        MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
        Matrix<int> *matrix2 = mtp2->choiceMatrixType(3, 1);
        matrix2->printMatrix();
        matrix2->whoAmI();

        cout << endl << "Vettore riga" << endl;
        MatrixDesigner<int> *mtp3 = new MatrixStyle<int>();
        Matrix<int> *matrix3 = mtp3->choiceMatrixType(1, 3);
        matrix3->printMatrix();
        matrix3->whoAmI();

        cout << endl << "Rettangolare" << endl;
        MatrixDesigner<int> *mtp4 = new MatrixStyle<int>();
        Matrix<int> *matrix4 = mtp4->choiceMatrixType(3, 4);
        matrix4->printMatrix();
        matrix4->whoAmI();

        cout << "Matrix3" << endl;
        matrix3->setValue(1, 1, 1);
        matrix3->setValue(1, 2, 2);
        matrix3->setValue(1, 3, 3);
        matrix3->printMatrix();

        cout << "Matrix2" << endl;
        matrix2->setValue(1, 1, 1);
        matrix2->setValue(2, 1, 2);
        matrix2->setValue(3, 1, 3);
        matrix2->printMatrix();

        cout << "Matrix5 = matrix3 * matrix 2" << endl;
        MatrixDesigner<int> *mtp5 = new MatrixStyle<int>();
        Matrix<int> *matrix5 = mtp1->choiceMatrixType(1, 1);
        *matrix5 = matrix3->operator*(matrix2);
        matrix5->printMatrix();

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