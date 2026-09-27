#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class University {                // Outer class
public:
    class Department {            // Nested class
    private:
        std::string name;         // Store department name

    public:
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {} // Initialize name

        void display() const {    // Display department
            std::cout << "Department: "
                      << name << '\n'; // Print name
        }
    };
};

int main() {                      // Main function
    University::Department department("Computer Engineering"); // Create object
    department.display();         // Display department

    return 0;                     // End program
}
