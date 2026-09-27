#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class Vehicle {                   // Base class
protected:
    std::string registrationNumber; // Store registration

public:
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {} // Initialize registration

    void start() const {          // Start vehicle
        std::cout << "Vehicle " << registrationNumber
                  << " started\n"; // Display message
    }
};

class Car : public Vehicle {      // Derived car class
public:
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {} // Initialize base

    void openBoot() const {       // Open car boot
        std::cout << "Car boot opened\n"; // Display message
    }
};

class Bike : public Vehicle {     // Derived bike class
public:
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {} // Initialize base

    void helmetReminder() const { // Helmet reminder
        std::cout << "Please wear a helmet\n"; // Display message
    }
};

int main() {                      // Main function
    Car car("MH14EF2468");        // Create car
    Bike bike("MH14GH1357");      // Create bike

    car.start();                  // Start car
    car.openBoot();               // Open boot

    bike.start();                 // Start bike
    bike.helmetReminder();        // Show reminder

    return 0;                     // End program
}
