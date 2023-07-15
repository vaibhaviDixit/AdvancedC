/*
Create a class Student with attributes name, rollNumber, and an array marks to store marks in five subjects.
Implement methods to calculate the total and average marks of the student.

*/

#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int rollNumber;
    int marks[5];

public:
    Student(const std::string& n, int roll, const int* m) : name(n), rollNumber(roll) {
        for (int i = 0; i < 5; ++i)
            marks[i] = m[i];
    }

    int calculateTotal() {
        int total = 0;
        for (int i = 0; i < 5; ++i)
            total += marks[i];
        return total;
    }

    double calculateAverage() {
        return static_cast<double>(calculateTotal()) / 5;
    }
};

int main() {
    int marks[] = {90, 85, 78, 92, 88};
    Student student("Alice", 1001, marks);
    std::cout << "Total Marks: " << student.calculateTotal() << std::endl;
    std::cout << "Average Marks: " << student.calculateAverage() << std::endl;
    return 0;
}

/*
This program defines a class Student with attributes name, rollNumber, and an array marks to store subject marks.
The methods calculateTotal() and calculateAverage() are used to compute the total and average marks.
*/
