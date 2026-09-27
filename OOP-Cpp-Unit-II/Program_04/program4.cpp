#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class Person {                    // First level
protected:
    std::string name;             // Store name

public:
    explicit Person(std::string personName)
        : name(std::move(personName)) {} // Initialize name

    void showPerson() const {     // Display person
        std::cout << "Name: " << name << '\n'; // Print name
    }
};

class Employee : public Person { // Second level
protected:
    int employeeId;               // Store employee ID

public:
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {} // Initialize members

    void showEmployee() const {   // Display employee
        std::cout << "Employee ID: " << employeeId << '\n'; // Print ID
    }
};

class Manager : public Employee { // Third level
private:
    int teamSize;                 // Store team size

public:
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {} // Initialize

    void showManager() const {    // Display manager details
        showPerson();             // Call Person function
        showEmployee();           // Call Employee function
        std::cout << "Team Size: " << teamSize << '\n'; // Print team size
    }
};

int main() {                      // Main function
    Manager manager("Arjun", 608, 12); // Create manager
    manager.showManager();        // Display details

    return 0;                     // End program
}
