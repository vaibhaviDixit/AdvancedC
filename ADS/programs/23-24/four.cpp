/*
Create a Car class to model a car's make, model, and current speed. Implement methods to accelerate, decelerate, and display car information.

Input:
    Car myCar("Toyota", "Camry");
    myCar.accelerate(60);
    myCar.decelerate(20);
    myCar.displayInfo();

Output:

Car accelerated to 60 km/h.
Car decelerated to 40 km/h.
Make: Toyota
Model: Camry
Current Speed: 40 km/h


*/

#include <iostream> // Include the iostream library to enable input and output stream operations.
using namespace std; // Use the standard namespace to access standard library elements directly.

class Car {
private:
    string make; // Private member variable to store the make of the car.
    string model; // Private member variable to store the model of the car.
    int speed; // Private member variable to store the current speed of the car.

public:
    Car(string mk, string mdl) : make(mk), model(mdl), speed(0) {
        // Constructor to initialize the Car object with the provided make and model.
        // The initial speed is set to 0.
    }

    void accelerate(int increment) {
        if (increment > 0) { // Check if the acceleration increment is positive.
            speed += increment; // Increase the car's speed by the acceleration increment.
            cout << "Car accelerated to " << speed << " km/h." << endl;
        } else {
            cout << "Invalid acceleration value. Acceleration failed." << endl;
            // Display an error message if the acceleration increment is not positive.
        }
    }

    void decelerate(int decrement) {
        if (decrement > 0 && speed >= decrement) { // Check if the deceleration decrement is positive and the car's speed is greater than or equal to the decrement.
            speed -= decrement; // Decrease the car's speed by the deceleration decrement.
            cout << "Car decelerated to " << speed << " km/h." << endl;
        } else {
            cout << "Invalid deceleration value or car already at rest. Deceleration failed." << endl;
            // Display an error message if the deceleration decrement is not positive or if the car's speed is not sufficient for the decrement.
        }
    }

    void displayInfo() {
        cout << "Make: " << make << endl; // Display the car's make.
        cout << "Model: " << model << endl; // Display the car's model.
        cout << "Current Speed: " << speed << " km/h" << endl; // Display the car's current speed.
    }
};

int main() {
    Car myCar("Toyota", "Camry"); // Create a Car object named 'myCar' with the provided make "Toyota" and model "Camry."
    myCar.accelerate(60); // Accelerate the car to 60 km/h.
    myCar.decelerate(20); // Decelerate the car by 20 km/h.
    myCar.displayInfo(); // Display the car's information and current speed.

    return 0; // Exit the program with a success status.
}

/*
This C++ program defines a Car class to represent a simple car. The class has private member variables make to store the make of the car, model to store the model of the car, and speed to store the current speed of the car.

The class provides three member functions:

The constructor Car is used to initialize a Car object with the provided make and model. The initial speed is set to 0.
The accelerate member function is used to increase the car's speed by the given acceleration increment. It performs a check to ensure the acceleration increment is positive before updating the speed.
The decelerate member function is used to decrease the car's speed by the given deceleration decrement. It performs checks to ensure the deceleration decrement is positive and that the car's speed is sufficient for the decrement before updating the speed.
The displayInfo member function is used to display the car's make, model, and current speed.

In the main function, a Car object named myCar is created with the make "Toyota" and the model "Camry." The program then accelerates the car to 60 km/h, decelerates it by 20 km/h, and displays the car's information and current speed on the console.

*/
