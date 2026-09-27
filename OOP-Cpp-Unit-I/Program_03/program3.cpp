#include <iostream>  // Input/output library
using namespace std; // Standard namespace

int main() { // Main entry point
    int scores[5] = {85, 92, 74, 68, 90}; // Integer array of 5 scores

    for (int i = 0; i < 5; i++) { // Loop through array indices 0 to 4
        cout << scores[i] << " ";  // Output each score followed by space
    }
    cout << endl; // Print newline

    return 0; // Exit program
}
