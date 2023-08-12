/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Input: Enter the number of pairs of parentheses: 3
Output:
Combinations of well-formed parentheses:
((()))
(()())
(())()
()(())
()()()

*/

// Code for Combinations of Parentheses

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(int open, int close, string current, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }

    if (open > 0) {
        generateParentheses(open - 1, close, current + '(', result);
    }

    if (close > open) {
        generateParentheses(open, close - 1, current + ')', result);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generateParentheses(n, n, "", result);
    return result;
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = generateParentheses(n);

    cout << "Combinations of well-formed parentheses:\n";
    for (const string& parentheses : result) {
        cout << parentheses << endl;
    }

    return 0;
}

/*
The Combinations of Parentheses program generates all combinations of well-formed parentheses using backtracking recursion.
The generateParentheses function takes two parameters, the count of remaining open and close parentheses, and the current combination.
It recursively adds open and close parentheses to the current combination while ensuring that the parentheses remain well-formed
(i.e., every opening parenthesis has a corresponding closing parenthesis). The function stops when there are no remaining open and close
parentheses. The generateParentheses function is called from the main function with the number of pairs of parentheses provided by the user,
and it prints all possible combinations.

*/



