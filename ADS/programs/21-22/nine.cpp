/*
Create a class to represent student details such as name, roll number, and marks.
Implement a function to calculate the average marks of a student.

Input:
 marks1={90, 85, 92, 78, 88
 student1("John Doe", 101, marks1)

Output:

Name: John Doe
Roll Number: 101
Marks: 90 85 92 78 88
Average Marks: 86.6

*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
#include <string> // Include the string library to work with strings.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Student {
private:
    string name; // Private member variable to store the name of the student.
    int rollNumber; // Private member variable to store the roll number of the student.
    double marks[5]; // Private member array to store the marks of the student in five subjects.

public:
    Student(string n, int roll, double m[5]) : name(n), rollNumber(roll) {
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i]; // Constructor to initialize the Student object with provided name, roll number, and marks.
        }
    }

    double calculateAverageMarks() {
        double sum = 0; // Variable to store the sum of the marks.
        for (int i = 0; i < 5; i++) {
            sum += marks[i]; // Calculate the sum of all the marks.
        }
        return sum / 5; // Return the average marks by dividing the sum by the number of subjects (5).
    }

    void display() {
        cout << "Name: " << name << endl; // Display the name of the student.
        cout << "Roll Number: " << rollNumber << endl; // Display the roll number of the student.
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " "; // Display the marks of the student in five subjects.
        }
        cout << endl;
    }
};

int main() {
    double marks1[5] = {90, 85, 92, 78, 88}; // Create an array with marks for student1.
    Student student1("John Doe", 101, marks1); // Create a Student object for student1 with name, roll number, and marks.

    double marks2[5] = {80, 75, 82, 88, 90}; // Create an array with marks for student2.
    Student student2("Jane Smith", 102, marks2); // Create a Student object for student2 with name, roll number, and marks.

    student1.display(); // Display the details of student1.
    cout << "Average Marks: " << student1.calculateAverageMarks() << endl; // Display the average marks of student1.

    student2.display(); // Display the details of student2.
    cout << "Average Marks: " << student2.calculateAverageMarks() << endl; // Display the average marks of student2.

    return 0; // Exit the program with a success status.
}

/*
This C++ program defines a Student class to represent students and their marks. It has private member variables name, rollNumber, and marks, which store the name, roll number, and marks of the student, respectively. The class provides a constructor to initialize a Student object with the provided name, roll number, and marks.

The class also has a calculateAverageMarks member function that calculates the average marks of the student by adding all the marks and dividing by the number of subjects (5).

In the main function, it creates two Student objects, student1 and student2, with their respective names, roll numbers, and marks. It then displays the details of both students and their average marks on the console using the display and calculateAverageMarks member functions, respectively.

*/


