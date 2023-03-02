#include <iostream>
#include <cstring>

void resizeArray(int *& arr, int &size, int &capacity) {
    capacity *= 2;
    int* biggerArray = new int[capacity];

    for (int i = 0; i < size; i++) {
        biggerArray[i] = arr[i];
    }

    delete [] arr;
    arr = biggerArray;
}

void pushBack(int *& arr, int &size, int &capacity, int newElement) {
    if (size == capacity) {
        resizeArray(arr, size, capacity);
    }
    arr[size++] = newElement;
}

void pushFront(int *& arr, int &size, int &capacity, int newElement) {
    if (size == capacity) {
        resizeArray(arr, size, capacity);
    }
    // {1 2, _}
    // shift elements 1 to right {1, 1, 2}
    // insert at index 0 new element {<new element>, 1, 2}
    size++;
}

void printArray(const int size, const int* arr) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}


int main() {   
}
