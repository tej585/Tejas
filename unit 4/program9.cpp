#include <cstdio>       // provides std::remove() and std::rename()
#include <fstream>      // provides ifstream/ofstream for reading and writing
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <sstream>      // provides std::stringstream for parsing lines
#include <string>       // provides std::string for field storage

int main() {
    std::ifstream inputFile("students.txt");        // open original file for reading
    std::ofstream temporaryFile("students_temp.txt"); // create temporary file for writing
    if (!inputFile || !temporaryFile) {              // check both streams opened
        std::cerr << "Error: Could not open file(s).\n";
        return 1;
    }

    int targetRollNumber;                            // roll number to update
    double updatedMarks;                             // new marks value
    std::cout << "Enter roll number to update: ";
    std::cin >> targetRollNumber;
    std::cout << "Enter updated marks: ";
    std::cin >> updatedMarks;

    std::string line;                                // holds one record line
    bool found = false;                              // tracks whether record was updated

    while (std::getline(inputFile, line)) {          // process every record
        std::stringstream record(line);              // parse this line
        std::string rollText;
        std::string name;
        std::string marksText;

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {

            int rollNumber = std::stoi(rollText);    // convert roll number to int

            if (rollNumber == targetRollNumber) {    // this is the record to update
                temporaryFile << rollNumber << '|' << name << '|' << updatedMarks << '\n'; // write updated record
                found = true;
            } else {
                temporaryFile << line << '\n';       // copy unchanged record as-is
            }
        }
    }

    inputFile.close();                               // close both files before file operations
    temporaryFile.close();

    if (!found) {                                    // target roll number never matched
        std::remove("students_temp.txt");            // delete unused temp file
        std::cout << "Student record not found. No update performed.\n";
        return 0;
    }

    if (std::remove("students.txt") != 0) {          // delete old file
        std::cerr << "Error: Could not remove old students.txt\n";
        return 1;
    }
    if (std::rename("students_temp.txt", "students.txt") != 0) { // rename temp file to original name
        std::cerr << "Error: Could not rename temporary file.\n";
        return 1;
    }

    std::cout << "Student marks updated successfully.\n";
    return 0;
}
