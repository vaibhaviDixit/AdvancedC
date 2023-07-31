/*
Write a recursive function to calculate x raised to the power n where x and n are non-negative integers.

Input: Enter the base (x): 5
       Enter the exponent (n): 3
Output: 5 raised to the power 3 is 125

*/

#include <iostream>

// Recursive function to calculate power
unsigned long long power(int x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main() {
    int x, n;
    std::cout << "Enter the base (x): ";
    std::cin >> x;
    std::cout << "Enter the exponent (n): ";
    std::cin >> n;
    std::cout << x << " raised to the power " << n << " is " << power(x, n) << std::endl;
    return 0;
}

/*
unsigned long long power(int x, int n): This is the recursive function definition for calculating the power of 'x' raised to 'n'. The function takes two integers as its parameters: 'x' (the base) and 'n' (the exponent). It returns an unsigned long long (an integer type capable of holding large non-negative values) representing the result of 'x' raised to the power of 'n'.

if (n == 0) return 1;: This is the base case of the recursion. When 'n' is 0, the function returns 1. This handles the case when any number raised to the power of 0 is always 1.

return x * power(x, n - 1);: This is the recursive step. The function returns the value of 'x' multiplied by the result of 'x' raised to the power of 'n - 1'. By doing so, it gradually breaks down the power calculation into smaller subproblems until it reaches the base case.

*/


