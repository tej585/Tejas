#include <iostream>                         // Input and output

class Counter {                             // Define class
private:
    int value;                              // Store counter value

public:
    explicit Counter(int initialValue = 0)  // Constructor
        : value(initialValue) {}            // Initialize value

    Counter& operator++() {                 // Prefix increment
        ++value;                            // Increase value
        return *this;                       // Return current object
    }

    Counter operator++(int) {               // Postfix increment
        Counter oldValue = *this;           // Save old value
        ++value;                            // Increase value
        return oldValue;                    // Return old object
    }

    void display() const {                  // Display value
        std::cout << value << '\n';         // Print value
    }
};

int main() {                                // Main function
    Counter counter(8);                     // Create counter

    std::cout << "After prefix increment: "; // Display heading
    ++counter;                              // Prefix increment
    counter.display();                      // Display value

    std::cout << "Value returned by postfix increment: "; // Heading
    Counter previous = counter++;          // Store old value
    previous.display();                    // Display old value

    std::cout << "Counter after postfix increment: "; // Heading
    counter.display();                      // Display new value

    return 0;                               // End program
}
