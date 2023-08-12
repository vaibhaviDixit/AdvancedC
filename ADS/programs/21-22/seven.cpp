/* Create a base class 'Shape' with an attribute 'name'.
 Create a derived class 'Rectangle' with additional attributes 'length' and 'width'.
 Implement constructors, copy constructor, copy assignment operator, and destructor for deep copy.

 Input:
    Rectangle r1("Rectangle", 5, 3);
    r1.display();

    Rectangle r2 = r1;
    r2.display();

    Rectangle r3("New Rectangle");
    r3 = r1;
    r3.display();

 Output:

 Name: Rectangle
 Length: 5, Width: 3
 Name: Rectangle
 Length: 5, Width: 3
 Name: Rectangle
 Length: 5, Width: 3

 */

#include <iostream>
#include <cstring>
using namespace std;

class Shape {
protected:
    char* name;

public:
    Shape(const char* n = "") {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Shape(const Shape& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    Shape& operator=(const Shape& other) {
        if (this != &other) {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }

    virtual void display() {
        cout << "Name: " << name << endl;
    }

    virtual ~Shape() {
        delete[] name;
    }
};

class Rectangle : public Shape {
private:
    int length;
    int width;

public:
    Rectangle(const char* n = "", int l = 0, int w = 0) : Shape(n), length(l), width(w) {}

    Rectangle(const Rectangle& other) : Shape(other), length(other.length), width(other.width) {}

    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            Shape::operator=(other);
            length = other.length;
            width = other.width;
        }
        return *this;
    }

    void display() override {
        Shape::display();
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    ~Rectangle() {}
};

int main() {
    Rectangle r1("Rectangle", 5, 3);
    r1.display();

    Rectangle r2 = r1; // Copy constructor called
    r2.display();

    Rectangle r3("New Rectangle");
    r3 = r1; // Copy assignment operator called
    r3.display();

    return 0;
}

/*
Shape Class:
The Shape class is a base class that represents a generic shape. It has a protected attribute name, which is a dynamically allocated C-string (character array). The constructor of the Shape class takes a const char* n as its parameter and initializes the name attribute by dynamically allocating memory for the C-string and copying the contents of the input C-string n into it using strcpy.
The Shape class also has a copy constructor and a copy assignment operator. Both the copy constructor and copy assignment operator perform a deep copy of the name attribute to ensure that each object has its own separate copy of the C-string.

The display() function is a virtual function in the Shape class, indicating that it can be overridden by derived classes. The display() function in the Shape class prints the name of the shape to the console.

The destructor of the Shape class is virtual and responsible for releasing the dynamically allocated memory when the object is destroyed. It uses delete[] to deallocate the memory assigned to the C-string.

Rectangle Class:
The Rectangle class is a derived class of the Shape class. It represents a rectangle and extends the Shape class with additional attributes length and width.
The Rectangle class has its own constructor, copy constructor, and copy assignment operator. The constructor takes three parameters: a const char* n for the name of the rectangle, and two integers l and w for the length and width of the rectangle, respectively. The constructor initializes the name attribute using the constructor of the base class (Shape(n)) and sets the length and width attributes.

The copy constructor of the Rectangle class also calls the copy constructor of the base class (Shape(other)) to create a deep copy of the name attribute, and then it sets the length and width attributes.

The copy assignment operator of the Rectangle class first calls the copy assignment operator of the base class (Shape::operator=(other)) to copy the name attribute, and then it sets the length and width attributes.

The display() function is overridden in the Rectangle class using the override keyword, which indicates that it is a virtual function being redefined in the derived class. The display() function in the Rectangle class first calls the display() function of the base class (Shape::display()) to print the name of the shape and then prints the length and width of the rectangle to the console.

In the main() function, we demonstrate the use of the Rectangle class by creating three Rectangle objects (r1, r2, and r3). We initialize r1 with the name "Rectangle" and length and width 5 and 3, respectively. Then, we create r2 as a copy of r1 using the copy constructor. We create r3 with the name "New Rectangle" and then use the copy assignment operator to assign r1 to r3. Finally, we display the details of all three objects using the display() function.

*/
