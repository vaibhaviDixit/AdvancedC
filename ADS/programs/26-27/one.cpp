/*
Given a string containing only the characters '(', ')', '{', '}', '[', and ']', determine if the input string is valid.

Input: "()[]{}"
Output: true

Input: "(]{}"
Output: Invalid

*/

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() ||
                (c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    if (isValid(input)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}

/*
This program checks the validity of a string containing different types of parentheses using a stack. It pushes opening parentheses onto the
stack and pops from the stack when a corresponding closing parenthesis is encountered. If the stack is empty at the end, the string is valid.

*/


