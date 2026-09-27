#include <iostream>              // Input and output
using namespace std;             // Use standard namespace

class Student {                  // Define class
public:
    static int total;            // Declare static variable

    Student() {                  // Constructor
        total++;                 // Increase count
    }
};

int Student::total = 0;          // Initialize static variable

int main() {                     // Main function
    Student st1, st2, st3, st4;  // Create four objects

    cout << Student::total;      // Display object count

    return 0;                    // End program
}
