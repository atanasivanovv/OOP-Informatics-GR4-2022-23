#include "Person.h"

Person::Person() {
    name = new char[10];
    strcpy(name, "Ivo_555");
    age = 18;
}

void Person::printPerson() {
    std::cout << "PERSON DATA:" << std::endl;
    std::cout << this;
    std::cout << name << std::endl;
}

// const char* Person::someWeirdMethod(const char* name) const {

// }

const char* Person::getName() const {
    return name;
}

void Person::setName(const char* otherName) {
    strcpy(this->name, otherName);
}

bool Person::comparePersonAge(const Person& other) const {
    // DO NOT DO THIS (when logic is this simple)
    // if (this->age == other.age) {
    //     return true;
    // } else {
    //     return false;
    // }

    return this->age == other.age;
}

const Person& Person::getReferenceToSelf() {
    return *this;
}

bool Person::operator==(const Person& other) const {
    bool areNamesEqual = strcmp(this->name, other.name) == 0;
    bool areAgesEqual = this->age == other.age;
    // can be done without declaring 2 
    // booleans and can be better for performance
    return areNamesEqual && areAgesEqual;
}

Person::~Person() {
    delete[] name;
}

Person::Person(const Person& other) {
    this->age = other.age;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

Person& Person::operator=(const Person& other) {
    if (this == &other) {
        delete [] this->name;

        this->age = other.age;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }

    return *this;
}