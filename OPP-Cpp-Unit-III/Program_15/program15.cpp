#include <iostream>                         // Input and output

class Payment {                             // Define abstract class
public:
    virtual void pay(double amount) const = 0; // Pure virtual function
    virtual ~Payment() = default;           // Virtual destructor
};

class CardPayment : public Payment {        // Card payment class
public:
    void pay(double amount) const override { // Implement payment
        std::cout << "Paid Rs. " << amount
                  << " using card\n";       // Display payment
    }
};

class UpiPayment : public Payment {         // UPI payment class
public:
    void pay(double amount) const override { // Implement payment
        std::cout << "Paid Rs. " << amount
                  << " using UPI\n";        // Display payment
    }
};

class NetBankingPayment : public Payment {  // Net banking class
public:
    void pay(double amount) const override { // Implement payment
        std::cout << "Paid Rs. " << amount
                  << " using net banking\n"; // Display payment
    }
};

void processPayment(const Payment& payment,
                    double amount) {       // Process payment
    payment.pay(amount);                    // Call correct function
}

int main() {                                // Main function
    CardPayment card;                       // Create card object
    UpiPayment upi;                         // Create UPI object
    NetBankingPayment netBanking;           // Create net banking object

    processPayment(card, 1450.0);           // Process card payment
    processPayment(upi, 850.0);             // Process UPI payment
    processPayment(netBanking, 650.0);      // Process net banking payment

    return 0;                               // End program
}
