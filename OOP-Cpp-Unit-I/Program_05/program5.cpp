#include <iostream>              // Input and output
using namespace std;             // Use standard namespace

class Student {                  // Define class
public:
    string studentName;          // Store name
    int studentAge;              // Store age

    void display() {             // Define member function
        cout << studentName << " " << studentAge << endl; // Display data
    }
};

int main() {                     // Main function
    Student student1;            // Create object

    student1.studentName = "Rahul"; // Assign name
    student1.studentAge = 21;       // Assign age

    student1.display();          // Call member function

    return 0;                    // End program
}
