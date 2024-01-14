// automobile.h
#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>

class Automobile {
public:
    Automobile();
    Automobile(const char* fuel, const char* body, const char* transmission, int power, const char* equipment, const char* vin);
    virtual ~Automobile();

    virtual void printInfo() const;

private:
    const char* fuel;
    const char* body;
    const char* transmission;
    int power;
    const char* equipment;
    const char* vin;
};

#endif // AUTOMOBILE_H
