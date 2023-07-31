/*
Write a recursive function to count the number of digits in a positive integer.

Input: Enter a positive integer: 374
Output: Number of digits: 3

*/

#include <iostream>

// Recursive function to count number of digits
int countDigits(int n) {
    // Base case: If the number is 0, it has no digits, so return 0.
    if (n == 0)
        return 0;

    // Recursive step: Return 1 (for the current digit) plus the count of digits
    // obtained by calling the function with the remaining digits (n / 10).
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    // Call the countDigits function with the input positive integer.
    int numDigits = countDigits(n);

    // Output the number of digits.
    std::cout << "Number of digits: " << numDigits << std::endl;
    return 0;
}

/*
int countDigits(int n): This is the recursive function definition to count the number of digits in a given positive integer. The function takes an integer n as its parameter and returns an integer representing the count of digits in the number.

if (n == 0) return 0;: This is the base case of the recursion. If the number n is 0, it means there are no digits to count, so the function returns 0.

return 1 + countDigits(n / 10);: This line represents the recursive step. The function returns 1 (indicating the current digit) plus the count of digits obtained by calling the countDigits function with the remaining digits of the number (obtained using n / 10). This step is based on the idea that counting the digits of a number involves removing the last digit and counting the remaining digits.

*/
