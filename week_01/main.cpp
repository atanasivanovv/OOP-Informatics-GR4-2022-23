#include <iostream>
#include <cstring>

void strtrim(char* str) {
    int count = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' ')) {
            str[count++] = str[i];
        }
    }

    str[count - 1] = '\0';
}

char getUpperCase(char symbol) {
    if (symbol >= 'a' && symbol <= 'z') {
        return symbol -= 32;
    }

    return symbol;
}

bool areSymbolsEqual(char firstSymbol, char secondSymbol) {
    return getUpperCase(firstSymbol) == getUpperCase(secondSymbol);
}

bool areEqual(char* firstStr, char* secondStr) {
    bool areNotEqual = *firstStr == '\0' && *secondStr != '\0' ||
            *secondStr == '\0' && *firstStr != '\0' || 
            !areSymbolsEqual(*firstStr, *secondStr);

    if (areNotEqual) { 
        return false;
    }

    bool canEnd = *firstStr == '\0' && *secondStr == '\0';
 
    return canEnd || areEqual(firstStr + 1, secondStr + 1);
}

void printArr(int* arr, int size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void resizeArray(int *&arr, int sizeOfArray) {
    int* resizedArray = new int[sizeOfArray * 2];

    for (size_t i = 0; i < sizeOfArray; i++) {
        resizedArray[i] = arr[i];
    }
    delete [] arr;
    arr = resizedArray;
}

void pushBack(int *&arr, int& sizeOfArr, int capacity, int element) {
    if (sizeOfArr == capacity) {
        resizeArray(arr, sizeOfArr);
    }
    arr[sizeOfArr++] = element;
}

void pushFront(int *&arr, int& sizeOfArr, int capacity, int element) {
    if (sizeOfArr == capacity) {
        resizeArray(arr, sizeOfArr);
    }

    for (size_t i = sizeOfArr + 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    sizeOfArr++;
    arr[0] = element;
}

int main() {
    test1.x = 666;
    test1.printX();
}
