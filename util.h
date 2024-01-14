// util.h
#ifndef UTIL_H
#define UTIL_H

#include "automobile.h"

class Util {
public:
    static void printCustomMessage(const char* message);
    static double calculateAverage(int a, int b);
    static void printAutomobileInfo(const Automobile& automobile);
};

#endif
