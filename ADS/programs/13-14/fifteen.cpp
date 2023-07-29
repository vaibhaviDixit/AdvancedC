/*
Given a string S, the task is to find the bracket numbers.

Input:  S = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3

Input:  S = "(((()("
Output: 1 2 3 4 4 5

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to assign bracket numbers to each opening and closing parenthesis in the input string
    vector<int> bracketNumbers(string S)
    {
        int a = 0; // Counter to keep track of the bracket numbers
        vector<int> res; // Vector to store the result, i.e., the bracket numbers
        stack<int> stack; // Stack to keep track of opening parenthesis positions

        for (auto x : S)
        {
            if (x == '(')
            {
                stack.push(++a); // Increment the counter and push the current bracket number to the stack
                res.push_back(stack.top()); // Store the current bracket number as the result
            }
            if (x == ')')
            {
                res.push_back(stack.top()); // For closing parenthesis, assign the top bracket number from the stack
                stack.pop(); // Pop the bracket number from the stack as it has been used for the current closing parenthesis
            }
        }
        return res; // Return the vector containing the bracket numbers
    }
};

int main()
{
    string s;
    getline(cin, s); // Input the string containing parentheses

    Solution ob;
    vector<int> ans = ob.bracketNumbers(s); // Get the bracket numbers for the input string

    for (auto i : ans)
        cout << i << " "; // Print the bracket numbers separated by spaces

    cout << "\n";

    return 0;
}

/*
The provided code defines a C++ class Solution with a method bracketNumbers that assigns bracket numbers to each opening and closing
parenthesis in the input string. The bracketNumbers function uses a stack to keep track of the bracket numbers. When it encounters an
opening parenthesis '(', it increments a counter a, assigns the current value of a as the bracket number for the opening parenthesis,
and pushes this bracket number to the stack. When it encounters a closing parenthesis ')', it assigns the current top bracket number from
the stack to the closing parenthesis and then pops the top bracket number from the stack as it has been used for this closing parenthesis.

The main function takes an input string containing parentheses and creates an instance of the Solution class.
It calls the bracketNumbers method to get the vector of bracket numbers for the input string and then prints these bracket numbers separated
by spaces.

*/








