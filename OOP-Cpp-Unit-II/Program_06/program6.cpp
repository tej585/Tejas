
#include <iostream>               // Input and output

class Academic {                  // First base class
protected:
    int academicMarks;            // Store academic marks

public:
    explicit Academic(int marks)
        : academicMarks(marks) {} // Initialize marks

    void showAcademic() const {   // Display academic marks
        std::cout << "Academic Marks: "
                  << academicMarks << '\n'; // Print marks
    }
};

class Sports {                    // Second base class
protected:
    int sportsMarks;              // Store sports marks

public:
    explicit Sports(int marks)
        : sportsMarks(marks) {}   // Initialize marks

    void showSports() const {     // Display sports marks
        std::cout << "Sports Marks: "
                  << sportsMarks << '\n'; // Print marks
    }
};

class Student : public Academic, public Sports { // Multiple inheritance
public:
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {} // Initialize both bases

    void showTotal() const {       // Display total
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks << '\n'; // Add marks
    }
};

int main() {                       // Main function
    Student student(86, 18);       // Create student
    student.showAcademic();        // Show academic marks
    student.showSports();          // Show sports marks
    student.showTotal();           // Show total

    return 0;                      // End program
}
