/*
 Write a program to check whether a given year is a leap year or not.

 Input: Enter a year: 2020
 Output: 2020 is a leap year.

*/

#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}

/*
This program checks if a given year is a leap year or not, based on the leap year rules.
*/
