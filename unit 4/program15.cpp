#include <cstdio>       // provides std::remove() and std::rename()
#include <fstream>      // provides ifstream/ofstream for file I/O
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <limits>       // provides std::numeric_limits for cin.ignore()
#include <sstream>      // provides std::stringstream for parsing lines
#include <string>       // provides std::string for text fields

void addStudent() {                              // function to add one new student record
    std::ofstream outputFile("student_records.txt", std::ios::app); // open in append mode
    if (!outputFile) {                           // check if file failed to open
        std::cerr << "Error: Could not open student_records.txt\n";
        return;
    }

    int rollNumber;                              // stores roll number
    std::string name;                            // stores name
    double marks;                                // stores marks

    std::cout << "Enter roll number: ";
    std::cin >> rollNumber;                      // read roll number
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear leftover newline
    std::getline(std::cin, name);                // read full name
    std::cout << "Enter marks: ";
    std::cin >> marks;                           // read marks

    outputFile << rollNumber << '|' << name << '|' << marks << '\n'; // write record
    std::cout << "Record added successfully.\n";
}

void displayStudents() {                         // function to display all records
    std::ifstream inputFile("student_records.txt"); // open for reading
    if (!inputFile) {                            // check file exists
        std::cout << "No student record file found.\n";
        return;
    }

    std::string line;                            // holds one record line
    std::cout << "\nRoll No.\tName\t\tMarks\n";
    std::cout << "----------------------------------------\n";

    while (std::getline(inputFile, line)) {      // read every record
        std::stringstream record(line);          // parse this line
        std::string rollText;
        std::string name;
        std::string marksText;

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {
            std::cout << rollText << "\t\t" << name << "\t\t" << marksText << '\n'; // print as table row
        }
    }
}

void searchStudent() {                           // function to search by roll number
    std::ifstream inputFile("student_records.txt");
    if (!inputFile) {
        std::cout << "No student record file found.\n";
        return;
    }

    int targetRoll;                              // roll number to find
    std::cout << "Enter roll number to search: ";
    std::cin >> targetRoll;

    std::string line;
    bool found = false;                          // tracks match status

    while (std::getline(inputFile, line)) {
        std::stringstream record(line);
        std::string rollText;
        std::string name;
        std::string marksText;

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {
            if (std::stoi(rollText) == targetRoll) { // compare as integers
                std::cout << "Record Found\n";
                std::cout << "Roll Number: " << rollText << '\n';
                std::cout << "Name: " << name << '\n';
                std::cout << "Marks: " << marksText << '\n';
                found = true;
                break;                            // stop after first match
            }
        }
    }
    if (!found) {                                 // no match found
        std::cout << "Student not found.\n";
    }
}

void updateMarks() {                              // function to update a student's marks
    std::ifstream inputFile("student_records.txt");     // original file
    std::ofstream temporaryFile("student_records_temp.txt"); // temp file for rewritten data
    if (!inputFile || !temporaryFile) {           // check both opened
        std::cerr << "Error: Could not open record file(s).\n";
        return;
    }

    int targetRoll;                               // roll number to update
    double newMarks;                              // new marks value
    std::cout << "Enter roll number to update: ";
    std::cin >> targetRoll;
    std::cout << "Enter new marks: ";
    std::cin >> newMarks;

    std::string line;
    bool found = false;

    while (std::getline(inputFile, line)) {       // process every record
        std::stringstream record(line);
        std::string rollText;
        std::string name;
        std::string marksText;

        if (std::getline(record, rollText, '|') &&
            std::getline(record, name, '|') &&
            std::getline(record, marksText)) {
            if (std::stoi(rollText) == targetRoll) {   // this is the target record
                temporaryFile << rollText << '|' << name << '|' << newMarks << '\n'; // write updated version
                found = true;
            } else {
                temporaryFile << line << '\n';    // copy unchanged record
            }
        }
    }

    inputFile.close();                            // close before file operations
    temporaryFile.close();

    if (!found) {                                 // target not found
        std::remove("student_records_temp.txt");  // discard unused temp file
        std::cout << "Student not found. No changes made.\n";
        return;
    }

    if (std::remove("student_records.txt") != 0 ||        // delete old file
        std::rename("student_records_temp.txt", "student_records.txt") != 0) { // rename temp to original
        std::cerr << "Error: Could not replace the record file.\n";
        return;
    }
    std::cout << "Marks updated successfully.\n";
}

int main() {                                      // menu-driven entry point
    int choice;                                   // stores user's menu choice
    do {
        std::cout << "\nStudent Record Manager\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Update Marks\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;                       // read menu choice

        switch (choice) {                         // dispatch to the right function
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 0: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);                        // repeat until user chooses to exit
    return 0;
}
