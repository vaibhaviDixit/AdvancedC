/*
You are tasked with writing a C++ program that calculates and prints the binomial coefficient, also known as "n choose r," denoted as C(n, r).
The program should take two integer inputs, 'n' and 'r,' and compute the binomial coefficient using the formula:

C(n, r) = n! / (r! * (n - r)!)

Where 'n!' represents the factorial of 'n.'

Input: n= 9   r= 4
Output: 126

*/


#include <iostream>
using namespace std;

// Function to calculate the factorial of a number
int fact(int n) {
   if (n == 0 || n == 1)
      return 1;
   else
      return n * fact(n - 1);
}

int main() {
   int n, r, result;

   // Prompting the user to enter 'n' and 'r'
   cout << "Enter n : ";
   cin >> n;
   cout << "\nEnter r : ";
   cin >> r;

   // Calculate C(n, r) using the binomial coefficient formula
   result = fact(n) / (fact(r) * fact(n - r));

   // Display the result
   cout << "\nThe result : " << result;

   return 0;
}

/*
The fact function is defined to calculate the factorial of a given number 'n' recursively. If 'n' is 0 or 1, the function returns 1 (the base case).
Otherwise, it calculates 'n!' by multiplying 'n' with the factorial of 'n - 1.'

*/
