#include <fstream>                    // File handling
#include <iostream>                   // Input and output
#include <string>                     // String support

int main() {                          // Main function
    std::ifstream inputFile("data.txt"); // Open file for reading

    if (!inputFile) {                 // Check file opening
        std::cerr << "Error: Could not open data.txt\n"; // Display error
        return 1;                     // Stop program
    }

    std::string textLine;             // Store each line

    std::cout << "File Content:\n";   // Display heading

    while (std::getline(inputFile, textLine)) { // Read each line
        std::cout << textLine << '\n'; // Display line
    }

    inputFile.close();                // Close file

    return 0;                         // End program
}
