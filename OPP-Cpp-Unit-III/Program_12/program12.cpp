#include <iostream>                         // Input and output
#include <memory>                           // Smart pointers
#include <vector>                           // Vector

class Shape {                               // Define abstract class
public:
    virtual double area() const = 0;        // Pure virtual area
    virtual void displayName() const = 0;   // Pure virtual name
    virtual ~Shape() = default;             // Virtual destructor
};

class Rectangle : public Shape {            // Rectangle class
private:
    double length;                          // Store length
    double width;                           // Store width

public:
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {} // Initialize values

    double area() const override {           // Calculate area
        return length * width;               // Return area
    }

    void displayName() const override {      // Display shape name
        std::cout << "Rectangle";            // Print name
    }
};

class Circle : public Shape {               // Circle class
private:
    double radius;                          // Store radius

public:
    explicit Circle(double givenRadius)
        : radius(givenRadius) {}             // Initialize radius

    double area() const override {            // Calculate area
        constexpr double PI = 3.141592653589793; // Store PI
        return PI * radius * radius;         // Return area
    }

    void displayName() const override {      // Display shape name
        std::cout << "Circle";               // Print name
    }
};

int main() {                                // Main function
    std::vector<std::unique_ptr<Shape>> shapes; // Create pointer collection

    shapes.push_back(
        std::make_unique<Rectangle>(7.0, 4.0)); // Add rectangle

    shapes.push_back(
        std::make_unique<Circle>(3.0));          // Add circle

    for (const auto& shape : shapes) {           // Loop through shapes
        shape->displayName();                    // Display name
        std::cout << " Area: "
                  << shape->area() << '\n';      // Display area
    }

    return 0;                                    // End program
}
