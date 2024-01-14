// automobile.cpp
#include "automobile.h"

Automobile::Automobile() : fuel(nullptr), body(nullptr), transmission(nullptr), power(0), equipment(nullptr), vin(nullptr) {
    std::cout << "Base class default constructor called.\n";
}

Automobile::Automobile(const char* fuel, const char* body, const char* transmission, int power, const char* equipment, const char* vin)
    : fuel(fuel), body(body), transmission(transmission), power(power), equipment(equipment), vin(vin) {
    std::cout << "Base class parameterized constructor called.\n";
}

Automobile::~Automobile() {
    std::cout << "Base class destructor called.\n";
}

void Automobile::printInfo() const {
    std::cout << "Fuel: " << fuel << "\nBody: " << body << "\nTransmission: " << transmission << "\nPower: " << power
        << "\nEquipment: " << equipment << "\nVIN: " << vin << "\n";
}
