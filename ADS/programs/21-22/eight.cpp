/*
 Create classes 'Base' and 'Derived' with their own destructors.
 Instantiate objects of both classes and observe the destructor order during object destruction.

 Input:
Derived d;

 Output:

Creating Derived object...
Base constructor called
Derived constructor called
Leaving scope, object will be destructed...
Derived destructor called
Base destructor called

 */

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor called" << endl;
    }

    ~Base() {
        cout << "Base destructor called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor called" << endl;
    }

    ~Derived() {
        cout << "Derived destructor called" << endl;
    }
};

int main() {
    cout << "Creating Derived object..." << endl;
    Derived d; // Constructor order: Base -> Derived
    cout << "Leaving scope, object will be destructed..." << endl;

    return 0;
}

/*
Base Class:
The Base class is a base class with a default constructor and destructor. The constructor outputs a message "Base constructor called" to the console when an object of the Base class is created. Similarly, the destructor outputs a message "Base destructor called" to the console when an object of the Base class is destroyed.

Derived Class:
The Derived class is a derived class of the Base class. It inherits from the Base class using the public access specifier. The Derived class also has a default constructor and destructor. The constructor outputs a message "Derived constructor called" to the console when an object of the Derived class is created. Similarly, the destructor outputs a message "Derived destructor called" to the console when an object of the Derived class is destroyed.

In the main() function, we demonstrate the use of the Base and Derived classes by creating a Derived object d. When the Derived object is created, its constructor is called. Since the Derived class is derived from the Base class, the Base constructor is called first, and then the Derived constructor is called. The constructor order is: Base -> Derived.

When the program execution reaches the end of the main() function and the Derived object d goes out of scope, it will be automatically destructed. The destructor order is: Derived -> Base. This means that the destructor of the Derived class is called first, and then the destructor of the Base class is called.

*/




