// automobile.h

#pragma once
#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include <stdexcept>

class Automobile {
public:
    Automobile();
    Automobile(const char* fuel, const char* body, const char* transmission, int power, const char* equipment, const char* vin);
    virtual ~Automobile();

    void printInfo() const;

    // Metode pentru "Rule of Three" ?i "Rule of Five"
    Automobile(const Automobile& other);
    Automobile& operator=(const Automobile& other);
    Automobile(Automobile&& other) noexcept;
    Automobile& operator=(Automobile&& other) noexcept;

    // Metod? pentru limitarea num?rului de obiecte la 1
    static void setInstanceCreated(bool value);

    virtual void printInfo() const = 0;

protected:
    const char* fuel;
    const char* body;
    const char* transmission;
    int power;
    const char* equipment;
    const char* vin;

private:
    // Membru static pentru a ține evidența dacă un obiect a fost creat
    static bool instanceCreated;
};

class ElectricCar : public Automobile {
public:
    ElectricCar();
    ElectricCar(const char* body, const char* transmission, int power, const char* equipment, const char* vin, int batteryCapacity);
    ~ElectricCar();

    void printInfo() const override;

    // Rule of Three
    ElectricCar(const ElectricCar& other);
    ElectricCar& operator=(const ElectricCar& other);
    ElectricCar(ElectricCar&& other) noexcept;
    ElectricCar& operator=(ElectricCar&& other) noexcept;

private:
    int batteryCapacity;
};

class GasolineCar : public Automobile {
public:
    GasolineCar();
    GasolineCar(const char* body, const char* transmission, int power, const char* equipment, const char* vin, int fuelTankCapacity);
    ~GasolineCar();

    void printInfo() const override;
    // Rule of Three
    GasolineCar(const GasolineCar& other);
    GasolineCar& operator=(const GasolineCar& other);
    GasolineCar(GasolineCar&& other) noexcept;
    GasolineCar& operator=(GasolineCar&& other) noexcept;

private:
    int fuelTankCapacity;
};

#endif // AUTOMOBILE_H