#include "Vector.h"

void Vector::erase() {
    delete [] data;
}

void Vector::copy(const Vector& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[other.capacity];

    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void Vector::resize() {
    capacity *= 2;
    
    int* dataBuffer = new int[capacity];
    for (size_t i = 0; i < size; i++) {
        dataBuffer[i] = data[i];
    }

    delete [] data;
    data = dataBuffer;
}

Vector::Vector() : capacity(8), size(0), data(new int[8]) {
    std::cout << "Hello new Vector!" << std::endl;
}

Vector::Vector(const Vector& other) {
    copy(other);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Vector::~Vector() {
    erase();
}

void Vector::pushBack(int newElement) {
    if (size == capacity) {
        resize();
    }

    data[size++] = newElement;
}

int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw 5;
        // throw "OUT OF BOUNDS!";
    }
    return data[index];
}

// const int& Vector::operator[](int index) const {
//     return data[index];
// }




