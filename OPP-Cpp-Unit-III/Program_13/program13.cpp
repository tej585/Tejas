#include <iostream>                         // Input and output

class Base {                                // Define base class
public:
    virtual ~Base() {                       // Virtual destructor
        std::cout << "Base destructor\n";   // Display message
    }
};

class Derived : public Base {               // Define derived class
public:
    ~Derived() override {                   // Override destructor
        std::cout << "Derived destructor\n"; // Display message
    }
};

int main() {                                // Main function
    Base* pointer = new Derived();          // Create derived object

    delete pointer;                         // Delete through base pointer

    return 0;                               // End program
}
