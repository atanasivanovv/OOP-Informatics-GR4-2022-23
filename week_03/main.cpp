#include <iostream>
#include <fstream>

int main () {
    // std::ofstream outFile("rawsentence.txt");

    // if (outFile.is_open()) {
    //     // std::cout << outFile.tellp() << std::endl;
    //     outFile << "ABCD";
        
    //     // outFile.seekp(2, std::ios::end);
    //     // std::cout << outFile.tellp() << std::endl;
    //     outFile.close();
    // }

    std::ifstream inFile("rawsentence.txt");
    std::ofstream parsedFile("parsedsentece.txt");

    if (inFile.is_open()) {
        char symbol = ' ';
        while (!inFile.eof()) {
            int positionInFile = (int) inFile.tellg() + 1;
            symbol = inFile.get();

            if (positionInFile % 2 == 0) {
                parsedFile << symbol;
            }
        }

        // char sentence[100];
        // while (!inFile.eof()) {
        //     inFile.getline(sentence, 100);
        //     std::cout << sentence << std::endl;
        // }
    }
    


    return 0;
}