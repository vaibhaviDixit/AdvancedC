/*
Create a base class "Shape" with two derived classes "Circle" and "Triangle."
Implement an abstract class "Drawing" with pure virtual functions to draw shapes and demonstrate the use of multiple inheritance.
*/

#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a Circle" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() {
        cout << "Drawing a Triangle" << endl;
    }
};

class Drawing : public Circle, public Triangle {
public:
    // Must implement draw() due to multiple inheritance
    void draw() {
        cout << "Drawing using Drawing class" << endl;
    }
};

int main() {
    Drawing drawing;
    drawing.draw();

    return 0;
}
