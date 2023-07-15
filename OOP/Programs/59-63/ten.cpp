/*
Create a diamond-shaped hierarchy of classes, where each class contains an integer data member.
Implement a method in each class to return the sum of its data member and the data member of its base class.
*/

#include <iostream>

// Base class
class Shape {
protected:
    int x;

public:
    Shape(int val) : x(val) {}

    int getX() const { return x; }
};

// Derived class A
class A : virtual public Shape {
public:
    A(int val) : Shape(val) {}

    int sum() const {
        return getX();
    }
};

// Derived class B
class B : virtual public Shape {
public:
    B(int val) : Shape(val) {}

    int sum() const {
        return getX();
    }
};

// Derived class C
class C : public A, public B {
public:
    C(int val) : Shape(val), A(val), B(val) {}

    int sum() const {
        return A::sum() + B::sum() + getX();
    }
};

int main() {
    C objC(5);
    std::cout << "Sum in C: " << objC.sum() << std::endl;
    return 0;
}
