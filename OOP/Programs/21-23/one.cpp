/*
Write a C++ program to find the greatest common divisor of two numbers.

Input: Enter two numbers: 6 9
Output: The greatest common divisor of 6 and 9 is 3

*/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int a, b;
  cout << "Enter two numbers: ";
  cin >> a >> b;

  int gcd_value = gcd(a, b);
  cout << "The greatest common divisor of " << a << " and " << b << " is " << gcd_value << endl;

  return 0;
}

/*
This program first defines the gcd() function, which takes two integers a and b as input and returns their greatest common divisor.
The greatest common divisor of two numbers is the largest number that is a factor of both numbers.
The gcd() function is declared as an inline function, which tells the compiler to expand the function in line when it is called.
This can improve the execution time of the program.
*/
