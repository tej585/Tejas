#include <iostream>                         // Input and output

class Base {                                // Define base class
public:
    virtual void display() const {          // Virtual function
        std::cout << "Base object\n";       // Display base
    }

    virtual ~Base() = default;              // Virtual destructor
};

class Derived : public Base {               // Define derived class
public:
    void display() const override {         // Override function
        std::cout << "Derived object\n";    // Display derived
    }
};

void displayByValue(Base object) {          // Receive object by value
    object.display();                       // Call display
}

void displayByReference(const Base& object) { // Receive reference
    object.display();                         // Call display
}

int main() {                                // Main function
    Derived derivedObject;                  // Create derived object

    std::cout << "Passing by value: ";      // Display heading
    displayByValue(derivedObject);          // Pass by value

    std::cout << "Passing by reference: ";  // Display heading
    displayByReference(derivedObject);     // Pass by reference

    return 0;                               // End program
}
