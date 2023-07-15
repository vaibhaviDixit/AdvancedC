/*
Create a Student class with attributes name and age.
Implement a function that takes two Student objects as parameters and returns a new Student object with
the name and age of the older student.
*/

#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;

    Student(const std::string& n, int a) : name(n), age(a) {}
};

// Function to find the older student and return a new Student
Student findOlderStudent(const Student& s1, const Student& s2) {
    if (s1.age >= s2.age) {
        return Student(s1.name, s1.age);
    } else {
        return Student(s2.name, s2.age);
    }
}

int main() {
    Student student1("Alice", 21);
    Student student2("Bob", 23);

    Student olderStudent = findOlderStudent(student1, student2);

    std::cout << "Older Student: " << olderStudent.name << ", Age: " << olderStudent.age << std::endl;

    return 0;
}
