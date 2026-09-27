#include <fstream>      // provides ifstream for reading files
#include <iostream>     // provides cout/cerr for console output
#include <string>       // provides std::string to hold each line

int main() {
    std::ifstream inputFile("missing_file.txt"); // attempt to open a file that doesn't exist
    if (!inputFile.is_open()) {                  // explicitly check whether the file actually opened
        std::cerr << "Error: File could not be opened.\n";
        std::cerr << "Check whether missing_file.txt exists in the current folder.\n";
        return 1;                                // exit early since there's nothing to read
    }

    std::string line;                            // holds one line at a time (unreachable in this run)
    while (std::getline(inputFile, line)) {      // read until end of file
        std::cout << line << '\n';
    }

    if (inputFile.eof()) {                       // loop ended because end-of-file was reached
        std::cout << "End of file reached normally.\n";
    } else if (inputFile.bad()) {                // loop ended due to a serious I/O error
        std::cerr << "A serious file I/O error occurred.\n";
    } else if (inputFile.fail()) {                // loop ended due to a logical read failure
        std::cerr << "A logical file read error occurred.\n";
    }
    return 0;
}
