#include <fstream>      // provides fstream for combined read/write
#include <iostream>     // provides cout/cerr for console output
#include <string>       // included for consistency (not directly used here)

int main() {
    std::fstream file("navigation.txt", std::ios::in | std::ios::out | std::ios::trunc);
    // open for both reading and writing, truncating any existing content
    if (!file) {                                 // check if file failed to open
        std::cerr << "Error: Could not open navigation.txt\n";
        return 1;
    }

    file << "ABCDE";                             // write 5 characters to the file
    std::cout << "Output position after writing: " << file.tellp() << '\n'; // report output position
    file.flush();                                // force buffered write to be committed

    file.seekg(0, std::ios::beg);                // move input position to the beginning
    char firstCharacter;
    file.get(firstCharacter);                    // read one character (should be 'A')
    std::cout << "First character: " << firstCharacter << '\n';
    std::cout << "Input position after reading one character: " << file.tellg() << '\n';

    file.seekg(2, std::ios::beg);                // move input position to index 2 (0-based)
    char thirdCharacter;
    file.get(thirdCharacter);                    // read the character there (should be 'C')
    std::cout << "Character at position 2: " << thirdCharacter << '\n';

    file.seekp(5, std::ios::beg);                // move output position to index 5 (past "ABCDE")
    file << "F";                                 // write 'F' at that position

    file.close();                                // close the file
    std::cout << "Navigation completed. Check navigation.txt\n";
    return 0;
}
