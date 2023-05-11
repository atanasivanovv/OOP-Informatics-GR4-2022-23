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

Vector::Vector(const int* someData, int size) {
    this->capacity = size * 2;
    this->size = 0;
    this->data = new int[size * 2];

    for (size_t i = 0; i < size; i++) {
        int newElement = someData[i];
        this->data[this->size++] = someData[i];
    }
}

Vector::Vector(Vector&& other) {
    std::cout << "MOVED!\n";
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = other.data; // assigning the pointer!

    // clean other instance (create hollow object)
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Vector::Vector(const Vector& other) {
    std::cout << "COPIED!\n";
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

void Vector::printVector() const {
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << this->data[i] << " ";
    }   
    std::cout << "\b]";
    std::cout << std::endl;
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




