#include <fstream>      // provides ifstream/ofstream for file I/O
#include <iostream>     // provides cin/cout/cerr for console I/O
#include <limits>       // provides std::numeric_limits for cin.ignore()
#include <sstream>      // provides std::stringstream for parsing lines
#include <string>       // provides std::string for text fields

class Book {                                     // represents one library book
private:
    int bookId;                                  // unique identifier for the book
    std::string title;                           // book title
    std::string author;                          // book author
    bool issued;                                 // whether the book is currently issued

public:
    Book(int id, std::string bookTitle, std::string bookAuthor, bool issueStatus = false)
        : bookId(id), title(std::move(bookTitle)), author(std::move(bookAuthor)), issued(issueStatus) {}
        // constructor uses a member-initializer list; std::move avoids copying the strings

    int getBookId() const {                      // returns this book's ID (read-only access)
        return bookId;
    }

    std::string toFileRecord() const {           // converts the object into a pipe-delimited string
        return std::to_string(bookId) + "|" + title + "|" + author + "|" + (issued ? "1" : "0");
    }

    void display() const {                       // prints the book's details to console
        std::cout << "Book ID: " << bookId << '\n';
        std::cout << "Title: " << title << '\n';
        std::cout << "Author: " << author << '\n';
        std::cout << "Status: " << (issued ? "Issued" : "Available") << '\n';
    }
};

void addBook() {                                 // function to add a new book to the file
    int id;                                      // book ID entered by user
    std::string title;                           // book title entered by user
    std::string author;                          // book author entered by user

    std::cout << "Enter book ID: ";
    std::cin >> id;                              // read ID
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear leftover newline
    std::cout << "Enter title: ";
    std::getline(std::cin, title);               // read full title
    std::cout << "Enter author: ";
    std::getline(std::cin, author);              // read full author name

    Book book(id, title, author);                // construct a Book object (issued defaults to false)

    std::ofstream outputFile("library_books.txt", std::ios::app); // open file in append mode
    if (!outputFile) {                           // check if file failed to open
        std::cerr << "Error: Could not open library_books.txt\n";
        return;
    }

    outputFile << book.toFileRecord() << '\n';   // serialize the object and write it as a line
    std::cout << "Book added successfully.\n";
}

void displayBooks() {                            // function to display all stored books
    std::ifstream inputFile("library_books.txt"); // open file for reading
    if (!inputFile) {                            // check file exists
        std::cout << "No library record file found.\n";
        return;
    }

    std::string line;                            // holds one record line
    while (std::getline(inputFile, line)) {      // read every record
        std::stringstream record(line);          // parse this line
        std::string idText;
        std::string title;
        std::string author;
        std::string issuedText;

        if (std::getline(record, idText, '|') &&
            std::getline(record, title, '|') &&
            std::getline(record, author, '|') &&
            std::getline(record, issuedText)) {

            Book book(std::stoi(idText), title, author, issuedText == "1"); // reconstruct object from fields
            book.display();                       // print its details
            std::cout << "-------------------------\n";
        }
    }
}

int main() {                                      // menu-driven entry point
    int choice;                                   // stores user's menu choice
    do {
        std::cout << "\nLibrary Record System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Books\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;                       // read menu choice

        switch (choice) {                         // dispatch based on choice
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 0: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);                        // repeat until user exits
    return 0;
}
