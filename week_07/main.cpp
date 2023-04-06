#include <iostream>
#include <cstring>
#include "Student.h"
int main () {
    int* reallyBigArray = new(std::nothrow) int[3213];
    int numberCheck = 0;

    Student student1;
    student1.setName("Sasho");

    Student student2(student1);
}