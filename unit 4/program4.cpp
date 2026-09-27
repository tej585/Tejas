#include <fstream>      // provides ifstream/ofstream for reading and writing
#include <iostream>     // provides cout/cerr for console output
#include <string>       // provides std::string to hold each line

int main() {
    std::ifstream sourceFile("message.txt");       // open source file for reading
    std::ofstream destinationFile("message_copy.txt"); // open destination file for writing

    if (!sourceFile) {                              // check source opened successfully
        std::cerr << "Error: Could not open source file.\n";
        return 1;
    }
    if (!destinationFile) {                         // check destination opened successfully
        std::cerr << "Error: Could not create destination file.\n";
        return 1;
    }

    std::string line;                               // holds one line at a time
    while (std::getline(sourceFile, line)) {         // read each line from source
        destinationFile << line << '\n';             // write it into destination
    }

    std::cout << "File copied successfully to message_copy.txt\n"; // confirm on console
    return 0;
}
