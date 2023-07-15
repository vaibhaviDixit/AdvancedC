/*
Implement a base class "Shape" with two derived classes "Circle" and "Rectangle." \
Create a class "Square" derived from both "Circle" and "Rectangle" to calculate and display the area and perimeter of a square.
*/

#include <iostream>

// Base class Shape
class Shape {
protected:
    double area;

public:
    virtual void calculateArea() = 0;
    virtual void display() const = 0;
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void calculateArea() override {
        area = 3.14159 * radius * radius;
    }

    void display() const override {
        std::cout << "Circle Area: " << area << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    void calculateArea() override {
        area = length * width;
    }

    void display() const override {
        std::cout << "Rectangle Area: " << area << std::endl;
    }
};

// Derived class Square
class Square : public Circle, public Rectangle {
public:
    Square(double s) : Circle(s), Rectangle(s, s) {}

    void calculateArea() override {
        Circle::calculateArea();
    }

    void display() const override {
        Circle::display();
    }
};

int main() {
    Square square(5.0);
    square.calculateArea();
    square.display();

    return 0;
}

/*
This program demonstrates the diamond inheritance problem, which occurs when a class inherits from two classes that have a common base class.
The "Square" class is derived from both "Circle" and "Rectangle" classes, which, in turn, are derived from the "Shape" class.
This causes ambiguity in accessing the "area" member.
To resolve this ambiguity, we explicitly call the "calculateArea" and "display" functions of the "Circle" class within the "Square" class.

*/

