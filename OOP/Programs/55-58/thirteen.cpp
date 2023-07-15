/*
Implement a base class Rectangle with attributes length and width and a method to calculate the area.
Create a derived class Box from Rectangle with an additional height attribute and a method to calculate the volume of the box.
*/
#include <iostream>

class Rectangle {
protected:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() {
        return length * width;
    }
};

class Box : public Rectangle {
private:
    double height;
public:
    Box(double l, double w, double h) : Rectangle(l, w), height(h) {}

    double calculateVolume() {
        return calculateArea() * height;
    }
};

int main() {
    double length, width, height;
    std::cout << "Enter the length of the box: ";
    std::cin >> length;
    std::cout << "Enter the width of the box: ";
    std::cin >> width;
    std::cout << "Enter the height of the box: ";
    std::cin >> height;

    Box box(length, width, height);
    std::cout << "Box's Volume: " << box.calculateVolume() << std::endl;

    return 0;
}
