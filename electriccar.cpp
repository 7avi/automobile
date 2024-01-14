// electriccar.cpp
#include "electriccar.h"
#include <iostream>

ElectricCar::ElectricCar() : Automobile(), batteryCapacity(0) {
    std::cout << "ElectricCar default constructor called.\n";
}

ElectricCar::ElectricCar(const char* body, const char* transmission, int power, const char* equipment, const char* vin, int batteryCapacity)
    : Automobile("Electric", body, transmission, power, equipment, vin), batteryCapacity(batteryCapacity) {
    std::cout << "ElectricCar parameterized constructor called.\n";
}

ElectricCar::~ElectricCar() {
    std::cout << "ElectricCar destructor called.\n";
}

void ElectricCar::printInfo() const {
    Automobile::printInfo();
    std::cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
}

ElectricCar::ElectricCar(const ElectricCar& other)
    : Automobile(other), batteryCapacity(other.batteryCapacity) {
    std::cout << "ElectricCar copy constructor called.\n";
}

ElectricCar& ElectricCar::operator=(const ElectricCar& other) {
    if (this != &other) {
        Automobile::operator=(other);
        batteryCapacity = other.batteryCapacity;
    }

    std::cout << "ElectricCar copy assignment operator called.\n";
    return *this;
}

ElectricCar::ElectricCar(ElectricCar&& other) noexcept
    : Automobile(std::move(other)), batteryCapacity(other.batteryCapacity) {
    other.batteryCapacity = 0;

    std::cout << "ElectricCar move constructor called.\n";
}

ElectricCar& ElectricCar::operator=(ElectricCar&& other) noexcept {
    if (this != &other) {
        Automobile::operator=(std::move(other));
        batteryCapacity = other.batteryCapacity;
        other.batteryCapacity = 0;
    }

    std::cout << "ElectricCar move assignment operator called.\n";
    return *this;
}

