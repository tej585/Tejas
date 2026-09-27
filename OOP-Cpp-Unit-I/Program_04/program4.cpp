#include <iostream>   // Input/output library
using namespace std; // Standard namespace

int add(int x, int y); // Function prototype

int main() { // Main entry point
    int val1 = 12, val2 = 28; // Declare and initialize variables
    cout << "Sum = " << add(val1, val2) << endl; // Call function and print result

    return 0; // Exit program
}

int add(int x, int y) { // Function definition
    return x + y; // Return sum of two numbers
}
