/*
Create a class to calculate the factorial of a given positive integer using a recursive function.

Input: Enter a positive integer: 7
Output: Factorial of 7 is: 5040

*/

#include <iostream>
using namespace std;

class FactorialCalculator {
public:
    int calculate(int n) {
        if (n <= 1) { //base case
            return 1;
        }
        return n * calculate(n - 1);// recursive call
    }
};

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    FactorialCalculator calculator;
    int result = calculator.calculate(num); //store result in integer variable.

    cout << "Factorial of " << num << " is: " << result << endl;
    return 0;
}

/*
In above program we have class called 'FactorialCalculator' which contains method calculate() to calculate factorial of given number.

*/



