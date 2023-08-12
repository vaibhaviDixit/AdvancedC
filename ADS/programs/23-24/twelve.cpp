/*
Create a base class Shape with a virtual function draw(). Implement derived classes Circle and Square that override the draw() function
to draw their respective shapes on the screen.

Input:
    Shape* shape1 = new Circle();
    Shape* shape2 = new Square();

    shape1->draw();
    shape2->draw();

Output:

Drawing a circle.
Drawing a square.

*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a generic shape." << endl;
        // Virtual function 'draw()' to draw a generic shape (has a default implementation).
        // The 'virtual' keyword allows dynamic binding to the appropriate derived class implementation.
    }
};

// Derive a class 'Circle' from the base class 'Shape' to represent circles.
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
        // Override the 'draw()' method to draw a circle.
        // This method will be invoked dynamically through dynamic binding based on the object type.
    }
};

// Derive a class 'Square' from the base class 'Shape' to represent squares.
class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing a square." << endl;
        // Override the 'draw()' method to draw a square.
        // This method will be invoked dynamically through dynamic binding based on the object type.
    }
};

int main() {
    Shape* shape1 = new Circle(); // Create a Shape pointer pointing to a dynamically allocated Circle object.
    Shape* shape2 = new Square(); // Create a Shape pointer pointing to a dynamically allocated Square object.

    shape1->draw(); // Dynamic binding to Circle's draw() - Polymorphism.
    shape2->draw(); // Dynamic binding to Square's draw() - Polymorphism.

    delete shape1; // Deallocate the memory for the Circle object.
    delete shape2; // Deallocate the memory for the Square object.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of polymorphism using virtual functions and dynamic binding.
The program defines a base class 'Shape' with a virtual function 'draw()'. The 'draw()' method is intended to be overridden in derived
classes.
Two derived classes, 'Circle' and 'Square', inherit from the 'Shape' base class and override the 'draw()' method to draw specific shapes.

*/


