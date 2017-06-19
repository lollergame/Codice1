#include <iostream>

#include "MatrixDesigner.h"
#include "MatrixStyle.h"

using namespace std;

int main() {
    try {

        MatrixDesigner<int> *mtp = new MatrixStyle<int>();
        Matrix<int> *matrixxx = mtp->choiceMatrixType(5, 5);
        cout << "lel" << endl;
        matrixxx->printMatrix();


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