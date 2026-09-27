#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class Person {                    // Base class
protected:
    std::string name;             // Store name

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {} // Initialize name
};

class Student : public Person {   // Derived class
private:
    int rollNumber;               // Store roll number

public:
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {} // Initialize

    void display() const {        // Display details
        std::cout << "Name: " << name << '\n'; // Print name
        std::cout << "Roll Number: "
                  << rollNumber << '\n'; // Print roll number
    }
};

int main() {                      // Main function
    Student student("Mehul", 31); // Create student
    student.display();            // Display details

    return 0;                     // End program
}
