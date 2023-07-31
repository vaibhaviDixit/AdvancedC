/*
Write a recursive function to print numbers from start to end in ascending order.

Input:  Enter the starting number: 5
        Enter the ending number: 25
Output: Numbers in the range: 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

*/

#include <iostream>

// Recursive function to print numbers in a range
void printNumbersInRange(int start, int end) {
    // Base case: If the starting number is greater than the ending number,
    // there are no more numbers to print, so return from the function.
    if (start > end)
        return;

    // Print the current number (start) followed by a space.
    std::cout << start << " ";

    // Recursive step: Call the function with the next number (start + 1) as the new starting number,
    // and the ending number unchanged. This will print the remaining numbers in the range.
    printNumbersInRange(start + 1, end);
}

int main() {
    int start, end;
    std::cout << "Enter the starting number: ";
    std::cin >> start;
    std::cout << "Enter the ending number: ";
    std::cin >> end;

    // Display the message indicating the numbers will be printed.
    std::cout << "Numbers in the range: ";

    // Call the printNumbersInRange function with the input starting and ending numbers.
    printNumbersInRange(start, end);

    // Output a newline after printing all the numbers in the range.
    std::cout << std::endl;

    return 0;
}

/*
void printNumbersInRange(int start, int end): This is the recursive function definition to print numbers in a specified range. The function takes two integers start and end as its parameters and does not return anything (void).

if (start > end) return;: This is the base case of the recursion. If the start number is greater than the end number, it means there are no more numbers to print in the range, so the function simply returns and exits.

std::cout << start << " ";: This line prints the current number (start) followed by a space. It prints the numbers in increasing order as the function is recursively called.

printNumbersInRange(start + 1, end);: This line represents the recursive step. The function calls itself with the next number (start + 1) as the new starting number and the ending number unchanged. This recursive call continues printing the remaining numbers in the range.

*/


