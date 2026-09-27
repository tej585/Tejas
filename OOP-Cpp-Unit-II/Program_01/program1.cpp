#include <iostream>              // Input and output
#include <string>                // String support
#include <utility>               // Move function

class Person {                   // Define base class
protected:
    std::string name;             // Store name

public:
    explicit Person(std::string personName) : name(std::move(personName)) {} // Constructor

    void displayName() const {    // Display name
        std::cout << "Name: " << name << '\n'; // Print name
    }
};

class Student : public Person {  // Define derived class
private:
    int rollNumber;               // Store roll number

public:
    Student(std::string studentName, int roll) // Constructor
        : Person(std::move(studentName)), rollNumber(roll) {} // Initialize members

    void displayStudent() const { // Display student details
        displayName();            // Call base function
        std::cout << "Roll Number: " << rollNumber << '\n'; // Print roll number
    }
};

int main() {                      // Main function
    Student student("Rahul", 116); // Create object
    student.displayStudent();      // Display details

    return 0;                     // End program
}
