#include <fstream>      // provides ifstream for reading files
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <sstream>      // provides std::stringstream for parsing lines
#include <string>       // provides std::string for field storage

int main() {
    std::ifstream inputFile("students.txt");    // open file for reading
    if (!inputFile) {                           // check if file failed to open
        std::cerr << "Error: Could not open students.txt\n";
        return 1;
    }

    int targetRollNumber;                       // roll number to search for
    std::cout << "Enter roll number to search: ";
    std::cin >> targetRollNumber;                // read target roll number

    std::string line;                            // holds one full record line
    bool found = false;                          // tracks whether match was found

    while (std::getline(inputFile, line)) {      // read one record at a time
        std::stringstream record(line);          // wrap line in a stream for parsing
        std::string rollText;                    // roll number as text
        std::string name;                        // student name
        std::string marksText;                   // marks as text

        if (std::getline(record, rollText, '|') &&   // extract field up to first '|'
            std::getline(record, name, '|') &&       // extract field up to second '|'
            std::getline(record, marksText)) {       // extract remaining text (marks)

            int rollNumber = std::stoi(rollText);    // convert roll number text to int
            double marks = std::stod(marksText);     // convert marks text to double

            if (rollNumber == targetRollNumber) {    // check if this is the target record
                std::cout << "Record Found\n";
                std::cout << "Roll Number: " << rollNumber << '\n';
                std::cout << "Name: " << name << '\n';
                std::cout << "Marks: " << marks << '\n';
                found = true;
                break;                               // stop searching once found
            }
        }
    }

    if (!found) {                                // no match after checking all records
        std::cout << "Student record not found.\n";
    }
    return 0;
}
