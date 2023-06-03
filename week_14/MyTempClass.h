#pragma once

template <typename T>
class MyTempClass {
    T myTempVariable;
    double myNonTempVariable;

    public:
    MyTempClass(T tempVariable);
    void templatePrint();
};

template <typename T>
MyTempClass<T>::MyTempClass(T tempVariable) {
    this->myTempVariable = myTempVariable;
}

template <typename T>
void MyTempClass<T>::templatePrint() {
    std::cout << *myTempVariable << std::endl;
}