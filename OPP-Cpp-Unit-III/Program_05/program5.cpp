#include <iostream>                         // Input and output

class Complex {                             // Define complex class
private:
    int real;                               // Store real part
    int imaginary;                          // Store imaginary part

public:
    Complex(int realPart = 0, int imaginaryPart = 0)
        : real(realPart), imaginary(imaginaryPart) {} // Initialize values

    Complex operator+(const Complex& other) const { // Overload +
        return Complex(real + other.real,
                       imaginary + other.imaginary); // Add parts
    }

    void display() const {                  // Display complex number
        std::cout << real;                   // Print real part

        if (imaginary >= 0) {               // Check sign
            std::cout << " + ";             // Print plus sign
        } else {
            std::cout << " - ";             // Print minus sign
        }

        std::cout << (imaginary >= 0 ? imaginary : -imaginary)
                  << "i\n";                 // Print imaginary part
    }
};

int main() {                                // Main function
    Complex firstNumber(3, 4);               // Create first number
    Complex secondNumber(5, 2);              // Create second number

    Complex total = firstNumber + secondNumber; // Add numbers

    std::cout << "First complex number: ";  // Display heading
    firstNumber.display();                  // Display first

    std::cout << "Second complex number: "; // Display heading
    secondNumber.display();                 // Display second

    std::cout << "Sum: ";                   // Display heading
    total.display();                        // Display result

    return 0;                               // End program
}
