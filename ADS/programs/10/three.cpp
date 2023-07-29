/*
Given two strings S and T, find the minimum window in S that contains all characters from T.

Input: S = "ADOBECODEBANC"
       T = "ABC"
Output: Minimum window substring: BANC

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindowSubstring(string s, string t) {
    // Create a hashmap to store the frequency of each character in string T.
    unordered_map<char, int> targetFreq;
    for (char c : t)
        targetFreq[c]++;

    int left = 0;           // Left pointer of the sliding window.
    int minLen = INT_MAX;   // Minimum length of the window substring.
    int count = t.size();   // Number of characters from T that are yet to be found in the window.
    int minStart = 0;       // Starting index of the minimum window substring.

    for (int right = 0; right < s.size(); right++) {
        // If the current character is a part of T, decrement its count in the hashmap.
        if (targetFreq[s[right]] > 0)
            count--;

        targetFreq[s[right]]--;

        // If all characters from T are found in the current window, try to minimize the window size.
        while (count == 0) {
            // Update the minimum window substring if the current window is smaller.
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // Increase the count of the left character in the hashmap and move the left pointer.
            targetFreq[s[left]]++;

            // If the count of the left character becomes positive, it means the window is no longer valid,
            // and we need to find the next valid window starting from the next position.
            if (targetFreq[s[left]] > 0)
                count++;

            left++; // Move the left pointer to find the next window.
        }
    }

    // If no valid window is found, return an empty string; otherwise, return the minimum window substring.
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    string S = "ADOBECODEBANC";
    string T = "ABC";
    string result = minWindowSubstring(S, T);

    if (result.empty())
        cout << "No minimum window substring found." << endl;
    else
        cout << "Minimum window substring: " << result << endl;

    return 0;
}

/*
The minWindowSubstring function takes two input strings s and t.
It creates a hashmap targetFreq to store the frequency of each character in string t.
The left variable is used to keep track of the left pointer of the sliding window.
minLen is initialized to INT_MAX to store the minimum window length found so far.
count represents the number of characters from t that are yet to be found in the current window.
minStart stores the starting index of the minimum window substring.
The right variable is used as the right pointer of the sliding window.
We iterate through the string s using the right pointer and check if the current character is in t.
If the character is in t, we decrement its count in the targetFreq hashmap and also decrement count.
When count becomes zero, it means all characters from t are found in the current window. Now, we try to minimize the window size by moving the left pointer until the window is no longer valid.
If the current window size is smaller than the minimum window found so far, we update minLen and minStart.
Finally, we return the minimum window substring using the substr function, or an empty string if no valid window is found.

*/

