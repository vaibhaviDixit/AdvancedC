/*
Create a base class Circle with attributes radius and methods to calculate area and circumference.
Derive a class Cylinder from Circle and add a height attribute and a method to calculate the volume of the cylinder.
*/

#include <iostream>
#include <cmath>

class Circle {
protected:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() {
        return M_PI * radius * radius;
    }

    double calculateCircumference() {
        return 2 * M_PI * radius;
    }
};

class Cylinder : public Circle {
private:
    double height;
public:
    Cylinder(double r, double h) : Circle(r), height(h) {}

    double calculateVolume() {
        return calculateArea() * height;
    }
};

int main() {
    double radius, height;
    std::cout << "Enter the radius of the cylinder: ";
    std::cin >> radius;
    std::cout << "Enter the height of the cylinder: ";
    std::cin >> height;

    Cylinder cylinder(radius, height);
    std::cout << "Cylinder's Volume: " << cylinder.calculateVolume() << std::endl;

    return 0;
}
