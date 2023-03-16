#include <iostream>
#include <fstream>
#include <cstring>

struct IFSTREAM {
    int POINTER_TO_CELL;
};

void writeTextInBinary(std::ofstream& outFile, const char* text) {
    if (outFile.is_open()) {    
        outFile.write(text, strlen(text)); 
        outFile.close();
    }
}

void readEvenSymbolsInBinary(std::ifstream& inFile) {
    std::ofstream newFile("newFile.data", std::ios::binary);

    if (inFile.is_open()) {
        char symbol = ' ';
        while (!inFile.eof()) {
            inFile.read((char*) &symbol, sizeof(char));
            if (inFile.tellg() % 2 == 0) {
                newFile.write((char*) &symbol, sizeof(char));
            }
        }

        inFile.close();
        newFile.close();
    }
}


int main () {
    // std::cout << "Hello world!" << std::endl;

    // std::ofstream outFile("test.data", std::ios::binary);

    // if (outFile.is_open()) {
    //     int test = 1000000;
    //     int test2 = 11;
    //     char test3[50] = "final test";
    //     outFile.write((char*) &test, sizeof(int));
    //     outFile.write((char*) &test2, sizeof(int));
    //     outFile.write((char*) &test3, sizeof(double));

    //     outFile.close(); 
    // }

    // std::ifstream inFile("test.data", std::ios::binary);
    // int testRead;
    // int testRead2;
    // char testRead3[50];
    // if (inFile.is_open()) {
    //     inFile.read((char*) &testRead, sizeof(int));
    //     inFile.read((char*) &testRead2, sizeof(int));
    //     inFile.read((char*) &testRead3, sizeof(char) * 11);
    //     inFile.close();
    // }

    // std::cout << sizeof(char) << std::endl;
    // std::cout << testRead << std::endl;
    // std::cout << testRead2 << std::endl;
    // std::cout << "|" << testRead3 << "|" << std::endl;

    // short test = 1;
    // short test2 = 2;

    // short test3 = test * test2;
    
    // std::cout << sizeof(test * test2) << std::endl;
    // return 0;  

    std::ofstream outFile("test.data", std::ios::binary);
    char test3[50] = "alabala";

    writeTextInBinary(outFile, test3);

    std::ifstream inFile("test.data", std::ios::binary);
    readEvenSymbolsInBinary(inFile);
}