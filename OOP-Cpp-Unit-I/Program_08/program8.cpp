#include <iostream>              // Input and output
using namespace std;             // Use standard namespace

class Test {                     // Define class
private:
    int number;                  // Private variable

public:
    Test(int n) {                // Constructor
        number = n;              // Assign value
    }

    inline int getNumber() {     // Inline function
        return number;           // Return value
    }

    friend void display(Test t); // Declare friend function
};

void display(Test t) {           // Define friend function
    cout << t.number;            // Access private value
}

int main() {                     // Main function
    Test obj(75);                // Create object

    cout << obj.getNumber() << endl; // Call getter
    display(obj);                // Call friend function

    return 0;                    // End program
}
