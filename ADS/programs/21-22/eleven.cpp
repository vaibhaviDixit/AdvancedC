/*Create a class called 'Point' to represent a 2D point.
 Implement multiple copy constructors and observe their usage.

 Input:
    Point p1(5, 3);
    Point p2 = p1;
    Point p3(p1);

    Point p4;
    p4 = p1;

    p1.display();
    p2.display();
    p3.display();
    p4.display();

 Output:

X: 5, Y: 3
X: 5, Y: 3
X: 5, Y: 3
X: 5, Y: 3

*/

#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    Point(const Point& other) : x(other.x), y(other.y) {}

    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    void display() {
        cout << "X: " << x << ", Y: " << y << endl;
    }
};

int main() {
    Point p1(5, 3);
    Point p2 = p1; // Copy constructor 1 called
    Point p3(p1); // Copy constructor 2 called

    Point p4;
    p4 = p1; // Copy assignment operator called

    p1.display();
    p2.display();
    p3.display();
    p4.display();

    return 0;
}

/*
The Point class has the following member functions:

Constructor: The constructor takes two optional parameters a (x-coordinate) and b (y-coordinate) with default values of 0. If no values are provided during object creation, the default values will be used to initialize the attributes.

Copy Constructor: The copy constructor is used to create a new Point object as a copy of an existing Point object. It takes a reference to another Point object (const Point& other) as its parameter. Inside the copy constructor, we perform a shallow copy by directly copying the values of the x and y attributes from the other object to the newly created object.

Copy Assignment Operator: The copy assignment operator (operator=) allows assignment of one Point object to another. It takes a reference to another Point object (const Point& other) as its parameter. The copy assignment operator first checks whether the two objects are not the same (to avoid self-assignment) and then assigns the values of the x and y attributes from the other object to the current object.

display function: This function is used to display the coordinates of the point in the format "X: x-coordinate, Y: y-coordinate" to the console.

In the main() function, we demonstrate the use of the Point class by creating four Point objects (p1, p2, p3, and p4). We initialize p1 with the coordinates (5, 3). Then, we create p2 as a copy of p1 using the copy constructor. We also create p3 using a different syntax to call the copy constructor. Next, we create p4 without any initialization and then use the copy assignment operator to assign p1 to p4. Finally, we display the coordinates of all four objects using the display() function.

*/


