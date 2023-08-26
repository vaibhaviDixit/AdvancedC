/*
Given two expressions in the form of strings. The task is to compare them and check if they are similar.
Expressions consist of lowercase alphabets, ‘+’, ‘-‘ and ‘( )’.

Input  : exp1 = "-(c+b+a)"
         exp2 = "-c-b-a"
Output : Yes

Input  : exp1 = "a-b-(c-d)"
         exp2 = "a-b-c-d"
Output : No

*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// Return local sign of the operand.
bool adjSign(string s, int i) {
    if (i == 0)
        return true;
    if (s[i - 1] == '-')
        return false;
    return true;
}

// Evaluate expressions into the count vector
void eval(string s, vector<int>& v, bool add) {
    stack<bool> stk;
    stk.push(true); // Global sign initially positive

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '+' || s[i] == '-') {
            i++;
            continue;
        }
        if (s[i] == '(') {
            if (adjSign(s, i))
                stk.push(stk.top());
            else
                stk.push(!stk.top());
        } else if (s[i] == ')')
            stk.pop();
        else {
            if (stk.top())
                v[s[i] - 'a'] += (adjSign(s, i) ? add ? 1 : -1 : add ? -1 : 1);
            else
                v[s[i] - 'a'] += (adjSign(s, i) ? add ? -1 : 1 : add ? 1 : -1);
        }
        i++;
    }
}

// Returns true if expr1 and expr2 represent the same expressions
bool areSame(string expr1, string expr2) {
    vector<int> v(MAX_CHAR, 0); // Initialize vector for all operands

    eval(expr1, v, true); // Put signs of all operands in expr1
    eval(expr2, v, false); // Subtract signs of operands in expr2

    // If expressions are same, the vector must be all 0.
    for (int i = 0; i < MAX_CHAR; i++)
        if (v[i] != 0)
            return false;

    return true;
}

int main() {
    string expr1 = "-(a+b-c)", expr2 = "-a-b-c";
    if (areSame(expr1, expr2))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

/*
This program checks if two expressions evaluate to the same result by comparing the counts of individual variables with their signs in the expressions.
It implements a custom evaluation function that iterates through each character of the expressions, considers parentheses' local signs and calculates
the final count for each variable. The areSame function evaluates both expressions and then compares the counts of variables.
If all counts are zero, the expressions are equivalent. The code demonstrates a technique for evaluating algebraic expressions and can be used to
solve certain types of interview questions related to expressions.

*/



