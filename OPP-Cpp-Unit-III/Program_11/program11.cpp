#include <iostream>                         // Input and output

class Shape {                               // Define abstract class
public:
    virtual double area() const = 0;        // Pure virtual function
    virtual ~Shape() = default;             // Virtual destructor
};

class Rectangle : public Shape {            // Define rectangle
private:
    double length;                          // Store length
    double width;                           // Store width

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {} // Initialize values

    double area() const override {           // Implement area
        return length * width;               // Calculate area
    }
};

int main() {                                // Main function
    Rectangle rectangle(9.0, 5.0);           // Create rectangle

    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n';   // Display area

    return 0;                               // End program
}
