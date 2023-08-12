/*
Implement a shape hierarchy with a base class "Shape" and derived classes "Circle" and "Rectangle." The base class should have virtual
functions for calculating area and perimeter, which are overridden in the derived classes.

Input:
Circle c(5);
Rectangle r(4, 6);
c.area()
r.area()

Output:
Circle Area: 78.5, Perimeter: 31.4
Rectangle Area: 24, Perimeter: 20

*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Shape {
public:
    virtual double area() const = 0; // Pure virtual function to calculate the area of a shape.
    virtual double perimeter() const = 0; // Pure virtual function to calculate the perimeter of a shape.
};

class Circle : public Shape {
private:
    double radius; // Private member variable to store the radius of the circle.

public:
    Circle(double r) : radius(r) {} // Constructor to initialize the Circle object with the provided radius.

    double area() const override { // Implementation of the area() method from the base class.
        return 3.14 * radius * radius; // Calculate and return the area of the circle using the formula π * r^2.
    }

    double perimeter() const override { // Implementation of the perimeter() method from the base class.
        return 2 * 3.14 * radius; // Calculate and return the perimeter of the circle using the formula 2 * π * r.
    }
};

class Rectangle : public Shape {
private:
    double length; // Private member variable to store the length of the rectangle.
    double width; // Private member variable to store the width of the rectangle.

public:
    Rectangle(double l, double w) : length(l), width(w) {} // Constructor to initialize the Rectangle object with the provided length and width.

    double area() const override { // Implementation of the area() method from the base class.
        return length * width; // Calculate and return the area of the rectangle using the formula length * width.
    }

    double perimeter() const override { // Implementation of the perimeter() method from the base class.
        return 2 * (length + width); // Calculate and return the perimeter of the rectangle using the formula 2 * (length + width).
    }
};

int main() {
    Circle c(5); // Create a Circle object named 'c' with a radius of 5.
    Rectangle r(4, 6); // Create a Rectangle object named 'r' with a length of 4 and a width of 6.

    cout << "Circle Area: " << c.area() << ", Perimeter: " << c.perimeter() << endl;
    // Display the area and perimeter of the circle using the area() and perimeter() methods of the Circle class.

    cout << "Rectangle Area: " << r.area() << ", Perimeter: " << r.perimeter() << endl;
    // Display the area and perimeter of the rectangle using the area() and perimeter() methods of the Rectangle class.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of abstraction and polymorphism using an abstract base class Shape and two derived classes Circle and Rectangle.

The Shape class is an abstract base class that contains two pure virtual functions, area() and perimeter(). As with the previous examples, pure virtual functions are intended to be overridden in the derived classes, making Shape an abstract class that cannot be instantiated directly.

The Circle class is a derived class from Shape and provides implementations for the area() and perimeter() methods specific to a circle. It calculates the area and perimeter of a circle based on its radius.

The Rectangle class is another derived class from Shape and provides implementations for the area() and perimeter() methods specific to a rectangle. It calculates the area and perimeter of a rectangle based on its length and width.

In the main() function, two objects c and r of type Circle and Rectangle, respectively, are created and initialized with the provided parameters. The program then calculates and displays the area and perimeter of the circle and rectangle using the area() and perimeter() methods of their respective classes.

*/

