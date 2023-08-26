/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation (postfix notation).

Input: ["2", "1", "+", "3", "*"]
Output: 9

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to evaluate Reverse Polish Notation (RPN) expression
int evalRPN(vector<string>& tokens) {
    stack<int> st; // Initialize a stack to hold operands

    // Iterate through each token in the expression
    for (string token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // If the token is an operator, pop the top two elements from the stack
            int num2 = st.top(); st.pop();
            int num1 = st.top(); st.pop();

            // Perform the operation based on the operator
            if (token == "+") st.push(num1 + num2);
            else if (token == "-") st.push(num1 - num2);
            else if (token == "*") st.push(num1 * num2);
            else if (token == "/") st.push(num1 / num2);
        } else {
            // If the token is an operand, convert it to an integer and push it onto the stack
            st.push(stoi(token));
        }
    }

    // The final result will be left on the top of the stack
    return st.top();
}

int main() {
    vector<string> tokens = {"6", "3", "2", "4", "+","-","*"};
    cout << "Result: " << evalRPN(tokens) << endl; // Evaluate the RPN expression and display the result
    return 0;
}

/*
This C++ code defines a function evalRPN that evaluates a given expression in Reverse Polish Notation (RPN) using a stack. RPN is a mathematical
notation in which every operator follows all of its operands. The main function demonstrates the usage of the evalRPN function with an example RPN
expression and outputs the result.

*/
