// gasolinecar.h
#pragma once
#ifndef GASOLINECAR_H
#define GASOLINECAR_H
#include <iostream>
#include "automobile.h"

class GasolineCar : public Automobile {
public:
    GasolineCar();
    GasolineCar(const char* body, const char* transmission, int power, const char* equipment, const char* vin, int fuelTankCapacity);
    ~GasolineCar();

    void printInfo() const override;

    // Rule of Three
    GasolineCar(const GasolineCar& other);
    GasolineCar& operator=(const GasolineCar& other);

    // Rule of Five
    GasolineCar(GasolineCar&& other) noexcept;
    GasolineCar& operator=(GasolineCar&& other) noexcept;

private:
    int fuelTankCapacity;
};

#endif // GASOLINECAR_H
