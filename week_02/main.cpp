#include <iostream>
#include <cstring>
#include <fstream>

struct Car {
    enum MONTH {JANUARY = 1, FEBRUARY};
    
    int maxKilometers: 1;
    int avarageWaste = 10;
    char model[20];
    char description[20];
    MONTH monthOfRelease = JANUARY;

    void printCar() {
        std::cout << "CAR DATA:\n";
        std::cout << maxKilometers << std::endl;
        std::cout << avarageWaste << std::endl;
        switch (monthOfRelease) {
            case JANUARY: std::cout << "Released in JANUARY" << std::endl; break;
            default: std::cout << "No release data added!" << std::endl;
        }
    }

};

struct Icecream {
    enum FLAVOUR {CHOCOLATE, VANILLA, CREAM, STRAWBERRY};

    struct Icecream2 {

    };

    Icecream2 icecream2;
};

int main() {
    Car car1;
    car1.maxKilometers = 1;
    for (size_t i = 0; i < 100; i++) {
        car1.maxKilometers++;
        std::cout << car1.maxKilometers << std::endl;
    }
    

    Car car2;
    // car2.maxKilometers = 200;
    car2.printCar();
}