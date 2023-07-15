/*
   Create a class 'Time' with attributes 'hours', 'minutes', and 'seconds'.
   Implement functions to add and display time.
   Use objects to demonstrate time addition.
*/

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Function to add time
    void addTime(const Time& other) {
        seconds += other.seconds;
        minutes += seconds / 60;
        seconds %= 60;

        minutes += other.minutes;
        hours += minutes / 60;
        minutes %= 60;

        hours += other.hours;
    }

    // Function to display time
    void displayTime() {
        std::cout << "Time: " << hours << "h " << minutes << "m " << seconds << "s\n";
    }
};

int main() {
    Time t1(2, 30, 45);
    Time t2(1, 45, 15);

    t1.addTime(t2);
    t1.displayTime();

    return 0;
}

/*
This program defines a class Time with attributes hours, minutes, and seconds.
It has a method to add time and display the resulting time.
The main function demonstrates how to use the addTime method with objects to add two time instances.
*/

