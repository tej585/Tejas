#include <iostream>              // Input and output
#include <string>                // String support
#include <utility>               // Move function

class Employee {                 // Define base class
protected:
    std::string name;             // Protected name

public:
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {} // Initialize name
};

class Developer : public Employee { // Define derived class
private:
    std::string language;          // Store programming language

public:
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage)) {} // Initialize members

    void display() const {         // Display details
        std::cout << "Developer: " << name << '\n'; // Access protected member
        std::cout << "Language: " << language << '\n'; // Display language
    }
};

int main() {                       // Main function
    Developer developer("Priya", "Python"); // Create object
    developer.display();           // Display details

    return 0;                      // End program
}
