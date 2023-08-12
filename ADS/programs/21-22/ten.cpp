/*
Create a class called 'Time' to represent the time in hours, minutes, and seconds.
Implement constructors, copy constructor, copy assignment operator, and destructor.

Input:
    Time t1(12, 30, 45);
    Time t2 = t1;
    Time t3;

    t3 = t1;

    t1.display();
    t2.display();
    t3.display();

Output:

Time: 12:30:45
Time: 12:30:45
Time: 12:30:45
Destructor called for Time: 12:30:45
Destructor called for Time: 12:30:45
Destructor called for Time: 12:30:45


*/


#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

    Time& operator=(const Time& other) {
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
        }
        return *this;
    }

    void display() {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }

    ~Time() {
        cout << "Destructor called for ";
        display();
    }
};

int main() {
    Time t1(12, 30, 45);
    Time t2 = t1; // Copy constructor called
    Time t3;

    t3 = t1; // Copy assignment operator called

    t1.display();
    t2.display();
    t3.display();

    return 0;
}

/*
The Time class has the following member functions:

Constructor: The constructor takes three optional parameters h (hours), m (minutes), and s (seconds) with default values of 0. If no values are provided during object creation, the default values will be used to initialize the attributes.

Copy Constructor: The copy constructor is used to create a new Time object as a copy of an existing Time object. It takes a reference to another Time object (const Time& other) as its parameter. Inside the copy constructor, we perform a shallow copy by directly copying the values of the hours, minutes, and seconds attributes from the other object to the newly created object.

Copy Assignment Operator: The copy assignment operator (operator=) allows assignment of one Time object to another. It takes a reference to another Time object (const Time& other) as its parameter. The copy assignment operator first checks whether the two objects are not the same (to avoid self-assignment) and then assigns the values of the hours, minutes, and seconds attributes from the other object to the current object.

display function: This function is used to display the time in the format "hours:minutes:seconds" to the console.

Destructor: The destructor is responsible for releasing resources when the object is destroyed. In this case, the destructor is used to print a message indicating that the destructor is called for the particular Time object.

In the main() function, we demonstrate the use of the Time class by creating three Time objects (t1, t2, and t3). We initialize t1 with the time 12:30:45. Then, we create t2 as a copy of t1 using the copy constructor. Next, we create t3 without any initialization. We use the copy assignment operator to assign t1 to t3. Finally, we display the time of all three objects using the display() function.

*/

