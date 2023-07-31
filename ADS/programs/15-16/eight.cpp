/*
Write a recursive function to find the sum of digits of a positive integer.

Input: Enter a positive integer: 742
Output: Sum of digits is: 13

*/

#include <iostream>

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    // Base case: If the number is 0, return 0 as there are no digits to add.
    if (n == 0)
        return 0;

    // Recursive step: Return the last digit (n % 10) and add it to the sum of digits
    // obtained by calling the function with the remaining digits (n / 10).
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    // Call the sumOfDigits function with the input positive integer.
    int sum = sumOfDigits(n);

    // Output the sum of digits.
    std::cout << "Sum of digits is: " << sum << std::endl;
    return 0;
}

/*

int sumOfDigits(int n): This is the recursive function definition to calculate the sum of digits of a given positive integer. The function takes an integer n as its parameter and returns an integer representing the sum of its digits.

if (n == 0) return 0;: This is the base case of the recursion. If the number n is 0, it means there are no digits to add, so the function returns 0.

return n % 10 + sumOfDigits(n / 10);: This line represents the recursive step. The function returns the last digit of the number (obtained using n % 10) and adds it to the sum of digits obtained by calling the sumOfDigits function with the remaining digits (obtained using n / 10). By doing so, it gradually breaks down the number into its individual digits and calculates their sum recursively.

*/
