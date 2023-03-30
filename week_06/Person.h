#pragma once
#include <iostream>
#include <cstring>

class Person {
    private:
    char* name;
    int age;
    
    public:
    Person();

    Person(const Person& person);
    ~Person();
    Person& operator=(const Person& other);
    void printPerson();
    // const char* someWeirdMethod(const char* name);

    const char* getName() const;
    void setName(const char* otherName);
    bool comparePersonAge(const Person& other) const;
    const Person& getReferenceToSelf();
    bool operator==(const Person& person) const;
};