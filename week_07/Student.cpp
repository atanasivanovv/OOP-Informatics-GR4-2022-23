#include "Student.h"

void Student::copy(const Student& other) {
    setName(other.name);
}

void Student::erase() {
    delete [] name;
}

Student::Student() {
    name = new char[10];
}

Student::Student(const Student& other) {
    copy(other);
}

Student& Student::operator=(const Student& other) {
    if (this == &other) {
        return *this;
    }
    erase();
    copy(other);
    return *this;
}

Student::~Student() {
    erase();
}

void Student::setName(const char* name) {
    delete [] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

const char* Student::getName() const {
    return this->name;
}

void Student::writeStudentBinary(std::ofstream& outFile) {
    
}