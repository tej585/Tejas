#include <iostream>                         // Input and output

class Animal {                              // Define base class
public:
    virtual void sound() const {            // Virtual function
        std::cout << "Animal makes a sound\n"; // Display message
    }

    virtual ~Animal() = default;             // Virtual destructor
};

class Dog : public Animal {                 // Define Dog class
public:
    void sound() const override {            // Override function
        std::cout << "Dog barks\n";          // Display sound
    }
};

class Cat : public Animal {                 // Define Cat class
public:
    void sound() const override {            // Override function
        std::cout << "Cat meows\n";          // Display sound
    }
};

int main() {                                // Main function
    Dog dog;                                // Create dog
    Cat cat;                                // Create cat

    Animal* animalPointer = &dog;           // Point to dog
    animalPointer->sound();                 // Call dog sound

    animalPointer = &cat;                   // Point to cat
    animalPointer->sound();                 // Call cat sound

    return 0;                               // End program
}
