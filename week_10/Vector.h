#pragma once
#include <iostream>
#include <iterator>
class Vector {
private:
    size_t capacity;
    size_t size;
    int* data;
private:
    void copy(const Vector&);
    void erase();
    void resize();
public:
    Vector();
    Vector(const Vector&);
    Vector(const int*, int);
    Vector(Vector&&);
    Vector& operator=(const Vector&);
    ~Vector();
public:
    void printVector() const;
public:
    int& operator[](int index);
    // const int& operator[](int index) const;
    // operator+ (adds new veector data to our vector)
    // oprator+= (adds new vector data to our vector and returns our vector reference)
    // operator== (checks if vectors are same)
    // pop (removes last element)
    // pushFront
    // popFront
    // sort
    void pushBack(int);
};