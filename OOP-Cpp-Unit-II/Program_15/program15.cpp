#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class Vehicle {                   // Base class
protected:
    std::string registrationNumber; // Store registration
    double ratePerDay;             // Store daily rate

public:
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)),
          ratePerDay(rate) {}      // Initialize values

    virtual double calculateRent(int days) const { // Calculate rent
        return ratePerDay * days;  // Return rent
    }

    virtual void display() const { // Display vehicle
        std::cout << "Registration: "
                  << registrationNumber << '\n'; // Print registration
        std::cout << "Rate per day: "
                  << ratePerDay << '\n'; // Print rate
    }

    virtual ~Vehicle() = default; // Virtual destructor
};

class Car : public Vehicle {      // Car derived class
private:
    int numberOfDoors;             // Store door count

public:
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate),
          numberOfDoors(doors) {}  // Initialize values

    void display() const override { // Override display
        Vehicle::display();         // Display base details
        std::cout << "Doors: "
                  << numberOfDoors << '\n'; // Display doors
    }
};

class Bike : public Vehicle {     // Bike derived class
private:
    int engineCapacity;            // Store engine capacity

public:
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity) {} // Initialize values

    double calculateRent(int days) const override { // Override rent
        return ratePerDay * days * 0.9; // Apply discount
    }

    void display() const override { // Override display
        Vehicle::display();         // Display base details
        std::cout << "Engine Capacity: "
                  << engineCapacity << " cc\n"; // Display engine
    }
};

int main() {                      // Main function
    Car car("MH14JK7392", 2200.0, 4); // Create car
    Bike bike("MH14LM4816", 900.0, 160); // Create bike

    std::cout << "Car Details\n"; // Display heading
    car.display();                // Display car details
    std::cout << "Rent for 4 days: "
              << car.calculateRent(4) << "\n\n"; // Calculate car rent

    std::cout << "Bike Details\n"; // Display heading
    bike.display();                // Display bike details
    std::cout << "Rent for 4 days: "
              << bike.calculateRent(4) << '\n'; // Calculate bike rent

    return 0;                     // End program
}
