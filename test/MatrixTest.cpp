#include "gtest/gtest.h"

#include "../SquareMatrix.h"
#include "../MatrixStyle.h"

TEST(Matrix, testSquare) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(4, 4);
    ASSERT_EQ(matrix->getType() == "Square Matrix", true);
    std::cout << "Eseguito test della generazione di una Matrice quadrata\n" << std::endl;
}

TEST(Matrix, testRectangle) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 4);
    ASSERT_EQ(matrix->getType() == "Rectangle Matrix", true);
    std::cout << "Eseguito test della generazione di una Matrice rettangolare\n" << std::endl;
}

TEST(Matrix, testRow) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(1, 4);
    ASSERT_EQ(matrix->getType() == "Row Vector", true);
    std::cout << "Eseguito test della generazione di un Vettore riga\n" << std::endl;
}

TEST(Matrix, testCol) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(4, 1);
    ASSERT_EQ(matrix->getType() == "Column Vector", true);
    std::cout << "Eseguito test della generazione di un Vettore colonna\n" << std::endl;
}

TEST(MatrixDesigner, intCtorTest) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    int value = matrix->getValue(5, 5);
    ASSERT_EQ(value == 0, true);
    std::cout << "Eseguito test del costruttore con gli interi\n" << std::endl;
}

TEST(MatrixDesigner, doubleCtorTest) {
    MatrixDesigner<double> *mtp = new MatrixStyle<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    double value = matrix->getValue(5, 5);
    ASSERT_EQ(value == 0, true);
    std::cout << "Eseguito test del costruttore con i double\n" << std::endl;
}

TEST (Matrix, testGetValue) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    int value = 1;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 0, true);
    std::cout << "Eseguito test del getValue\n" << std::endl;
}

TEST(Matrix, intTestSetValue) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1);
    matrix->setValue(2, 3, 5);
    int value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5, true);
    std::cout << "Eseguito test del setValue con gli int\n" << std::endl;
}

TEST(Matrix, doubleTestSetValue) {
    MatrixDesigner<double> *mtp = new MatrixStyle<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1.00005);
    matrix->setValue(2, 3, 5.0009);
    double value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5.0009, true);
    std::cout << "Eseguito test del setValue con i double\n" << std::endl;
}



/*

            cout << "Istanzio A come 2x2" << endl;
            Matrix<int> A(4, 4);
            int tre = 3;
            int quattro = 4;
            A.setValue(0, 0, 1);
            A.setValue(0, 1, 2);
            A.setValue(1, 0, tre);
            A.setValue(1, 1, quattro);
            A.printMatrix();

            cout << endl << "Istanzio B come 2x2" << endl;
            Matrix<int> B(4, 4);
            B.setValue(0, 0, 5);
            B.setValue(0, 1, 6);
            B.setValue(1, 0, 7);
            B.setValue(1, 1, 8);
            B.printMatrix();

            cout << endl << "Istanzio C come A + B" << endl;
            Matrix<int> C = A + B;
            C.printMatrix();

            cout << endl << endl << "Istanzio D come prima riga di C " << endl;
            Matrix<int> D = C.prendiRiga(0);
            D.printMatrix();

            cout << endl << "Istanzio E come seconda riga di C " << endl;
            Matrix<int> E = C.prendiRiga(1);
            E.printMatrix();

            cout << endl << "Istanzio F come prima colonna di C" << endl;
            Matrix<int> F = C.prendiColonna(0);
            F.printMatrix();

            cout << endl << "Istanzio G come seconda colonna di C" << endl;
            Matrix<int> G(C.getWidth(), C.getHeight());
            G = C.prendiColonna(1);
            G.printMatrix();

            cout << "Istanzio H come prodotto tra A e B" << endl;
            Matrix<int> H = A * B;
            H.printMatrix();

            cout << "A" << endl;
            A.printMatrix();

            cout << "Istanzio I come copia di A e traspongo" << endl;
            Matrix<int> I(4, 4);
            cout << "Copio A in I" << endl;
            I = A;
            I.printMatrix();
            cout << "Traspongo I" << endl;
            I.trasp();
            cout << "Printo I" << endl;
            I.printMatrix();

            cout << "A" << endl;
            A.printMatrix();
            cout << "traspongo A" << endl;
            A.trasp();
            A.printMatrix();

            cout << "Orlata 4x4 di A" << endl;
            A.underScale(4, 4);
            A.printMatrix();

            cout << "Autoassegno A" << endl;
            A = A;

            cout << "Orlata 10x10 di A" << endl;
            A.underScale(10, 10);
            A.printMatrix();

            std::cout << "Hello, World!" << std::endl;
            return 0;

        }*/