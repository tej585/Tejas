#include <iostream>               // Input and output

class Base {                      // Base class
public:
    Base() {                      // Base constructor
        std::cout << "Base constructor\n"; // Display message
    }

    ~Base() {                     // Base destructor
        std::cout << "Base destructor\n"; // Display message
    }
};

class Derived : public Base {     // Derived class
public:
    Derived() {                   // Derived constructor
        std::cout << "Derived constructor\n"; // Display message
    }

    ~Derived() {                  // Derived destructor
        std::cout << "Derived destructor\n"; // Display message
    }
};

int main() {                      // Main function
    Derived object;               // Create derived object

    return 0;                     // End program
}
