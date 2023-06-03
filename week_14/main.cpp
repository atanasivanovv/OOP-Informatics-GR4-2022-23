#include <iostream>
#include <functional>
#include "MyTempClass.h"
#include "Vector.h"

template <typename T>
inline void swap(T& first, T& second) {
    T temp = first;
    first = second;
    second = temp;
}

int main() {   
    int a = 5;
    int b = 10;

    double c = 5.0;
    double d = 6.0;

    swap <int> (a, b);
    
    int f = 5;
    int* f_p = &f;
    MyTempClass <int> myTempObject(*f_p);

    Vector<int> myVector;
    myVector.pushBack(5);
    myVector.pushBack(5.0);
    
    Vector<Vector<int>> matrix;
    matrix.pushBack(myVector);
    matrix.pushBack(myVector);

    matrix.printVector();
}     