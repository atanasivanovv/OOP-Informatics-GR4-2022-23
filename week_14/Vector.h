#pragma once
#include <iostream>
#include <iterator>
#include <fstream>

template <typename I>
class Vector {
private:
    size_t capacity;
    size_t size;
    I* data;
private:
    void copy(const Vector&);
    void erase();
    void resize();
public:
    Vector();
    Vector(const Vector&);
    Vector(const I*, I);
    Vector(Vector&&);
    Vector& operator=(const Vector&);
    ~Vector();
public:
    void printVector() const;
    size_t getSize() const {
        return this->size;
    }
public:
    I& operator[](I index);
    // const I& operator[](I index) const;
    // operator+ (adds new veector data to our vector)
    // oprator+= (adds new vector data to our vector and returns our vector reference)
    // operator== (checks if vectors are same)
    // pop (removes last element)
    // pushFront
    // popFront
    // sort
    void pushBack(I);

	friend std::ostream& operator<<(std::ostream& out, const Vector<I>& other) {
        out << "[";
        for (size_t i = 0; i < other.size; i++) {
            out << other.data[i] << " ";
        }   
        out << "\b]";
        out << std::endl;

        return out;
    };
};

template <typename I>
void Vector<I>::erase() {
    delete [] data;
}

template <typename I>
void Vector<I>::copy(const Vector<I>& other) {
    capacity = other.capacity;
    size = other.size;
    data = new I[other.capacity];

    for (size_t i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <typename I>
void Vector<I>::resize() {
    capacity *= 2;
    
    I* dataBuffer = new I[capacity];
    for (size_t i = 0; i < size; i++) {
        dataBuffer[i] = data[i];
    }

    delete [] data;
    data = dataBuffer;
}

template <typename I>
Vector<I>::Vector() : capacity(8), size(0), data(new I[8]) {
    // std::cout << "Hello new Vector!" << std::endl;
}

template <typename I>
Vector<I>::Vector(const I* someData, I size) {
    this->capacity = size * 2;
    this->size = 0;
    this->data = new I[size * 2];

    for (size_t i = 0; i < size; i++) {
        I newElement = someData[i];
        this->data[this->size++] = someData[i];
    }
}

template <typename I>
Vector<I>::Vector(Vector<I>&& other) {
    std::cout << "MOVED!\n";
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = other.data; // assigning the poIer!

    // clean other instance (create hollow object)
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename I>
Vector<I>::Vector(const Vector<I>& other) {
    std::cout << "COPIED!\n";
    copy(other);
}

template <typename I>
Vector<I>& Vector<I>::operator=(const Vector<I>& other) {
    if (this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

template <typename I>
Vector<I>::~Vector() {
    erase();
}

template <typename I>
void Vector<I>::pushBack(I newElement) {
    if (size == capacity) {
        resize();
    }

    data[size++] = newElement;
}

template <typename I>
void Vector<I>::printVector() const {
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << this->data[i] << " ";
    }   
    std::cout << "\b]";
    std::cout << std::endl;
}

template <typename I>
I& Vector<I>::operator[](I index) {
    if (index < 0 || index >= size) {
        throw 5;
        // throw "OUT OF BOUNDS!";
    }
    return data[index];
}