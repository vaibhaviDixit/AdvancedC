/*
Write a recursive function to generate the nth number in the Fibonacci series.

Input: Enter a positive integer: 7
Output: Fibonacci number at position 7 is 13

*/

#include <iostream>

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << std::endl;
    return 0;
}

/*
int fibonacci(int n): This is the recursive function definition for calculating the Fibonacci number at a given position n. The function takes an integer n as its parameter and returns an integer representing the Fibonacci number.

if (n <= 0) return 0;: This is the base case of the recursion. When n is less than or equal to 0, the function returns 0. This handles the case when an invalid position (non-positive) is given for the Fibonacci sequence.

if (n == 1) return 1;: This is another base case of the recursion. When n is equal to 1, the function returns 1. This covers the first position in the Fibonacci sequence, which is 1.

return fibonacci(n - 1) + fibonacci(n - 2);: This is the recursive step. The function returns the sum of the Fibonacci numbers at positions n - 1 and n - 2. By doing so, it gradually breaks down the Fibonacci number calculation into smaller subproblems until it reaches the base cases.

*/
