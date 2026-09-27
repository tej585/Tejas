#include <iostream>               // Input and output

class Shape {                     // Abstract base class
public:
    virtual double area() const = 0; // Pure virtual function
    virtual ~Shape() = default;   // Virtual destructor
};

class Rectangle : public Shape {  // Rectangle class
private:
    double length;                // Store length
    double width;                 // Store width

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {} // Initialize values

    double area() const override { // Override area
        return length * width;     // Calculate rectangle area
    }
};

class Circle : public Shape {     // Circle class
private:
    double radius;                // Store radius

public:
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}  // Initialize radius

    double area() const override { // Override area
        return 3.141592653589793 * radius * radius; // Calculate circle area
    }
};

int main() {                      // Main function
    Rectangle rectangle(7.0, 4.0); // Create rectangle
    Circle circle(3.0);             // Create circle

    std::cout << "Rectangle Area: "
              << rectangle.area() << '\n'; // Display rectangle area

    std::cout << "Circle Area: "
              << circle.area() << '\n'; // Display circle area

    return 0;                     // End program
}
