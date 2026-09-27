#include <iostream>                         // Input and output

class Complex {                             // Define class
private:
    int real;                               // Store real part
    int imaginary;                          // Store imaginary part

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {} // Initialize values

    friend Complex operator+(int value,
                             const Complex& number); // Declare friend

    void display() const {                  // Display complex number
        std::cout << real;                  // Print real part

        if (imaginary >= 0) {               // Check sign
            std::cout << " + ";             // Print plus
        } else {
            std::cout << " - ";             // Print minus
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary)
                  << "i\n";                 // Print imaginary part
    }
};

Complex operator+(int value, const Complex& number) { // Define friend operator
    return Complex(value + number.real,
                   number.imaginary);       // Add integer to real part
}

int main() {                                // Main function
    Complex number(4, 6);                    // Create complex object

    Complex result = 12 + number;            // Add integer and object

    std::cout << "Result: ";                // Display heading
    result.display();                       // Display result

    return 0;                               // End program
}
