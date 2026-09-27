#include <iostream>               // Input and output

class Account {                   // Define Account class
private:
    double balance;               // Store balance

    friend class Auditor;         // Give Auditor access

public:
    explicit Account(double initialBalance)
        : balance(initialBalance) {} // Initialize balance
};

class Auditor {                   // Define friend class
public:
    void inspect(const Account& account) const { // Inspect account
        std::cout << "Account Balance: "
                  << account.balance << '\n'; // Access private data
    }
};

int main() {                      // Main function
    Account account(7250.0);      // Create account
    Auditor auditor;              // Create auditor

    auditor.inspect(account);     // Check account balance

    return 0;                     // End program
}
