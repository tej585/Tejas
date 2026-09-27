#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class Person {                    // Base class
protected:
    std::string name;             // Store name

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {} // Initialize name

    void displayName() const {    // Display name
        std::cout << "Name: " << name << '\n'; // Print name
    }
};

class Student : virtual public Person { // Virtual inheritance
public:
    Student() : Person("Unknown") {} // Default constructor
};

class Employee : virtual public Person { // Virtual inheritance
public:
    Employee() : Person("Unknown") {} // Default constructor
};

class TeachingAssistant : public Student, public Employee { // Derived class
public:
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)), Student(), Employee() {} // Initialize
};

int main() {                      // Main function
    TeachingAssistant assistant("Sneha"); // Create object
    assistant.displayName();      // Display name

    return 0;                     // End program
}
