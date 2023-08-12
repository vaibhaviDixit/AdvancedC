/*
Create a class called 'Rectangle' with attributes 'length' and 'width'.
Implement a copy constructor to create a new rectangle from an existing one.

Input:
 Rectangle r1(5, 3);
 Rectangle r2 = r1;

 r1.display();
 r2.display();

Output:
Length: 5, Width: 3
Length: 5, Width: 3

*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    Rectangle(const Rectangle& other) {
        length = other.length;
        width = other.width;
    }

    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    Rectangle r1(5, 3);
    Rectangle r2 = r1; // Copy constructor called

    r1.display();
    r2.display();

    return 0;
}

/*
In this C++ program, we define a class Rectangle to represent a rectangle with private attributes length and width. The class has a constructor that takes two parameters l (length) and w (width) to initialize the length and width attributes of the objects.

The Rectangle class also has a copy constructor, which is a special constructor that is called when a new object is created as a copy of an existing object. In this case, the copy constructor takes a reference to another Rectangle object (const Rectangle& other) as its parameter. Inside the copy constructor, we copy the length and width attributes of the other object to initialize the attributes of the newly created object.

The class also has a member function display() that prints the length and width of the rectangle to the console.

In the main() function, we create a Rectangle object r1 with length 5 and width 3 using the constructor. Then, we create another Rectangle object r2 and initialize it as a copy of r1 using the copy constructor (i.e., Rectangle r2 = r1;). This results in the length and width of r2 being the same as r1.

Finally, we call the display() function on both r1 and r2 to print their length and width to the console.

*/




