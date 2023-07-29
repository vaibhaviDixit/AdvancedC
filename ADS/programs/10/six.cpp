/*
Given two strings S and T, find all the starting indices of the anagrams of T in S.

Input: s = "cbaebabacd";
       t = "abc";
Output: Starting indices of anagrams of T in S: 0 6

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string t) {
    vector<int> result; // To store the starting indices of anagrams of T in S
    int sLen = s.length();
    int tLen = t.length();

    if (sLen < tLen)
        return result; // If S is smaller than T, no anagrams are possible

    unordered_map<char, int> freqMap; // To store the character frequency of T
    for (char c : t)
        freqMap[c]++;

    int left = 0, right = 0, count = tLen;

    // Sliding window approach
    while (right < sLen) {
        // Move the right boundary of the window
        if (freqMap[s[right]] > 0) {
            // If the character exists in T, decrease the count
            count--;
        }
        freqMap[s[right]]--; // Decrement the frequency of the character
        right++;

        // Check if the window size is equal to T's size
        if (right - left == tLen) {
            if (count == 0) {
                // If count is zero, it means we found an anagram
                result.push_back(left);
            }

            // Move the left boundary of the window
            if (freqMap[s[left]] >= 0) {
                // If the character existed in T, increase the count
                count++;
            }
            freqMap[s[left]]++; // Increment the frequency of the character
            left++;
        }
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string t = "abc";
    vector<int> result = findAnagrams(s, t);
    cout << "Starting indices of anagrams of T in S: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}

/*
The function findAnagrams takes two strings s and t as input and returns a vector of integers representing the starting indices of anagrams of t in s.
We start by checking if s is smaller than t. If s is smaller, it is impossible to have anagrams, so we return an empty result vector.
We initialize an unordered map freqMap to store the character frequency of string t.
The left and right variables represent the boundaries of the window. We use the sliding window approach, starting with both boundaries at the beginning of string s.
We move the right boundary to the right and decrement the frequency of the character at the right position in the freqMap.
If the character exists in t, we decrease the count, which tracks the number of characters in t that are still needed to form an anagram.
When the window size becomes equal to the length of t, we check if an anagram is found by checking if count is zero. If count is zero, it means an anagram is found, so we add the left index to the result.
We move the left boundary to the right and revert the changes made to the freqMap. This step is necessary to keep the window size equal to t and move it further to check for other anagrams.
We repeat steps 5 to 8 until the right boundary reaches the end of string s.
Finally, we return the result vector containing the starting indices of all the anagrams of t in s.

*/
