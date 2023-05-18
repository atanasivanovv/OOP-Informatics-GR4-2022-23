#include <iostream>
#include <cstring>
#include <fstream>
class BaseClass {
protected:
    char* name;
    int size = 0;
private:
    void copy (const BaseClass& other) {
        this->size = other.size;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
public:

    BaseClass() {
        name = new char[8];
        std::cout << "Default\n";
    }

    BaseClass(const BaseClass& other) {
        this->copy(other);
        std::cout << "Copy\n";
    }

    BaseClass(const char* name) {
        this->size = strlen(name);
        this->name = new char[this->size + 1];
        strcpy(this->name, name);
        std::cout << "Constructor\n";
    }

    BaseClass& operator=(const BaseClass& other) {
        if (this != &other) {
            std::cout << "Operator =\n";
            delete [] this->name;
            this->copy(other);
        }
        return *this;
    }

    ~BaseClass() {
        std::cout << "Destructor\n";
        delete [] this->name;
    }
};

class DerivedClass : public BaseClass {
    int age;
public:
    DerivedClass() {
        age = 0;
    }

    DerivedClass(const char* name, int age) : BaseClass(name) {
        this -> age;
    }
};

#include<iostream>
using namespace std;
class Person {
protected:
    int x;
public:
    Person() {
        this->x = 0;
    }
    Person(int x)  { 
        this->x = x;
        std::cout << "Person::Person(int ) called" << endl;   
    }

    void printX() {
        std::cout << this->x;
    }
}; 
  
class Assistant : virtual public Person {
public:
    Assistant() {}
    Assistant(int x):Person(x)   {
       cout<<"Faculty::Faculty(int ) called"<< endl;
    }
};
  
class Student : virtual public Person {
public:
    Student() {}
    Student(int x):Person(x) {
        cout<<"Student::Student(int ) called"<< endl;
    }
};
  
class SuperPerson : public Assistant, public Student  {
public:
    SuperPerson(int x): Person(x) {
        cout<<"SuperPerson::SuperPerson(int ) called"<< endl;
        std::cout << this->x;
    }
};
int main()
{
    // DerivedClass derivedClass("Ivo", 22);
    // DerivedClass derivedClass2(derivedClass);
    // DerivedClass derivedClass3 = derivedClass2;

    // derivedClass2 = derivedClass;
    int x = 5;
    int x2 = 255;
    int x3 = 256;
    std::ofstream ofstr("file.bin", std::ios::binary);
    ofstr.write((const char*)& x, sizeof(int));
    ofstr.write((const char*)& x2, sizeof(int));
    ofstr.write((const char*)& x3, sizeof(int));

    SuperPerson ta1(30);
    ta1.printX();

}