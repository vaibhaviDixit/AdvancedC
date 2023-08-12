/*
Create a class called 'Person' with attributes 'name' and 'age'.
Implement constructors, destructor, and display function to show the details of the person.

Input:
Person p1("Alice", 25);
Person p2("Bob", 30);

p1.display();
p2.display();

Output:

Name: Alice, Age: 25
Name: Bob, Age: 30
Destructor called for Bob
Destructor called for Alice

*/


#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    ~Person() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Person p1("Alice", 25);
    Person p2("Bob", 30);

    p1.display();
    p2.display();

    return 0;
}

/*
In this C++ program, we define a class Person with private attributes name and age. The class has a constructor that takes two parameters n (name) and a (age) to initialize the name and age attributes of the objects. The class also has a member function display() that prints the name and age of the person to the console.

The Person class also has a destructor (~Person()), which is automatically called when an object of the class is destroyed. In this case, the destructor simply prints a message indicating that the destructor is called for the given name.

In the main() function, we create two Person objects, p1 and p2, with the names "Alice" and "Bob", and ages 25 and 30, respectively. Then we call the display() function on both objects to print their information to the console.

When the program finishes execution, the destructor for each Person object is automatically called, printing a message indicating the destruction of each object.

*/
