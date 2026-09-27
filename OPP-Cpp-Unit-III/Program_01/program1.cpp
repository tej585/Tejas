#include <iostream>                         // Input and output

int addNumbers(int num1, int num2) {        // Add two integers
    return num1 + num2;                     // Return sum
}

double addNumbers(double num1, double num2) { // Add two decimals
    return num1 + num2;                       // Return sum
}

int addNumbers(int num1, int num2, int num3) { // Add three integers
    return num1 + num2 + num3;                  // Return sum
}

int main() {                                  // Main function
    std::cout << "Sum of two integers: "
              << addNumbers(15, 25) << '\n'; // Call integer function

    std::cout << "Sum of two doubles: "
              << addNumbers(3.2, 4.8) << '\n'; // Call double function

    std::cout << "Sum of three integers: "
              << addNumbers(12, 18, 24) << '\n'; // Call three-number function

    return 0;                                 // End program
}
