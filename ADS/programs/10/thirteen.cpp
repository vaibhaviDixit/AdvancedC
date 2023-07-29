/*
Given a string, find the length of the longest substring that contains at most K distinct characters.

Input:  Enter the input string: macronipasta
        Enter the value of K: 8
Output: The length of the longest substring with at most 8 distinct characters is: 9


*/

#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubstringLengthWithKDistinctChars(const string& s, int K) {
    int n = s.length();
    if (n == 0 || K == 0)
        return 0;

    unordered_map<char, int> charFrequency; // Map to store character frequency in the current window
    int left = 0; // Left pointer of the sliding window
    int maxLen = 0; // Maximum length of the substring with at most K distinct characters

    for (int right = 0; right < n; right++) {
        charFrequency[s[right]]++; // Expand the window by adding the right character

        // Contract the window from the left if we have more than K distinct characters
        while (charFrequency.size() > K) {
            charFrequency[s[left]]--; // Decrease the frequency of the left character
            if (charFrequency[s[left]] == 0) {
                charFrequency.erase(s[left]); // Remove character if its frequency becomes zero
            }
            left++; // Move the left pointer to contract the window
        }

        // Update the maximum length encountered so far
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    string input;
    int K;

    cout << "Enter the input string: ";
    cin >> input;

    cout << "Enter the value of K: ";
    cin >> K;

    int result = longestSubstringLengthWithKDistinctChars(input, K);
    cout << "The length of the longest substring with at most " << K << " distinct characters is: " << result << endl;

    return 0;
}

/*
In this C++ program, we have implemented the function longestSubstringLengthWithKDistinctChars that finds the length of the longest
substring with at most K distinct characters. The main function takes the input string and the value of K from the user, calls the
longestSubstringLengthWithKDistinctChars function, and prints the result.

The function longestSubstringLengthWithKDistinctChars uses the sliding window technique to efficiently find the desired substring.
It maintains two pointers, left and right, to create a sliding window and uses an unordered map to keep track of the frequency of
characters in the current window. The map stores each character in the window along with its frequency.

The right pointer iterates through the string and expands the window by adding characters and updating their frequencies in the map.
When the window contains more than K distinct characters, the left pointer contracts the window by removing characters from the left
end and updating their frequencies. The loop continues until we again have at most K distinct characters in the window.
During this process, we keep track of the maximum length encountered so far, which is the result we need.

*/


