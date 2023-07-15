/*
Write a CPP program to include 3D shapes - sphere and cone - and calculate their volumes using method overriding.
*/

#include <iostream>
#include <cmath>

class Shape3D {
public:
    virtual double calculateVolume() const {
        return 0.0;
    }
};

class Sphere : public Shape3D {
private:
    double radius;
public:
    Sphere(double r) : radius(r) {}

    double calculateVolume() const override {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
};

class Cone : public Shape3D {
private:
    double radius, height;
public:
    Cone(double r, double h) : radius(r), height(h) {}

    double calculateVolume() const override {
        return (1.0 / 3.0) * M_PI * pow(radius, 2) * height;
    }
};

int main() {
    Shape3D* shape1 = new Sphere(5);
    Shape3D* shape2 = new Cone(3, 7);

    std::cout << "Volume of Sphere: " << shape1->calculateVolume() << std::endl;
    std::cout << "Volume of Cone: " << shape2->calculateVolume() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
