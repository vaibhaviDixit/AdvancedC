/*
Given a string and a positive integer k, find the length of the longest substring that can be formed by replacing at most 'k' characters.

Input: aabccbb
       k=2

Output: Length of the longest substring with at most 2 replacements: 5

*/

#include <stdio.h>
#include <string.h>

// Function to find the length of the longest substring with at most k replacements
int longestSubstringWithReplacements(char str[], int k) {
    int length = strlen(str); // Length of the string
    int start = 0; // Start index of the current substring
    int maxCount = 0; // Maximum count of a character in the current substring
    int maxLength = 0; // Length of the longest substring

    int charCount[26] = {0}; // Array to store the count of each character (assuming lowercase English letters)

    // Iterate through the string
    for (int end = 0; end < length; end++) {
        charCount[str[end] - 'a']++; // Increment the count of the current character

        // Update the maximum count of a character in the current substring
        if (charCount[str[end] - 'a'] > maxCount) {
            maxCount = charCount[str[end] - 'a'];
        }

        // If the length of the current substring minus the maximum count is greater than k,
        // move the start index and update the character counts accordingly
        if (end - start + 1 - maxCount > k) {
            charCount[str[start] - 'a']--; // Decrement the count of the character at the start index
            start++; // Move the start index to the right
        }

        // Update the length of the longest substring
        if (end - start + 1 > maxLength) {
            maxLength = end - start + 1;
        }
    }

    return maxLength; // Return the length of the longest substring
}

int main() {
    char str[] = "aabccbb";
    int k = 2;

    int longestSubstringLength = longestSubstringWithReplacements(str, k);
    printf("Length of the longest substring with at most %d replacements: %d\n", k, longestSubstringLength);

    return 0;
}

/*
This program finds the length of the longest substring that can be formed by replacing at most 'k' characters in a given string. The function longestSubstringWithReplacements takes the string str and the number of replacements k as input.

Inside the function, it initializes variables length as the length of the string, start as the start index of the current substring, maxCount as the maximum count of a character in the current substring, and maxLength as the length of the longest substring.

It also declares an array charCount of size 26 to store the count of each character (assuming lowercase English letters).

The program then iterates through the string using the end index. For each character, it increments the count of that character in charCount and updates the maxCount if necessary.

If the difference between the length of the current substring (end - start + 1) and the maxCount is greater than k, it means that more than 'k' characters need to be replaced to maintain the substring. In this case, it moves the start index to the right and updates the character counts accordingly by decrementing the count of the character at the start index.

After each iteration, it updates the maxLength if the length of the current substring is greater.

Finally, the function returns the maxLength as the length of the longest substring that satisfies the conditions.

In the main function, an example stringstr and a value of k are defined. The function longestSubstringWithReplacements is called with the string and the value of k. The length of the longest substring that can be formed by replacing at most k characters is printed to the console.
*/
