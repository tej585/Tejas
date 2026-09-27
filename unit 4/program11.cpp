#include <cstring>      // provides std::strncpy() for copying into char array
#include <fstream>      // provides ifstream/ofstream in binary mode
#include <iostream>     // provides cout/cerr for console output

struct StudentRecord {
    int rollNumber;     // fixed-size integer field
    char name[30];      // fixed-size character array (not std::string!)
    float marks;        // fixed-size floating point field
};

int main() {
    StudentRecord student{};                     // zero-initialize the struct
    student.rollNumber = 101;                    // set roll number
    std::strncpy(student.name, "Amit Patil", sizeof(student.name) - 1); // copy name safely, leaving room for '\0'
    student.marks = 85.5F;                       // set marks

    {
        std::ofstream outputFile("students.dat", std::ios::binary); // open in binary mode for writing
        if (!outputFile) {                       // check if file failed to open
            std::cerr << "Error: Could not create students.dat\n";
            return 1;
        }
        outputFile.write(reinterpret_cast<const char*>(&student), sizeof(student));
        // write the raw bytes of the entire struct to the file
    } // outputFile goes out of scope here and is automatically closed

    StudentRecord readStudent{};                 // struct to hold data read back
    {
        std::ifstream inputFile("students.dat", std::ios::binary); // open in binary mode for reading
        if (!inputFile) {                        // check if file failed to open
            std::cerr << "Error: Could not open students.dat\n";
            return 1;
        }
        inputFile.read(reinterpret_cast<char*>(&readStudent), sizeof(readStudent));
        // read raw bytes back into the struct
        if (!inputFile) {                        // check if read actually succeeded
            std::cerr << "Error: Could not read record from students.dat\n";
            return 1;
        }
    } // inputFile goes out of scope here and is automatically closed

    std::cout << "Roll Number: " << readStudent.rollNumber << '\n';
    std::cout << "Name: " << readStudent.name << '\n';
    std::cout << "Marks: " << readStudent.marks << '\n';
    return 0;
}
