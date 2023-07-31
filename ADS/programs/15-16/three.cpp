/*
Write a recursive function to find the sum of the first n natural numbers.

Input: Enter a positive integer: 10
Output: Sum of first 10 natural numbers is 55

*/

#include <iostream>

// Recursive function to calculate sum of natural numbers
int sumOfNaturalNumbers(int n) {
    if (n == 0)
        return 0;
    return n + sumOfNaturalNumbers(n - 1);
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Sum of first " << n << " natural numbers is " << sumOfNaturalNumbers(n) << std::endl;
    return 0;
}

/*
int sumOfNaturalNumbers(int n): This is the recursive function definition for calculating the sum of the first 'n' natural numbers. The function takes an integer n as its parameter and returns an integer representing the sum.

if (n == 0) return 0;: This is the base case of the recursion. When n is 0, the function returns 0. This handles the case when the input 'n' is 0, and the sum of the first 0 natural numbers is 0.

return n + sumOfNaturalNumbers(n - 1);: This is the recursive step. The function returns the value of n added to the sum of the first 'n-1' natural numbers, which is calculated by calling the sumOfNaturalNumbers function recursively with the argument 'n - 1'. By doing so, it gradually breaks down the sum calculation into smaller subproblems until it reaches the base case.

*/
