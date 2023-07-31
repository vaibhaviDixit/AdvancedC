/*
 Write a recursive function to reverse a string.

 Input: Enter a string: windows
 Output: Reversed string: swodniw

*/

#include <iostream>
#include <string>

// Recursive function to reverse a string
void reverseString(std::string& str, int start, int end) {
    // Base case: If the start index is greater than or equal to the end index, return.
    // This happens when there are no more characters left to swap.
    if (start >= end)
        return;

    // Swap the characters at the start and end positions of the string.
    std::swap(str[start], str[end]);

    // Recursive step: Call the function with updated start and end positions.
    // Move towards the middle of the string, swapping characters along the way.
    reverseString(str, start + 1, end - 1);
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    // Call the reverseString function with start index 0 and end index (length - 1).
    reverseString(str, 0, str.length() - 1);

    // Output the reversed string.
    std::cout << "Reversed string: " << str << std::endl;
    return 0;
}

/*
void reverseString(std::string& str, int start, int end): This is the recursive function definition to reverse a string. The function takes three parameters:

str: A reference to the string that needs to be reversed.
start: The starting index of the portion of the string to be considered.
end: The ending index of the portion of the string to be considered.
if (start >= end) return;: This is the base case of the recursion. If the start index is greater than or equal to the end index, it means the entire string or the remaining portion of the string has been reversed, and the function returns without further processing.

std::swap(str[start], str[end]);: This line swaps the characters at the start and end positions of the string str. This step effectively reverses the order of the characters.

reverseString(str, start + 1, end - 1);: This line represents the recursive step. The function calls itself with updated parameters: start is incremented by 1, and end is decremented by 1. This recursive call will reverse the remaining portion of the string closer to the middle of the string.

*/

