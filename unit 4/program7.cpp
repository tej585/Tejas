#include <fstream>      // provides ofstream for writing files
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <limits>       // provides std::numeric_limits for cin.ignore()
#include <string>       // provides std::string for name storage

int main() {
    std::ofstream outputFile("students.txt", std::ios::app); // open in append mode
    if (!outputFile) {                          // check if file failed to open
        std::cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    int rollNumber;                             // stores roll number
    std::string name;                           // stores student name
    double marks;                               // stores marks

    std::cout << "Enter roll number: ";
    std::cin >> rollNumber;                     // read roll number (leaves newline in buffer)

    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard leftover newline
    std::getline(std::cin, name);               // read full name including spaces

    std::cout << "Enter marks: ";
    std::cin >> marks;                          // read marks

    outputFile << rollNumber << '|' << name << '|' << marks << '\n'; // write delimited record

    std::cout << "Student record saved successfully.\n";
    return 0;
}
