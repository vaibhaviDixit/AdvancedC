/*
Create an abstract class for animals with pure virtual functions for making sounds and displaying information.
Implement derived classes for specific animals.

Input:

Animal* dog = new Dog;
Animal* cat = new Cat;
dog->displayInfo();
dog->makeSound();
cat->displayInfo();
cat->makeSound();

Output:
This is a Dog.
Dog barks
This is a Cat.
Cat meows


*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual void displayInfo() const = 0; // Pure virtual function

    virtual ~Animal() {} // Virtual destructor to ensure proper cleanup when derived objects are deleted.
};

class Dog : public Animal {
public:
    void makeSound() const override { // Implementation of the makeSound() method from the base class.
        cout << "Dog barks" << endl; // Display a message that a dog barks.
    }

    void displayInfo() const override { // Implementation of the displayInfo() method from the base class.
        cout << "This is a Dog." << endl; // Display a message indicating that this is a dog.
    }
};

class Cat : public Animal {
public:
    void makeSound() const override { // Implementation of the makeSound() method from the base class.
        cout << "Cat meows" << endl; // Display a message that a cat meows.
    }

    void displayInfo() const override { // Implementation of the displayInfo() method from the base class.
        cout << "This is a Cat." << endl; // Display a message indicating that this is a cat.
    }
};

int main() {
    Animal* dog = new Dog; // Create a pointer to an Animal object and assign it to a Dog object.
    Animal* cat = new Cat; // Create another pointer to an Animal object and assign it to a Cat object.

    dog->displayInfo(); // Call the displayInfo() method of the Dog object through the base class pointer.
    dog->makeSound(); // Call the makeSound() method of the Dog object through the base class pointer.

    cat->displayInfo(); // Call the displayInfo() method of the Cat object through the base class pointer.
    cat->makeSound(); // Call the makeSound() method of the Cat object through the base class pointer.

    delete dog; // Delete the dynamically allocated memory for the Dog object.
    delete cat; // Delete the dynamically allocated memory for the Cat object.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of polymorphism and dynamic binding using an abstract base class Animal and two derived classes Dog and Cat.

The Animal class is an abstract base class that contains two pure virtual functions, makeSound() and displayInfo(). As with the previous example, pure virtual functions are intended to be overridden in the derived classes, making Animal an abstract class that cannot be instantiated directly.

The Dog class is a derived class from Animal and provides implementations for the makeSound() and displayInfo() methods, displaying messages specific to a dog.

The Cat class is another derived class from Animal and provides implementations for the makeSound() and displayInfo() methods, displaying messages specific to a cat.

In the main() function, two Animal pointers, dog and cat, are created and dynamically allocated to Dog and Cat objects, respectively. Since both makeSound() and displayInfo() are virtual functions in the base class Animal, when these methods are called through the base class pointers dog and cat, the appropriate implementations (based on the actual object type) are invoked, i.e., dynamic binding takes place.

The program prints the information and sound of the dog and cat using the displayInfo() and makeSound() methods through the base class pointers. After the display, the dynamically allocated memory for the objects is properly deallocated using delete to avoid memory leaks.

*/


