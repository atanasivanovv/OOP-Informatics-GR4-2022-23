#include "vector/Vector.h"

int main() {
    Vector v;
    v.pushBack(5);
        // std::cout << v[56];

    try {
        std::cout << v[56];
    }
    catch (const int& num) {
        std::cerr << "THERE WAS A SECOND ERROR BUT PROGRAM STILL WORKING!";
    } catch (...) {
        std::cout << "THERE WAS AN ERROR BUT PROGRAM STILL WORKING!";
    } 

    // Implement String as well :)
}