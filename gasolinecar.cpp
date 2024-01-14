// gasolinecar.cpp
#include "gasolinecar.h"
#include <iostream>

GasolineCar::GasolineCar() : Automobile(), fuelTankCapacity(0) {
    std::cout << "GasolineCar default constructor called.\n";
}

GasolineCar::GasolineCar(const char* body, const char* transmission, int power, const char* equipment, const char* vin, int fuelTankCapacity)
    : Automobile("Gasoline", body, transmission, power, equipment, vin), fuelTankCapacity(fuelTankCapacity) {
    std::cout << "GasolineCar parameterized constructor called.\n";
}

GasolineCar::~GasolineCar() {
    std::cout << "GasolineCar destructor called.\n";
}

void GasolineCar::printInfo() const {
    Automobile::printInfo();
    std::cout << "Fuel Tank Capacity: " << fuelTankCapacity << " liters\n";
}

GasolineCar::GasolineCar(const GasolineCar& other)
    : Automobile(other), fuelTankCapacity(other.fuelTankCapacity) {
    std::cout << "GasolineCar copy constructor called.\n";
}

GasolineCar& GasolineCar::operator=(const GasolineCar& other) {
    if (this != &other) {
        Automobile::operator=(other);
        fuelTankCapacity = other.fuelTankCapacity;
    }

    std::cout << "GasolineCar copy assignment operator called.\n";
    return *this;
}

GasolineCar::GasolineCar(GasolineCar&& other) noexcept
    : Automobile(std::move(other)), fuelTankCapacity(other.fuelTankCapacity) {
    other.fuelTankCapacity = 0;

    std::cout << "GasolineCar move constructor called.\n";
}

GasolineCar& GasolineCar::operator=(GasolineCar&& other) noexcept {
    if (this != &other) {
        Automobile::operator=(std::move(other));
        fuelTankCapacity = other.fuelTankCapacity;
        other.fuelTankCapacity = 0;
    }

    std::cout << "GasolineCar move assignment operator called.\n";
    return *this;
}
