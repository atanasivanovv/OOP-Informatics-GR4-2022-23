#pragma once
#include <iostream>
#include <cstring>

// Example with dynamic stuff
class Student {
    private:
    char* name;

    private:
    void copy(const Student& other);
    void erase();
    
    public:
    Student();
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    public:
    void setName(const char* name);
    const char* getName () const;

    public:
    void writeStudentBinary(std::ofstream& outFile);
    void readStudentBinary(std::ifstream& outFile);
};