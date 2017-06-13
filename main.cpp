#include <iostream>
#include "ValoMatrix.h"
using namespace std;
int main() {

    ValoMatrix <int> A (3,2);
    ValoMatrix <int> B (3,2);
    A.setValue(1,2,8);
    int v = A.getValue(1,2);
    cout<<v<<endl;
    ValoMatrix <int> C = A.prod(B);
    int w = C.getWidth();
    int h = C.getHeight();
    for (int i = 0; i < w ; i++) {
        for (int j = 0; j < h ; j++) {
            cout<<C.getValue(i,j)<< endl;
        }
    }
      std::cout << "Hello, World!" << std::endl;
    return 0;
}