#include <iostream>                         // Input and output

int calculateArea(int sideLength) {         // Calculate square area
    return sideLength * sideLength;         // Return area
}

int calculateArea(int length, int width) {  // Calculate rectangle area
    return length * width;                  // Return area
}

double calculateArea(double radius) {       // Calculate circle area
    constexpr double PI = 3.141592653589793; // Store PI
    return PI * radius * radius;            // Return area
}

int main() {                                // Main function
    std::cout << "Square Area: "
              << calculateArea(7) << '\n';  // Calculate square

    std::cout << "Rectangle Area: "
              << calculateArea(8, 5) << '\n'; // Calculate rectangle

    std::cout << "Circle Area: "
              << calculateArea(3.0) << '\n'; // Calculate circle

    return 0;                               // End program
}
