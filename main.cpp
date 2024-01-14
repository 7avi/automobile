#include "automobile.h"
#include "util.h"
#include "electriccar.h"
#include "gasolinecar.h"
#include <iostream>

int main() {
    try {
        std::cout << "Creating an ElectricCar:\n";
        ElectricCar electricCar("Sedan", "Automatic", 150, "Standard Equipment", "ABC123", 60);
        std::cout << "\nCreating a GasolineCar:\n";
        GasolineCar gasolineCar("SUV", "Manual", 200, "Premium Equipment", "XYZ789", 70);

        std::cout << "\nCalling printInfo() for ElectricCar:\n";
        electricCar.printInfo();

        std::cout << "\nCalling printInfo() for GasolineCar:\n";
        gasolineCar.printInfo();

        // Utilizarea funcțiilor statice din clasa Util
        Util::printCustomMessage("This is a custom message.");

        double average = Util::calculateAverage(10, 20);
        std::cout << "Average: " << average << std::endl;

        Util::printAutomobileInfo(electricCar);

        std::cout << "\nTesting Rule of Three and Rule of Five:\n";

        // Copy constructor
        ElectricCar electricCarCopy = electricCar;
        GasolineCar gasolineCarCopy = gasolineCar;

        // Copy assignment operator
        ElectricCar electricCarCopyAssign;
        electricCarCopyAssign = electricCarCopy;
        GasolineCar gasolineCarCopyAssign;
        gasolineCarCopyAssign = gasolineCarCopy;

        // Move constructor
        ElectricCar electricCarMoved = std::move(electricCar);
        GasolineCar gasolineCarMoved = std::move(gasolineCar);

        // Move assignment operator
        ElectricCar electricCarMoveAssign;
        electricCarMoveAssign = std::move(electricCarMoved);
        GasolineCar gasolineCarMoveAssign;
        gasolineCarMoveAssign = std::move(gasolineCarMoved);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
