#include <iostream>               // Input and output

class Academic {                  // First base class
public:
    void display() const {        // Display academic information
        std::cout << "Academic information\n"; // Print message
    }
};

class Sports {                    // Second base class
public:
    void display() const {        // Display sports information
        std::cout << "Sports information\n"; // Print message
    }
};

class Student : public Academic, public Sports { // Multiple inheritance
public:
    void displayAll() const {      // Display both
        Academic::display();       // Call Academic function
        Sports::display();         // Call Sports function
    }
};

int main() {                       // Main function
    Student student;               // Create object

    student.Academic::display();   // Specify Academic function
    student.Sports::display();     // Specify Sports function
    student.displayAll();          // Display both

    return 0;                      // End program
}
