#include <fstream>                    // File handling
#include <iostream>                   // Input and output

int main() {                          // Main function
    std::ofstream outputFile("data.txt"); // Open file for writing

    if (!outputFile) {                // Check file opening
        std::cerr << "Error: Could not create data.txt\n"; // Display error
        return 1;                     // Stop program
    }

    outputFile << "Welcome to File Handling\n"; // Write first line
    outputFile << "C++ stores data in files.\n"; // Write second line
    outputFile << "File handling is useful.\n"; // Write third line

    outputFile.close();               // Close file

    std::cout << "Data written successfully.\n"; // Display message

    return 0;                         // End program
}
