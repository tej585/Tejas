#include <iostream>               // Input and output

class Base {                      // Define base class
public:
    void show() const {           // Public function
        std::cout << "Base public function\n"; // Display message
    }
};

class PublicDerived : public Base { // Public inheritance
};

class PrivateDerived : private Base { // Private inheritance
public:
    void callBaseShow() const {      // Public wrapper function
        show();                      // Call base function
    }
};

int main() {                         // Main function
    PublicDerived publicObject;      // Create public-derived object
    publicObject.show();             // Access base function

    PrivateDerived privateObject;    // Create private-derived object
    privateObject.callBaseShow();    // Access through public function

    return 0;                        // End program
}
