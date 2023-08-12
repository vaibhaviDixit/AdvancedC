/*
 Implement an employee hierarchy with a base class "Employee" and derived classes "Manager" and "Worker." Each class should have member
 functions for displaying information.

 Input:
    Manager m("John Doe", 101, 5);
    Worker w("Alice Smith", 201, 15);
    m.display();
    w.display();

 Output:
    Name: John Doe, Employee ID: 101
    Number of Subordinates: 5
    Name: Alice Smith, Employee ID: 201
    Hourly Rate: 15


*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
#include <string> // Include the string library to work with strings.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Employee {
protected:
    string name; // Protected member variable to store the name of the employee.
    int employeeId; // Protected member variable to store the employee ID.

public:
    Employee(string n, int id) : name(n), employeeId(id) {
        // Constructor to initialize the Employee object with the provided name and employee ID.
    }

    virtual void display() const {
        cout << "Name: " << name << ", Employee ID: " << employeeId << endl;
        // Display the name and employee ID of the employee.
    }
};

class Manager : public Employee {
private:
    int numberOfSubordinates; // Private member variable to store the number of subordinates managed by the manager.

public:
    Manager(string n, int id, int numSub) : Employee(n, id), numberOfSubordinates(numSub) {
        // Constructor to initialize the Manager object with the provided name, employee ID, and number of subordinates.
    }

    void display() const override {
        Employee::display(); // Call the display() method of the base class Employee to display the name and employee ID.
        cout << "Number of Subordinates: " << numberOfSubordinates << endl;
        // Display the number of subordinates managed by the manager.
    }
};

class Worker : public Employee {
private:
    int hourlyRate; // Private member variable to store the hourly rate of the worker.

public:
    Worker(string n, int id, int rate) : Employee(n, id), hourlyRate(rate) {
        // Constructor to initialize the Worker object with the provided name, employee ID, and hourly rate.
    }

    void display() const override {
        Employee::display(); // Call the display() method of the base class Employee to display the name and employee ID.
        cout << "Hourly Rate: " << hourlyRate << endl;
        // Display the hourly rate of the worker.
    }
};

int main() {
    Manager m("John Doe", 101, 5); // Create a Manager object named 'm' with the provided name "John Doe", employee ID 101, and 5 subordinates.
    Worker w("Alice Smith", 201, 15); // Create a Worker object named 'w' with the provided name "Alice Smith", employee ID 201, and hourly rate 15.

    m.display(); // Display the information of the manager using the display() method of the Manager class.
    w.display(); // Display the information of the worker using the display() method of the Worker class.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of inheritance and polymorphism using the base class Employee and its derived classes Manager and Worker.

The Employee class is the base class, which has two protected member variables: name to store the name of the employee and employeeId to store the unique employee ID. The class provides a constructor to initialize an Employee object with the provided name and employee ID. It also declares a virtual member function display(), which is intended to be overridden in the derived classes.

The Manager class is a derived class from Employee and has an additional private member variable, numberOfSubordinates, to store the number of subordinates managed by the manager. The class provides a constructor to initialize a Manager object with the provided name, employee ID, and number of subordinates. It overrides the display() method to also display the number of subordinates managed by the manager.

The Worker class is another derived class from Employee and has an additional private member variable, hourlyRate, to store the hourly rate of the worker. The class provides a constructor to initialize a Worker object with the provided name, employee ID, and hourly rate. It also overrides the display() method to display the hourly rate of the worker.

In the main() function, two objects m and w of type Manager and Worker, respectively, are created and initialized with the provided parameters. The program then calls the display() method for both objects, which results in polymorphic behavior. The display() method of each derived class is invoked, showing the information specific to the type of employee (manager or worker) while also displaying the common information (name and employee ID) from the base class Employee.

*/

