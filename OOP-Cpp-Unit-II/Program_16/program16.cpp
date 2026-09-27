#include <iostream>               // Input and output
#include <string>                 // String support
#include <utility>                // Move function

class Employee {                  // Abstract base class
protected:
    int employeeId;               // Store employee ID
    std::string name;             // Store employee name

public:
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {} // Initialize

    virtual double calculateSalary() const = 0; // Pure virtual function

    void displayBasicDetails() const { // Display basic details
        std::cout << "Employee ID: "
                  << employeeId << '\n'; // Display ID
        std::cout << "Name: "
                  << name << '\n';       // Display name
    }

    virtual ~Employee() = default; // Virtual destructor
};

class PermanentEmployee : public Employee { // Permanent employee
private:
    double basicSalary;             // Store basic salary
    double allowance;               // Store allowance

public:
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic), allowance(extra) {} // Initialize values

    double calculateSalary() const override { // Calculate salary
        return basicSalary + allowance;        // Return total salary
    }
};

class ContractEmployee : public Employee { // Contract employee
private:
    double hourlyRate;               // Store hourly rate
    int hoursWorked;                 // Store hours worked

public:
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate), hoursWorked(hours) {} // Initialize values

    double calculateSalary() const override { // Calculate salary
        return hourlyRate * hoursWorked;       // Return salary
    }
};

void displayPaySlip(const Employee& employee) { // Display payslip
    employee.displayBasicDetails();              // Display employee details
    std::cout << "Salary: "
              << employee.calculateSalary() << "\n\n"; // Display salary
}

int main() {                                    // Main function
    PermanentEmployee permanentEmployee(
        115, "Nisha", 42000.0, 7500.0);         // Create permanent employee

    ContractEmployee contractEmployee(
        116, "Rohan", 550.0, 75);               // Create contract employee

    displayPaySlip(permanentEmployee);           // Display first payslip
    displayPaySlip(contractEmployee);            // Display second payslip

    return 0;                                    // End program
}
