/*
Create a class called 'Student' with attributes 'name' and 'age'.
Create a class called 'Classroom' with an array of 'Student' objects.
Implement a copy constructor for deep copy of the array.

Input:
    Classroom c1(3);
    c1.display();

    Classroom c2 = c1; // Deep copy
    c2.display();

Output:

Name: , Age: 0
Name: , Age: 0
Name: , Age: 0
Name: , Age: 0
Name: , Age: 0
Name: , Age: 0


*/

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(const string& n = "", int a = 0) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Classroom {
private:
    Student* students;
    int numStudents;

public:
    Classroom(int num) : numStudents(num) {
        students = new Student[numStudents];
    }

    Classroom(const Classroom& other) {
        numStudents = other.numStudents;
        students = new Student[numStudents];
        for (int i = 0; i < numStudents; i++) {
            students[i] = other.students[i];
        }
    }

    void display() {
        for (int i = 0; i < numStudents; i++) {
            students[i].display();
        }
    }

    ~Classroom() {
        delete[] students;
    }
};

int main() {
    Classroom c1(3);
    c1.display();

    Classroom c2 = c1; // Deep copy
    c2.display();

    return 0;
}

/*
Student Class:
The Student class represents a student with attributes name (string) and age (integer). The class has a constructor that takes two optional parameters n (name) and a (age) with default values. If no values are provided during object creation, the default values will be used to initialize the attributes. The class also has a member function display() that prints the name and age of the student to the console.

Classroom Class:
The Classroom class represents a classroom of students. It has private attributes students, which is a dynamic array of Student objects, and numStudents, which stores the number of students in the classroom. The constructor of the Classroom class takes an integer num as its parameter to initialize the number of students and dynamically allocates memory for the students array using new Student[numStudents].

The Classroom class also has a copy constructor, which is used to create a new Classroom object as a copy of an existing Classroom object. The copy constructor takes a reference to another Classroom object (const Classroom& other) as its parameter. Inside the copy constructor, we create a deep copy of the students array by allocating new memory for the students array and copying the Student objects from the other object's students array.

The Classroom class has a member function display() that prints the details of all students in the classroom by calling the display() function of each Student object in the students array.

In the main() function, we demonstrate the use of the Classroom class by creating a Classroom object c1 with 3 students. We display the details of all students in c1 using the display() function. Then, we create another Classroom object c2 as a copy of c1 using the copy constructor. We display the details of all students in c2 as well.

*/


