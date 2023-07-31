/*
 Write a recursive function to check if a string is a palindrome.

 Input: Enter a string: madam
 Output: The string is a palindrome.

 Input: Enter a string: tools
 Output: The string is not a palindrome.

*/

#include <iostream>
#include <string>

// Recursive function to check palindrome
bool isPalindrome(const std::string& str, int start, int end) {
    // Base case: If the start index is greater than or equal to the end index,
    // it means all characters in the string have been compared, and it is a palindrome.
    if (start >= end)
        return true;

    // If the characters at the start and end positions are not equal,
    // it means the string is not a palindrome.
    if (str[start] != str[end])
        return false;

    // Recursive step: Call the function with updated start and end positions.
    // Continue checking characters towards the middle of the string.
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    // Call the isPalindrome function with start index 0 and end index (length - 1).
    bool palindrome = isPalindrome(str, 0, str.length() - 1);

    // Output whether the string is a palindrome or not.
    if (palindrome)
        std::cout << "The string is a palindrome." << std::endl;
    else
        std::cout << "The string is not a palindrome." << std::endl;

    return 0;
}

/*
bool isPalindrome(const std::string& str, int start, int end): This is the recursive function definition to check whether a given string is a palindrome. The function takes three parameters:

str: A constant reference to the string that needs to be checked for being a palindrome.
start: The starting index of the portion of the string to be considered for comparison.
end: The ending index of the portion of the string to be considered for comparison.
if (start >= end) return true;: This is the base case of the recursion. If the start index is greater than or equal to the end index, it means all characters in the string have been compared, and the function returns true, indicating that the string is a palindrome.

if (str[start] != str[end]) return false;: This condition checks whether the characters at the start and end positions of the string are not equal. If they are not equal, it means the string is not a palindrome, and the function returns false.

return isPalindrome(str, start + 1, end - 1);: This line represents the recursive step. If the function reaches this point, it means the characters at start and end positions are equal. The function now calls itself with updated parameters: start is incremented by 1, and end is decremented by 1. This recursive call continues the comparison towards the middle of the string.

*/

