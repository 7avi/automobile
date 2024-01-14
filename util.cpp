// util.cpp
#include "util.h"

void Util::printCustomMessage(const char* message) {
    std::cout << "Custom Message: " << message << std::endl;
}

double Util::calculateAverage(int a, int b) {
    return static_cast<double>(a + b) / 2.0;
}

void Util::printAutomobileInfo(const Automobile& automobile) {
    std::cout << "Printing Automobile Information:\n";
    automobile.printInfo();
}
