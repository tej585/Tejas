#include <fstream>      // provides ofstream for writing files
#include <iostream>     // provides cout/cerr for console output

int main() {
    std::ofstream outputFile("message.txt", std::ios::app); // open in append mode
    if (!outputFile) {                          // check if file failed to open
        std::cerr << "Error: Could not open message.txt for appending\n";
        return 1;                               // exit with error code
    }

    outputFile << "This line was added using append mode.\n"; // write new line at end

    outputFile.close();                         // close the file, flush data to disk
    std::cout << "New line appended successfully.\n"; // confirm on console
    return 0;
}
