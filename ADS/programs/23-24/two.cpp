/*
Create an abstract class for shapes with a pure virtual function to calculate the area. Implement derived classes for different shapes
and calculate their areas.

Input:
Shape* shape1 = new Rectangle(5, 3)
Shape* shape2 = new Circle(2)
shape1->area()
shape2->area()

Output:

Area of Rectangle: 15
Area of Circle: 12.56

*/


#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Shape {
public:
    virtual double area() const = 0; // Pure virtual function

    virtual ~Shape() {} // Virtual destructor to ensure proper cleanup when derived objects are deleted.
};

class Rectangle : public Shape {
private:
    double length; // Private member variable to store the length of the rectangle.
    double width; // Private member variable to store the width of the rectangle.

public:
    Rectangle(double l, double w) : length(l), width(w) {} // Constructor to initialize the Rectangle object with the provided length and width.

    double area() const override { // Implementation of the area() method from the base class.
        return length * width; // Calculate and return the area of the rectangle.
    }
};

class Circle : public Shape {
private:
    double radius; // Private member variable to store the radius of the circle.

public:
    Circle(double r) : radius(r) {} // Constructor to initialize the Circle object with the provided radius.

    double area() const override { // Implementation of the area() method from the base class.
        return 3.14 * radius * radius; // Calculate and return the area of the circle.
    }
};

int main() {
    Shape* shape1 = new Rectangle(5, 3); // Create a pointer to a Shape object and assign it to a Rectangle object with length 5 and width 3.
    Shape* shape2 = new Circle(2); // Create another pointer to a Shape object and assign it to a Circle object with radius 2.

    cout << "Area of Rectangle: " << shape1->area() << endl; // Call the area() method of the Rectangle object through the base class pointer.
    cout << "Area of Circle: " << shape2->area() << endl; // Call the area() method of the Circle object through the base class pointer.

    delete shape1; // Delete the dynamically allocated memory for the Rectangle object.
    delete shape2; // Delete the dynamically allocated memory for the Circle object.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of polymorphism and dynamic binding using an abstract base class Shape and two derived classes Rectangle and Circle.

The Shape class is an abstract base class that contains a pure virtual function area(). A pure virtual function is a function without any implementation in the base class, and it is intended to be overridden in the derived classes. Classes containing pure virtual functions are called abstract classes, and they cannot be instantiated directly; they can only be used as base classes for derived classes.

The Rectangle class is a derived class from Shape and provides an implementation for the area() method, calculating the area of a rectangle using its length and width.

The Circle class is another derived class from Shape and provides an implementation for the area() method, calculating the area of a circle using its radius.

In the main() function, two Shape pointers shape1 and shape2 are created and dynamically allocated to Rectangle and Circle objects, respectively. Since area() is a virtual function in the base class Shape, when the area() method is called through the base class pointers shape1 and shape2, the appropriate implementation (based on the actual object type) is invoked, i.e., dynamic binding takes place.

The program prints the areas of the rectangle and circle using the area() method through the base class pointers. After the calculations, the dynamically allocated memory for the objects is properly deallocated using delete to avoid memory leaks.

*/


