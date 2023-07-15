/*
Implement a base class "Person" with two derived classes "Employee" and "Student."
Create another class "Graduate" derived from both "Employee" and "Student." Ensure that the base class "Person"
acts as a virtual base class to avoid ambiguity in "Graduate" due to multiple inheritance

*/

#include <iostream>
#include <string>

// Virtual Base class Person
class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}

    void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

// Derived class Employee
class Employee : virtual public Person {
protected:
    int employeeID;

public:
    Employee(const std::string& n, int id) : Person(n), employeeID(id) {}

    void display() const {
        Person::display();
        std::cout << "Employee ID: " << employeeID << std::endl;
    }
};

// Derived class Student
class Student : virtual public Person {
protected:
    int studentID;

public:
    Student(const std::string& n, int id) : Person(n), studentID(id) {}

    void display() const {
        Person::display();
        std::cout << "Student ID: " << studentID << std::endl;
    }
};

// Derived class Graduate
class Graduate : public Employee, public Student {
public:
    Graduate(const std::string& n, int empID, int stuID)
        : Person(n), Employee(n, empID), Student(n, stuID) {}

    void display() const {
        Employee::display();
        Student::display();
    }
};

int main() {
    Graduate graduate("John Doe", 12345, 98765);
    graduate.display();

    return 0;
}

/*
This program demonstrates the use of virtual base class to avoid ambiguity in multiple inheritance.
The base class "Person" is made virtual by using the "virtual" keyword while inheriting it in both "Employee" and "Student" classes.
The "Graduate" class is then derived from both "Employee" and "Student" classes, and it can access the "Person" class properties without
any ambiguity.

*/

