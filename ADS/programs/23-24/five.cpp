/*
Create a class to manage employee details, including name, designation, and salary, with the ability to update salary and display employee
information.

Input:
Employee emp("Alice", "Manager", 50000);
emp.updateSalary(55000);
emp.displayInfo();

Output:
Salary updated successfully. New salary: 55000
Name: Alice
Designation: Manager
Salary: 55000

*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Employee {
private:
    string name; // Private member variable to store the name of the employee.
    string designation; // Private member variable to store the designation of the employee.
    double salary; // Private member variable to store the salary of the employee.

public:
    Employee(string n, string desig, double sal) : name(n), designation(desig), salary(sal) {
        // Constructor to initialize the Employee object with the provided name, designation, and salary.
    }

    void updateSalary(double newSalary) {
        if (newSalary > 0) { // Check if the new salary is positive.
            salary = newSalary; // Update the employee's salary to the new value.
            cout << "Salary updated successfully. New salary: " << salary << endl;
        } else {
            cout << "Invalid salary. Update failed." << endl;
            // Display an error message if the new salary is not positive.
        }
    }

    void displayInfo() {
        cout << "Name: " << name << endl; // Display the employee's name.
        cout << "Designation: " << designation << endl; // Display the employee's designation.
        cout << "Salary: " << salary << endl; // Display the employee's current salary.
    }
};

int main() {
    Employee emp("Alice", "Manager", 50000); // Create an Employee object named 'emp' with the provided name "Alice", designation "Manager", and salary 50000.
    emp.updateSalary(55000); // Update the employee's salary to 55000.
    emp.displayInfo(); // Display the employee's information and updated salary.

    return 0; // Exit the program with a success status.
}


/*
This C++ program defines an Employee class to represent a simple employee. The class has private member variables name to store the name of the employee, designation to store the designation of the employee, and salary to store the current salary of the employee.

The class provides two member functions:

The constructor Employee is used to initialize an Employee object with the provided name, designation, and salary.
The updateSalary member function is used to update the employee's salary to the provided new salary value. It performs a check to ensure the new salary is positive before updating the salary.
The displayInfo member function is used to display the employee's name, designation, and current salary.

In the main function, an Employee object named emp is created with the name "Alice", designation "Manager", and salary 50000. The program then updates the employee's salary to 55000 and displays the employee's information along with the updated salary on the console.

*/

