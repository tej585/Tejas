#include <iostream>                         // Input and output

class Distance {                            // Define class
private:
    int meters;                             // Store distance

public:
    explicit Distance(int value)            // Constructor
        : meters(value) {}                  // Initialize distance

    bool operator>(const Distance& other) const { // Overload >
        return meters > other.meters;       // Compare distances
    }

    void display() const {                  // Display distance
        std::cout << meters << " meters\n"; // Print distance
    }
};

int main() {                                // Main function
    Distance firstDistance(150);            // Create first distance
    Distance secondDistance(110);           // Create second distance

    std::cout << "First distance: ";        // Display heading
    firstDistance.display();                // Display first

    std::cout << "Second distance: ";       // Display heading
    secondDistance.display();               // Display second

    if (firstDistance > secondDistance) {   // Compare distances
        std::cout << "First distance is greater\n"; // Display result
    } else {
        std::cout << "Second distance is greater or equal\n"; // Result
    }

    return 0;                               // End program
}
