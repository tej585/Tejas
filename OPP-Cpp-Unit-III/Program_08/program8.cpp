#include <iostream>                         // Input and output

class Base {                                // Define base class
public:
    void display() const {                  // Base function
        std::cout << "Base display function\n"; // Display message
    }
};

class Derived : public Base {               // Define derived class
public:
    void display() const {                  // Derived function
        std::cout << "Derived display function\n"; // Display message
    }
};

int main() {                                // Main function
    Derived derivedObject;                  // Create derived object

    Base* basePointer = &derivedObject;     // Base pointer to derived

    basePointer->display();                 // Call base function

    return 0;                               // End program
}
