/*
 Implement a vehicle hierarchy with a base class "Vehicle" and derived classes "Car" and "Bike." Each class should have member
 functions for displaying information.

 Input:
    Car c("Toyota", "Corolla", 4);
    Bike b("Honda", "CBR", 250);

    c.display();
    b.display();

 Output:
  Make: Toyota, Model: Corolla
  Number of Doors: 4
  Make: Honda, Model: CBR
  Engine CC: 250

*/


#include <iostream> // Include the iostream library to enable input and output stream operations.
#include <string> // Include the string library to work with strings.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Vehicle {
protected:
    string make; // Protected member variable to store the make of the vehicle.
    string model; // Protected member variable to store the model of the vehicle.

public:
    Vehicle(string mk, string mdl) : make(mk), model(mdl) {
        // Constructor to initialize the Vehicle object with the provided make and model.
    }

    virtual void display() const {
        cout << "Make: " << make << ", Model: " << model << endl;
        // Display the make and model of the vehicle.
    }
};

class Car : public Vehicle {
private:
    int numDoors; // Private member variable to store the number of doors of the car.

public:
    Car(string mk, string mdl, int doors) : Vehicle(mk, mdl), numDoors(doors) {
        // Constructor to initialize the Car object with the provided make, model, and number of doors.
    }

    void display() const override {
        Vehicle::display(); // Call the display() method of the base class Vehicle to display the make and model.
        cout << "Number of Doors: " << numDoors << endl;
        // Display the number of doors of the car.
    }
};

class Bike : public Vehicle {
private:
    int engineCC; // Private member variable to store the engine CC (cubic centimeters) of the bike.

public:
    Bike(string mk, string mdl, int cc) : Vehicle(mk, mdl), engineCC(cc) {
        // Constructor to initialize the Bike object with the provided make, model, and engine CC.
    }

    void display() const override {
        Vehicle::display(); // Call the display() method of the base class Vehicle to display the make and model.
        cout << "Engine CC: " << engineCC << endl;
        // Display the engine CC of the bike.
    }
};

int main() {
    Car c("Toyota", "Corolla", 4); // Create a Car object named 'c' with the provided make "Toyota", model "Corolla", and 4 doors.
    Bike b("Honda", "CBR", 250); // Create a Bike object named 'b' with the provided make "Honda", model "CBR", and engine CC 250.

    c.display(); // Display the information of the car using the display() method of the Car class.
    b.display(); // Display the information of the bike using the display() method of the Bike class.

    return 0; // Exit the program with a success status.
}

/*
This C++ program demonstrates the concept of inheritance and polymorphism using the base class Vehicle and its derived classes Car and Bike.

The Vehicle class is the base class, which has two protected member variables: make to store the make of the vehicle and model to store the model of the vehicle. The class provides a constructor to initialize a Vehicle object with the provided make and model. It also declares a virtual member function display(), which is intended to be overridden in the derived classes.

The Car class is a derived class from Vehicle and has an additional private member variable, numDoors, to store the number of doors of the car. The class provides a constructor to initialize a Car object with the provided make, model, and number of doors. It overrides the display() method to also display the number of doors of the car.

The Bike class is another derived class from Vehicle and has an additional private member variable, engineCC, to store the engine cubic centimeters (CC) of the bike. The class provides a constructor to initialize a Bike object with the provided make, model, and engine CC. It also overrides the display() method to display the engine CC of the bike.

In the main() function, two objects c and b of type Car and Bike, respectively, are created and initialized with the provided parameters. The program then calls the display() method for both objects, which results in polymorphic behavior. The display() method of each derived class is invoked, showing the information specific to the type of vehicle (car or bike) while also displaying the common information (make and model) from the base class Vehicle.

*/





