#include <cctype>       // provides std::isspace() for whitespace detection
#include <fstream>      // provides ifstream for reading files
#include <iostream>     // provides cout/cerr for console output
#include <string>       // included for consistency (not directly used for storage here)

int main() {
    std::ifstream inputFile("message.txt");     // open file for reading
    if (!inputFile) {                           // check if file failed to open
        std::cerr << "Error: Could not open message.txt\n";
        return 1;
    }

    std::size_t lineCount = 0;                  // counts number of lines
    std::size_t wordCount = 0;                  // counts number of words
    std::size_t characterCount = 0;             // counts total characters
    bool insideWord = false;                    // tracks whether we are currently inside a word
    char ch;                                    // holds one character at a time

    while (inputFile.get(ch)) {                 // read character by character
        ++characterCount;                       // every character read counts

        if (ch == '\n') {                       // newline means a line has ended
            ++lineCount;
        }

        if (std::isspace(static_cast<unsigned char>(ch))) { // check if character is whitespace
            insideWord = false;                 // whitespace ends a word
        } else if (!insideWord) {               // first non-space char after a space = new word
            ++wordCount;
            insideWord = true;
        }
    }

    if (characterCount > 0) {                   // handle files without a trailing newline
        inputFile.clear();                      // clear eof/fail flags before seeking
        inputFile.seekg(-1, std::ios::end);      // move to the last character
        char lastCharacter;
        inputFile.get(lastCharacter);            // read that last character
        if (lastCharacter != '\n') {             // if file doesn't end with newline
            ++lineCount;                         // count the final unterminated line
        }
    }

    std::cout << "Lines: " << lineCount << '\n';
    std::cout << "Words: " << wordCount << '\n';
    std::cout << "Characters: " << characterCount << '\n';
    return 0;
}
