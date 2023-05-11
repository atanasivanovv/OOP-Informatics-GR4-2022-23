#pragma once
#include <iostream>
#include <cstring>
class String
{
    char *data;
    size_t size;

public:
    String();
    String(const char *data);
    String& operator=(const String& other);
    String(const String &other);
    String(String &&other);
    ~String();

    void printData();
};

// class Person
// {
//     String name;

// public:
//     Person(const String &otherName) : name(otherName) {}
//     Person(String &&otherName) : name(std::move(otherName)){};
//     // Person(String &&otherName) : name((String&&) otherName){};
// };