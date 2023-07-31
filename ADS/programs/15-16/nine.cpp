/*
Write a recursive function to find the Greatest Common Divisor (GCD) of two non-negative integers.

Input: Enter two non-negative integers: 35 90
Output: GCD of 35 and 90 is 5

*/

#include <iostream>

// Recursive function to calculate GCD
int gcd(int a, int b) {
    // Base case: If the second number (b) is 0, the GCD is found and it is 'a'.
    if (b == 0)
        return a;

    // Recursive step: Calculate the GCD by calling the function with the second number (b)
    // as the first number and the remainder of 'a' divided by 'b' as the second number.
    return gcd(b, a % b);
}

int main() {
    int a, b;
    std::cout << "Enter two non-negative integers: ";
    std::cin >> a >> b;

    // Call the gcd function with the two input non-negative integers.
    int result = gcd(a, b);

    // Output the GCD.
    std::cout << "GCD of " << a << " and " << b << " is " << result << std::endl;
    return 0;
}

/*
int gcd(int a, int b): This is the recursive function definition to calculate the Greatest Common Divisor (GCD) of two non-negative integers 'a' and 'b'. The function takes two integers 'a' and 'b' as its parameters and returns an integer representing their GCD.

if (b == 0) return a;: This is the base case of the recursion. If the second number 'b' is 0, it means that the GCD has been found, and the function returns 'a'. The GCD of any number 'a' with 0 is 'a'.

return gcd(b, a % b);: This line represents the recursive step. The function calculates the GCD by calling itself with 'b' as the first number and the remainder of 'a' divided by 'b' as the second number. This step is based on the Euclidean algorithm for finding the GCD.

*/

