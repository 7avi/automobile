// automobile.cpp
#include <cstdlib> // Pentru a include declarația de malloc și free
#include "automobile.h"
#include <iostream>
#include <cstring>

bool Automobile::instanceCreated = false;

Automobile::~Automobile() {
    delete[] fuel;
    delete[] body;
    delete[] transmission;
    delete[] equipment;
    delete[] vin;
    std::cout << "Base class destructor called.\n";
}



// Implementări pentru clasa Automobile


Automobile::Automobile() : fuel(nullptr), body(nullptr), transmission(nullptr), power(0), equipment(nullptr), vin(nullptr) {
    if (instanceCreated) {
        throw std::logic_error("Only one instance of Automobile is allowed.");
    }

    instanceCreated = true;

    std::cout << "Base class default constructor called.\n";
}


Automobile::Automobile(const char* fuel, const char* body, const char* transmission, int power, const char* equipment, const char* vin)
    : fuel(fuel), body(body), transmission(transmission), power(power), equipment(equipment), vin(vin) {
    if (instanceCreated) {
        throw std::logic_error("Only one instance of Automobile is allowed.");
    }

    instanceCreated = true;

    std::cout << "Base class parameterized constructor called.\n";
}


Automobile::~Automobile() {
    std::cout << "Base class destructor called.\n";
}

void Automobile::printInfo() const {
    std::cout << "Fuel: " << fuel << "\nBody: " << body << "\nTransmission: " << transmission << "\nPower: " << power
        << "\nEquipment: " << equipment << "\nVIN: " << vin << "\n";
}

// Implementări pentru "Rule of Three" și "Rule of Five" în clasa Automobile
Automobile::Automobile(const Automobile& other)
    : fuel(other.fuel ? strdup(other.fuel) : nullptr),
    body(other.body ? strdup(other.body) : nullptr),
    transmission(other.transmission ? strdup(other.transmission) : nullptr),
    power(other.power),
    equipment(other.equipment ? strdup(other.equipment) : nullptr),
    vin(other.vin ? strdup(other.vin) : nullptr) {
    std::cout << "Base class copy constructor called.\n";
}

Automobile& Automobile::operator=(const Automobile& other) {
    if (this != &other) {
        delete[] fuel;
        delete[] body;
        delete[] transmission;
        delete[] equipment;
        delete[] vin;

        fuel = other.fuel ? strdup(other.fuel) : nullptr;
        body = other.body ? strdup(other.body) : nullptr;
        transmission = other.transmission ? strdup(other.transmission) : nullptr;
        power = other.power;
        equipment = other.equipment ? strdup(other.equipment) : nullptr;
        vin = other.vin ? strdup(other.vin) : nullptr;

    }

    std::cout << "Base class copy assignment operator called.\n";
    return *this;
}


Automobile::Automobile(Automobile&& other) noexcept
    : fuel(other.fuel), body(other.body), transmission(other.transmission),
    power(other.power), equipment(other.equipment), vin(other.vin) {
    other.fuel = nullptr;
    other.body = nullptr;
    other.transmission = nullptr;
    other.equipment = nullptr;
    other.vin = nullptr;

    std::cout << "Base class move constructor called.\n";
}

Automobile& Automobile::operator=(Automobile&& other) noexcept {
    if (this != &other) {
        delete[] fuel;
        delete[] body;
        delete[] transmission;
        delete[] equipment;
        delete[] vin;

        fuel = strdup(other.fuel);
        body = strdup(other.body);
        transmission = strdup(other.transmission);
        power = other.power;
        equipment = strdup(other.equipment);
        vin = strdup(other.vin);

    }

    std::cout << "Base class move assignment operator called.\n";
    return *this;
}

// Implementări pentru clasa ElectricCar

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

// Implementări pentru "Rule of Three" și "Rule of Five" în clasa ElectricCar
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

// Implementări pentru clasa GasolineCar

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

// Metoda pentru limitarea numărului de obiecte la 1
void Automobile::setInstanceCreated(bool value) {
    instanceCreated = value;
}