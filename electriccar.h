// electriccar.h
#pragma once
#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "automobile.h"

class ElectricCar : public Automobile {
public:
    ElectricCar();
    ElectricCar(const char* body, const char* transmission, int power, const char* equipment, const char* vin, int batteryCapacity);
    ~ElectricCar();

    void printInfo() const override;

    // Rule of Three
    ElectricCar(const ElectricCar& other);
    ElectricCar& operator=(const ElectricCar& other);

    // Rule of Five
    ElectricCar(ElectricCar&& other) noexcept;
    ElectricCar& operator=(ElectricCar&& other) noexcept;

private:
    int batteryCapacity;
};

#endif // ELECTRICCAR_H
