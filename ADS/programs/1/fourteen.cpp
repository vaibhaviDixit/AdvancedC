/*
Given a string s, find the length of the longest substring without repeating characters.

Input: s="abcabcbb"
Output: Length of the longest substring without repeating characters: 3

*/

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int max_length = 0;
    int left = 0;
    unordered_map<char, int> char_index_map;

    for (int right = 0; right < n; right++) {
        if (char_index_map.find(s[right]) != char_index_map.end()) {
            left = max(left, char_index_map[s[right]] + 1);
        }
        char_index_map[s[right]] = right;
        max_length = max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    string s = "abcabcbb";

    int max_length = lengthOfLongestSubstring(s);

    cout << "Length of the longest substring without repeating characters: " << max_length << endl;

    return 0;
}

/*
This program finds the length of the longest substring without repeating characters in a given string. It uses two pointers, left and right, to represent the current substring being considered. The left pointer keeps track of the start index of the substring, and the right pointer iterates through the string. The char_index_map is used to store the latest index of each character encountered in the string. Whenever a repeating character is found (i.e., the character already exists in the map), the left pointer is updated to the right of the previous occurrence of that character. This ensures that the substring between left and right contains no repeating characters. The program maintains the maximum length of such substrings, and the final result is returned. The solution has a time complexity of O(n) as each character in the string is visited once.

*/
