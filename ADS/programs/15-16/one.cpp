/*
Write a recursive function to calculate the factorial of a non-negative integer n.

Input: Enter a non-negative integer: 5
Output: Factorial of 5 is 120

*/

#include <iostream>

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}

/*
unsigned long long factorial(int n): This is the recursive function definition for calculating the factorial of an integer. The function takes an integer n as its parameter and returns an unsigned long long (an integer type capable of holding large non-negative values) representing the factorial of n.

if (n == 0 || n == 1) return 1;: This is the base case of the recursion. When n is either 0 or 1, the function returns 1 since the factorial of 0 and 1 is always 1.

return n * factorial(n - 1);: This is the recursive step. The function returns the value of n multiplied by the factorial of n - 1. By doing so, it gradually breaks down the factorial calculation into smaller subproblems until it reaches the base case.

*/
