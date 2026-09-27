#include <fstream>      // provides ifstream for reading files
#include <iostream>     // provides cout/cerr for console output
#include <string>       // provides std::string to store each line

int main() {
    std::ifstream inputFile("message.txt");    // open message.txt for reading
    if (!inputFile) {                          // check if file failed to open
        std::cerr << "Error: Could not open message.txt\n";
        return 1;                              // exit with error code
    }

    std::string line;                          // holds one line at a time
    std::cout << "File Content:\n";
    while (std::getline(inputFile, line)) {    // read until end of file
        std::cout << line << '\n';             // print the line to console
    }

    inputFile.close();                         // close the file after reading
    return 0;
}
