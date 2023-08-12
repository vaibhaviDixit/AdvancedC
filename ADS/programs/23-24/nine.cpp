/*
Implement a shape hierarchy with a base class "Shape" and derived classes "Rectangle" and "Square." The base class should have virtual functions for calculating area and perimeter, which are overridden in the
derived classes.

Input:
Rectangle r(4, 6)
Square s(5)
r.area(), r.perimeter()
s.area(),s.perimeter()

Output:
Rectangle Area: 24, Perimeter: 20
Square Area: 25, Perimeter: 20


*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Shape {
public:
    virtual double area() const = 0; // Pure virtual function to calculate the area of the shape (no implementation).
    virtual double perimeter() const = 0; // Pure virtual function to calculate the perimeter of the shape (no implementation).
};

// Derive a class 'Rectangle' from the base class 'Shape' to represent rectangles.
class Rectangle : public Shape {
private:
    double length; // Private member variable to store the length of the rectangle.
    double width; // Private member variable to store the width of the rectangle.

public:
    Rectangle(double l, double w) : length(l), width(w) {
        // Constructor to initialize the Rectangle object with the provided length and width.
    }

    double area() const override {
        return length * width; // Implementation of the 'area()' method to calculate the area of the rectangle.
    }

    double perimeter() const override {
        return 2 * (length + width); // Implementation of the 'perimeter()' method to calculate the perimeter of the rectangle.
    }
};

// Derive a class 'Square' from the base class 'Shape' to represent squares.
class Square : public Shape {
private:
    double side; // Private member variable to store the side length of the square.

public:
    Square(double s) : side(s) {
        // Constructor to initialize the Square object with the provided side length.
    }

    double area() const override {
        return side * side; // Implementation of the 'area()' method to calculate the area of the square.
    }

    double perimeter() const override {
        return 4 * side; // Implementation of the 'perimeter()' method to calculate the perimeter of the square.
    }
};

int main() {
    Rectangle r(4, 6); // Create a Rectangle object named 'r' with the provided length 4 and width 6.
    Square s(5); // Create a Square object named 's' with the provided side length 5.

    cout << "Rectangle Area: " << r.area() << ", Perimeter: " << r.perimeter() << endl;
    // Display the area and perimeter of the rectangle using the overridden 'area()' and 'perimeter()' methods of the Rectangle class.

    cout << "Square Area: " << s.area() << ", Perimeter: " << s.perimeter() << endl;
    // Display the area and perimeter of the square using the overridden 'area()' and 'perimeter()' methods of the Square class.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of abstract classes and inheritance to calculate the area and perimeter of shapes.
The base class 'Shape' is an abstract class that defines two pure virtual functions: 'area()' and 'perimeter()'.
The pure virtual functions have no implementation in the base class and must be overridden by derived classes.

*/
