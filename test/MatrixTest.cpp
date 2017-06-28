#include "gtest/gtest.h"

#include "../SquareMatrix.h"
#include "../MatrixStyle.h"

TEST(Matrix, testSquare) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(4, 4);
    ASSERT_EQ(matrix->getType() == "Square Matrix", true);
}

TEST(Matrix, testRectangle) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 4);
    ASSERT_EQ(matrix->getType() == "Rectangle Matrix", true);
}

TEST(Matrix, testRow) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(1, 4);
    ASSERT_EQ(matrix->getType() == "Row Vector", true);
}

TEST(Matrix, testCol) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(4, 1);
    ASSERT_EQ(matrix->getType() == "Column Vector", true);
}

TEST(MatrixDesigner, intCtorTest) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    int value = matrix->getValue(5, 5);
    ASSERT_EQ(value == 0, true);
}

TEST(MatrixDesigner, doubleCtorTest) {
    MatrixDesigner<double> *mtp = new MatrixStyle<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    double value = matrix->getValue(5, 5);
    ASSERT_EQ(value == 0, true);
}

TEST (Matrix, testGetValue) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    int value = 1;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 0, true);
}

TEST(Matrix, intTestSetValue) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1);
    matrix->setValue(2, 3, 5);
    int value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5, true);
}

TEST(Matrix, doubleTestSetValue) {
    MatrixDesigner<double> *mtp = new MatrixStyle<double>();
    Matrix<double> *matrix = mtp->choiceMatrixType(5, 5);
    matrix->setValue(2, 3, 1.00005);
    matrix->setValue(2, 3, 5.0009);
    double value = 0;
    value = matrix->getValue(2, 3);
    ASSERT_EQ(value == 5.0009, true);
}

TEST(Matrix, TestReturnRow) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(1, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    matrix2->setValue(1, 2, 2);
    *matrix1 = matrix->returnRow(1);
    bool ans = false;
    for (int i = 1; i <= matrix1->getWidth(); ++i) {
        for (int j = 1; j <= matrix1->getHeight(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }

    ASSERT_EQ(ans, true);
}

TEST(Matrix, TestReturnCol) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 1);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    matrix2->setValue(2, 1, 3);
    *matrix1 = matrix->returnCol(1);
    bool ans = false;
    for (int i = 1; i <= matrix1->getWidth(); ++i) {
        for (int j = 1; j <= matrix1->getHeight(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }

    ASSERT_EQ(ans, true);
}


TEST(Matrix, TestTrasp) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    matrix2->setValue(1, 2, 3);
    matrix2->setValue(2, 1, 2);
    matrix2->setValue(2, 2, 4);
    *matrix1 = matrix->trasp();
    bool ans = false;
    for (int i = 1; i <= matrix1->getWidth(); ++i) {
        for (int j = 1; j <= matrix1->getHeight(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}

TEST(Matrix, TestunderScale) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(1, 1);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 1);
    *matrix1 = matrix->underScale(1, 1);
    bool ans = false;
    for (int i = 1; i <= matrix1->getWidth(); ++i) {
        for (int j = 1; j <= matrix1->getHeight(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}

TEST(Matrix, TestOperatorMultpl) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp3 = new MatrixStyle<int>();
    Matrix<int> *matrix3 = mtp->choiceMatrixType(2, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 7);
    matrix2->setValue(1, 2, 10);
    matrix2->setValue(2, 1, 15);
    matrix2->setValue(2, 2, 22);
    matrix3->setValue(1, 1, 1);
    matrix3->setValue(1, 2, 2);
    matrix3->setValue(2, 1, 3);
    matrix3->setValue(2, 2, 4);
    *matrix1 = (*matrix) * (*matrix3);
    bool ans = false;
    for (int i = 1; i <= matrix1->getWidth(); ++i) {
        for (int j = 1; j <= matrix1->getHeight(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}

TEST(Matrix, TestOperatorMultplAdd) {
    MatrixDesigner<int> *mtp = new MatrixStyle<int>();
    Matrix<int> *matrix = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp1 = new MatrixStyle<int>();
    Matrix<int> *matrix1 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp2 = new MatrixStyle<int>();
    Matrix<int> *matrix2 = mtp->choiceMatrixType(2, 2);
    MatrixDesigner<int> *mtp3 = new MatrixStyle<int>();
    Matrix<int> *matrix3 = mtp->choiceMatrixType(2, 2);
    matrix->setValue(1, 1, 1);
    matrix->setValue(1, 2, 2);
    matrix->setValue(2, 1, 3);
    matrix->setValue(2, 2, 4);
    matrix2->setValue(1, 1, 2);
    matrix2->setValue(1, 2, 4);
    matrix2->setValue(2, 1, 6);
    matrix2->setValue(2, 2, 8);
    matrix3->setValue(1, 1, 1);
    matrix3->setValue(1, 2, 2);
    matrix3->setValue(2, 1, 3);
    matrix3->setValue(2, 2, 4);
    *matrix1 = (*matrix) + (*matrix3);
    bool ans = false;
    for (int i = 1; i <= matrix1->getWidth(); ++i) {
        for (int j = 1; j <= matrix1->getHeight(); ++j) {
            if (matrix1->getValue(i, j) != matrix2->getValue(i, j)) {
                ans = false;
                ASSERT_EQ(ans, true);
            } else
                ans = true;
        }
    }
    ASSERT_EQ(ans, true);
}