#include <iostream>               // Input and output

class Vehicle {                   // Base class
public:
    virtual void move() const {   // Virtual function
        std::cout << "Vehicle is moving\n"; // Display message
    }

    virtual ~Vehicle() = default; // Virtual destructor
};

class Car : public Vehicle {      // Car class
public:
    void move() const override {  // Override function
        std::cout << "Car moves on roads\n"; // Display message
    }
};

class Boat : public Vehicle {     // Boat class
public:
    void move() const override {  // Override function
        std::cout << "Boat moves on water\n"; // Display message
    }
};

int main() {                      // Main function
    Car car;                      // Create car
    Boat boat;                    // Create boat

    car.move();                   // Call car function
    boat.move();                 // Call boat function

    return 0;                     // End program
}
