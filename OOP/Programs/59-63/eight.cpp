/*
Create a program to calculate the area of different geometric shapes.
The program should support calculating the area of rectangles, circles, and triangles.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Base class: Shape
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function to calculate the area
};

// Derived class: Rectangle (inherits from Shape)
class Rectangle : public Shape {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area()  {
        return width * height;
    }
};

// Derived class: Circle (inherits from Shape)
class Circle : public Shape {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() {
        return M_PI * pow(radius, 2);
    }
};

// Derived class: Triangle (inherits from Shape)
class Triangle : public Shape {
protected:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    double width, height, radius, base, triHeight;

    cout << "Enter the width and height of the rectangle: ";
    cin >> width >> height;
    Rectangle rectangle(width, height);
    cout << "Area of the rectangle: " << rectangle.area() << endl;

    cout << "Enter the radius of the circle: ";
    cin >> radius;
    Circle circle(radius);
    cout << "Area of the circle: " << circle.area() << endl;

    cout << "Enter the base and height of the triangle: ";
    cin >> base >> triHeight;
    Triangle triangle(base, triHeight);
    cout << "Area of the triangle: " << triangle.area() << endl;

    return 0;
}
