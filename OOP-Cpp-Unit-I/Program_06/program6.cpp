#include <iostream>              // Input and output
using namespace std;             // Use standard namespace

class Demo {                     // Define class
public:
    Demo() {                     // Constructor
        cout << "Constructor called\n"; // Display message
    }

    ~Demo() {                    // Destructor
        cout << "Destructor called\n";  // Display message
    }
};

int main() {                     // Main function
    Demo obj;                    // Create object

    return 0;                    // End program
}
