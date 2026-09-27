#include <fstream>      // provides ofstream/ifstream for file I/O
#include <iostream>     // provides cout/cerr for console output

int main() {
    std::ofstream outputFile("message.txt");   // open (create) message.txt for writing
    if (!outputFile) {                         // check if file failed to open
        std::cerr << "Error: Could not create message.txt\n";
        return 1;                              // exit with error code
    }

    outputFile << "Welcome to C++ File Handling\n";        // write line 1
    outputFile << "This is the first line written to a file.\n"; // write line 2
    outputFile << "Files store data permanently.\n";       // write line 3

    outputFile.close();                        // close the file, flush data to disk

    std::cout << "Data written successfully to message.txt\n"; // confirm on console
    return 0;
}
