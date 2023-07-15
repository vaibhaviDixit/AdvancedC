/*
 Create a C++ program to calculate the distance between two points using friend functions and handle constant objects properly.

 Input: p1(2.0, 3.0)
        p2(5.0, 7.0)
 Output: Distance between two points: 5

*/

#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) : x(x), y(y) {}

    friend double calculateDistance(const Point& p1, const Point& p2);
};

double calculateDistance(const Point& p1, const Point& p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    const Point p1(2.0, 3.0);
    const Point p2(5.0, 7.0);
    double distance = calculateDistance(p1, p2);

    std::cout << "Distance between two points: " << distance << std::endl;

    return 0;
}

/*
The program defines a class Point with private data members x and y.
It also declares a friend function calculateDistance that calculates the distance between two points.
The program then demonstrates how to use constant objects and friend functions to calculate the distance between two points.
*/
