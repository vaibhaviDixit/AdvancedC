/*
Create a class representing a point and overload the '>' operator to compare two points based on their distance from the origin.

Input: p1(3, 4)
       p2(5, 12)

Output: (5, 12) is farther from the origin than (3, 4)

*/

#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double xx, double yy) : x(xx), y(yy) {}

    // Overloading the '>' operator
    bool operator>(const Point& other) {
        double distance1 = sqrt(x * x + y * y);
        double distance2 = sqrt(other.x * other.x + other.y * other.y);
        return distance1 > distance2;
    }

    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3, 4);
    Point p2(5, 12);

    if (p1 > p2) {
        p1.display();
        cout << " is farther from the origin than ";
        p2.display();
    } else {
        p2.display();
        cout << " is farther from the origin than ";
        p1.display();
    }
    cout << endl;

    return 0;
}

/*
This program creates a class Point to represent a 2D point.
The '>' operator is overloaded to compare two points based on their distance from the origin.
The display() function is used to print which point is farther from the origin.

*/


