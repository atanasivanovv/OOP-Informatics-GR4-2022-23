#include <iostream>
#include <cstring>
#include "./moveString/String.h"

class Vehicle {
protected:
    String brand;
    String model;
    int kmPassed;
    int horsePower; 
    int seats;
public:
    Vehicle() {
        kmPassed = 0;
        horsePower = 0;
        seats = 0;
    }
    
    Vehicle(String brand, String model, int kmPassed, int horsePower, int seats) {
        this->brand = brand;
        this->model = model;
        this->kmPassed = kmPassed;
        this->horsePower = horsePower;
        this->seats = seats;
    }
    void startEngine() {
        std::cout << "STARTING NITRO!\n";
    }
};

class Van : public Vehicle {
    int additionalSeats;
    int roofSpace;

    public:
    Van(String brand, String model, int kmPassed, int horsePower, int seats, int additionalSeats, int roofSpace)
     : Vehicle(brand, model, kmPassed, horsePower, seats), additionalSeats(additionalSeats), roofSpace(roofSpace) {
    }

    Van(int additionalSeats, int roofSpace) : additionalSeats(additionalSeats), roofSpace(roofSpace) {
    }

    void openBackdoor () {
        std::cout << "OPEN BACKDOOR!\n";
    }
};

class RaceCar : public Vehicle {
public:
    // using Vehicle::Vehicle;
    void startNitro() {
        std::cout << "STARTING NITRO!\n";
    }
};
class RaceVan : public Van, public RaceCar {
public:
    // using Vehicle::Vehicle;
};

int main() {
}