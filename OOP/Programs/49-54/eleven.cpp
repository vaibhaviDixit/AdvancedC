/*
 Create a class representing a date and overload the '==' and '!=' operators to compare two dates.
*/

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Overloading the equality '==' operator
    bool operator==(const Date& other) {
        return day == other.day && month == other.month && year == other.year;
    }

    // Overloading the inequality '!=' operator
    bool operator!=(const Date& other) {
        return !(*this == other);
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d1(15, 7, 2023);
    Date d2(15, 7, 2023);
    Date d3(1, 1, 2023);

    if (d1 == d2) {
        cout << "d1 and d2 are the same dates." << endl;
    } else {
        cout << "d1 and d2 are different dates." << endl;
    }

    if (d1 != d3) {
        cout << "d1 and d3 are different dates." << endl;
    } else {
        cout << "d1 and d3 are the same dates." << endl;
    }

    return 0;
}

/*
This program creates a class Date to represent a date. The '==' and '!=' operators are overloaded
to compare two dates for equality and inequality.
The display() function is used to print the comparison results.

*/

