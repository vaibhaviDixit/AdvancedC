/*

Create a base class Printable with a pure virtual function print(). Implement derived classes Book and Magazine that override the print()
function to display their respective details.

Input:
    Printable* print1 = new Book("The Alchemist", "Paulo Coelho");
    Printable* print2 = new Magazine("National Geographic", 123);

    print1->print()
    print2->print()

Output:
Book Title: The Alchemist, Author: Paulo Coelho
Magazine Name: National Geographic, Issue: 123

*/


#include <iostream> // Include the iostream library to enable input and output stream operations.
#include <string> // Include the string library to work with strings.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Printable {
public:
    virtual void print() = 0; // Pure virtual function to print the details of the object (no implementation).
};

// Derive a class 'Book' from the base class 'Printable' to represent books.
class Book : public Printable {
private:
    string title; // Private member variable to store the title of the book.
    string author; // Private member variable to store the author of the book.

public:
    Book(const string& t, const string& a) : title(t), author(a) {
        // Constructor to initialize the Book object with the provided title and author.
    }

    void print() override {
        cout << "Book Title: " << title << ", Author: " << author << endl;
        // Implementation of the 'print()' method to display the title and author of the book.
    }
};

// Derive a class 'Magazine' from the base class 'Printable' to represent magazines.
class Magazine : public Printable {
private:
    string name; // Private member variable to store the name of the magazine.
    int issue; // Private member variable to store the issue number of the magazine.

public:
    Magazine(const string& n, int i) : name(n), issue(i) {
        // Constructor to initialize the Magazine object with the provided name and issue number.
    }

    void print() override {
        cout << "Magazine Name: " << name << ", Issue: " << issue << endl;
        // Implementation of the 'print()' method to display the name and issue number of the magazine.
    }
};

int main() {
    Printable* print1 = new Book("The Alchemist", "Paulo Coelho");
    Printable* print2 = new Magazine("National Geographic", 123);

    print1->print(); // Dynamic binding to Book's print() - Polymorphism.
    print2->print(); // Dynamic binding to Magazine's print() - Polymorphism.

    delete print1; // Deallocate the memory for the Book object.
    delete print2; // Deallocate the memory for the Magazine object.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of abstract classes and dynamic binding using a common base class Printable. The Printable class is an abstract class because it defines a pure virtual function print(), which has no implementation in the base class and is intended to be overridden in derived classes.

Two derived classes, Book and Magazine, inherit from the Printable base class. The Book class represents books and provides an implementation for the print() method to display the title and author of the book. The Magazine class represents magazines and provides an implementation for the print() method to display the name and issue number of the magazine.

In the main() function, two pointers print1 and print2 of type Printable are created and initialized with the addresses of dynamically allocated objects of the Book and Magazine classes, respectively. This demonstrates polymorphism through dynamic binding, where the correct print() method from the respective derived class is invoked based on the object type.

When print1->print() is called, the print() method of the Book class is executed, displaying the details of the book. Similarly, when print2->print() is called, the print() method of the Magazine class is executed, displaying the details of the magazine.

After printing the details, the dynamically allocated memory for the Book and Magazine objects is deallocated using the delete keyword to avoid memory leaks. Finally, the program exits with a success status.

*/


