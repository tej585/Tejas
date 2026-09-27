#include <cctype>       // provides std::isspace(), std::isalpha(), std::isdigit(), std::tolower()
#include <fstream>      // provides ifstream for reading files
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <string>       // provides std::string for the filename

bool isVowel(char ch) {                          // helper function: checks if a char is a vowel
    ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch))); // convert to lowercase first
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; // true if it matches a vowel
}

int main() {
    std::string fileName;                        // will hold the file name entered by user
    std::cout << "Enter file name: ";
    std::getline(std::cin, fileName);             // read full filename (allows spaces)

    std::ifstream inputFile(fileName);            // open the given file for reading
    if (!inputFile) {                             // check if file failed to open
        std::cerr << "Error: Could not open " << fileName << '\n';
        return 1;
    }

    std::size_t lines = 0;                        // counts lines
    std::size_t words = 0;                        // counts words
    std::size_t characters = 0;                   // counts all characters
    std::size_t vowels = 0;                       // counts vowels
    std::size_t digits = 0;                       // counts digit characters
    std::size_t spaces = 0;                       // counts space characters specifically
    bool insideWord = false;                      // tracks whether currently inside a word
    char ch;                                      // holds one character at a time

    while (inputFile.get(ch)) {                   // read character by character
        ++characters;                             // count every character

        if (ch == '\n') {                         // newline marks end of a line
            ++lines;
        }

        if (std::isspace(static_cast<unsigned char>(ch))) { // check for whitespace
            if (ch == ' ') {                       // specifically count plain spaces
                ++spaces;
            }
            insideWord = false;                    // whitespace ends a word
        } else if (!insideWord) {                  // first non-space char after whitespace
            ++words;
            insideWord = true;
        }

        if (std::isalpha(static_cast<unsigned char>(ch)) && isVowel(ch)) { // letter AND a vowel
            ++vowels;
        }
        if (std::isdigit(static_cast<unsigned char>(ch))) { // check for digit character
            ++digits;
        }
    }

    if (characters > 0) {                          // handle file without trailing newline
        inputFile.clear();                         // clear eof flag before seeking
        inputFile.seekg(-1, std::ios::end);         // jump to last character
        char lastCharacter;
        inputFile.get(lastCharacter);               // read it
        if (lastCharacter != '\n') {                // if file doesn't end in newline
            ++lines;                                // count that final line
        }
    }

    std::cout << "\nFile Statistics\n";
    std::cout << "Lines: " << lines << '\n';
    std::cout << "Words: " << words << '\n';
    std::cout << "Characters: " << characters << '\n';
    std::cout << "Vowels: " << vowels << '\n';
    std::cout << "Digits: " << digits << '\n';
    std::cout << "Spaces: " << spaces << '\n';
    return 0;
}
