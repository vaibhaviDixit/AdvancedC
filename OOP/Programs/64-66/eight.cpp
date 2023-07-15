/*
Create a C++ program to calculate the salary of employees.
Implement a base class called Employee with a virtual function calculateSalary(), which returns the basic salary.
Create two types of employees, FullTimeEmployee and PartTimeEmployee, that override the calculateSalary() method to
calculate the salary based on their working hours.
*/

#include <iostream>

class Employee {
protected:
    double basicSalary;
public:
    Employee(double salary) : basicSalary(salary) {}

    virtual double calculateSalary() const {
        return basicSalary;
    }
};

class FullTimeEmployee : public Employee {
private:
    double bonus;
public:
    FullTimeEmployee(double salary, double b) : Employee(salary), bonus(b) {}

    double calculateSalary()  {
        return basicSalary + bonus;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
public:
    PartTimeEmployee(double salary, int hours) : Employee(salary), hoursWorked(hours) {}

    double calculateSalary() {
        return basicSalary * hoursWorked;
    }
};

int main() {
    Employee* fullTimeEmp = new FullTimeEmployee(5000, 1000);
    Employee* partTimeEmp = new PartTimeEmployee(50, 30);

    std::cout << "Full-Time Employee Salary: " << fullTimeEmp->calculateSalary() << std::endl;
    std::cout << "Part-Time Employee Salary: " << partTimeEmp->calculateSalary() << std::endl;

    delete fullTimeEmp;
    delete partTimeEmp;

    return 0;
}
/*
In this program, we create an Employee base class with a virtual function calculateSalary().
Then, we create two derived classes FullTimeEmployee and PartTimeEmployee, each of which overrides the calculateSalary()
method to calculate the salary based on their working conditions.

*/

