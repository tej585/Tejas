#include <fstream>      // provides ifstream for reading files
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <string>       // provides std::string for words

int main() {
    std::ifstream inputFile("message.txt");     // open file for reading
    if (!inputFile) {                           // check if file failed to open
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::string searchWord;                     // will hold the word to search for
    std::cout << "Enter word to search: ";
    std::cin >> searchWord;                     // read search word from user

    std::string word;                           // holds each word read from the file
    int count = 0;                              // counts number of matches

    while (inputFile >> word) {                 // read one whitespace-separated word at a time
        if (word == searchWord) {               // compare with the search word
            ++count;                            // increment on exact match
        }
    }

    std::cout << "The word '" << searchWord << "' occurred " << count << " time(s).\n";
    return 0;
}
