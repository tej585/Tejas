#include <cstring>      // provides std::strncpy() for copying into char array
#include <fstream>      // provides ifstream/ofstream in binary mode
#include <iostream>     // provides cin/cout/cerr for console I/O

struct StudentRecord {
    int rollNumber;     // fixed-size integer field
    char name[30];      // fixed-size character array
    float marks;        // fixed-size floating point field
};

void addRecord(std::ofstream& file, int rollNumber, const char* name, float marks) {
    StudentRecord student{};                     // zero-initialize a new record
    student.rollNumber = rollNumber;              // set roll number
    std::strncpy(student.name, name, sizeof(student.name) - 1); // copy name safely
    student.marks = marks;                        // set marks
    file.write(reinterpret_cast<const char*>(&student), sizeof(student)); // write raw bytes
}

int main() {
    {
        std::ofstream outputFile("records.dat", std::ios::binary | std::ios::trunc);
        // open in binary mode, discard any existing content
        if (!outputFile) {                        // check if file failed to open
            std::cerr << "Error: Could not create records.dat\n";
            return 1;
        }
        addRecord(outputFile, 101, "Amit", 85.5F); // write record 1
        addRecord(outputFile, 102, "Neha", 91.0F); // write record 2
        addRecord(outputFile, 103, "Ravi", 78.0F); // write record 3
    } // outputFile closed automatically here

    std::ifstream inputFile("records.dat", std::ios::binary); // reopen file for reading
    if (!inputFile) {                             // check if file failed to open
        std::cerr << "Error: Could not open records.dat\n";
        return 1;
    }

    int recordNumber;                             // which record the user wants (1-based)
    std::cout << "Enter record number to read (1 to 3): ";
    std::cin >> recordNumber;

    if (recordNumber < 1 || recordNumber > 3) {   // validate range
        std::cerr << "Invalid record number.\n";
        return 1;
    }

    const std::streamoff offset = static_cast<std::streamoff>(recordNumber - 1) *
                                   static_cast<std::streamoff>(sizeof(StudentRecord));
    // calculate byte offset of the requested record: (index) * (size of one record)

    inputFile.seekg(offset, std::ios::beg);       // jump directly to that record's position

    StudentRecord selectedStudent{};              // struct to hold the record read
    inputFile.read(reinterpret_cast<char*>(&selectedStudent), sizeof(selectedStudent));
    // read exactly one record's worth of bytes
    if (!inputFile) {                             // verify the read succeeded
        std::cerr << "Error: Could not read selected record.\n";
        return 1;
    }

    std::cout << "Roll Number: " << selectedStudent.rollNumber << '\n';
    std::cout << "Name: " << selectedStudent.name << '\n';
    std::cout << "Marks: " << selectedStudent.marks << '\n';
    return 0;
}
