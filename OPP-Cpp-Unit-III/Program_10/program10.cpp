#include <iostream>                         // Input and output

class Shape {                               // Define base class
public:
    virtual double area() const {           // Virtual function
        return 0.0;                         // Return default area
    }

    virtual ~Shape() = default;             // Virtual destructor
};

class Rectangle : public Shape {             // Rectangle class
private:
    double length;                          // Store length
    double width;                           // Store width

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {} // Initialize values

    double area() const override {           // Override area
        return length * width;               // Calculate area
    }
};

class Circle : public Shape {                // Circle class
private:
    double radius;                          // Store radius

public:
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}             // Initialize radius

    double area() const override {           // Override area
        constexpr double PI = 3.141592653589793; // Store PI
        return PI * radius * radius;         // Calculate area
    }
};

void printArea(const Shape& shape) {         // Receive base reference
    std::cout << "Area: " << shape.area() << '\n'; // Display area
}

int main() {                                // Main function
    Rectangle rectangle(7.0, 4.0);           // Create rectangle
    Circle circle(3.0);                      // Create circle

    printArea(rectangle);                   // Process rectangle
    printArea(circle);                      // Process circle

    return 0;                               // End program
}
