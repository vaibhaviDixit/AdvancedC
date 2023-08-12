/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Constraints: String of digits should contain digits from 2 to 9 only.

Input: Enter the string of digits (2-9): 23
Output:
Letter Combinations:
ad
ae
af
bd
be
bf
cd
ce
cf

*/


// Code for Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> phoneMap = {
    "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void generateLetterCombinations(string digits, int index, string current, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    string letters = phoneMap[digits[index] - '2'];
    for (char ch : letters) {
        generateLetterCombinations(digits, index + 1, current + ch, result);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty())
        return result;
    generateLetterCombinations(digits, 0, "", result);
    return result;
}

int main() {
    string digits;
    cout << "Enter the string of digits (2-9): ";
    cin >> digits;

    vector<string> result = letterCombinations(digits);

    cout << "Letter Combinations:\n";
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}

/*
The Letter Combinations of a Phone Number program generates all possible letter combinations that can be formed using the digits from the input
string. It uses a recursive backtracking approach. The generateLetterCombinations function takes the digits, the current index, and the current
combination as parameters. For each digit, it maps the corresponding letters using the phoneMap vector and then recursively explores all possible
letter combinations. When the current index becomes equal to the length of the digits, it means a valid combination is formed, and it is added to
the result vector. The letterCombinations function handles the special case when the input string is empty and calls the generateLetterCombinations
function to generate all possible combinations.

*/



