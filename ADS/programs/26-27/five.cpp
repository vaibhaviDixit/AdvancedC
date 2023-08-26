/*
Given a stack of integers, sort it in ascending order using another temporary stack.

Input : [4, 3, 1, 8]
Output : [1, 3, 4, 8]

*/

// C++ program to sort a stack using an auxiliary stack.
#include <bits/stdc++.h>
using namespace std;

// This function returns the sorted stack
stack<int> sortStack(stack<int> &input) {
    stack<int> tmpStack;

    while (!input.empty()) {
        // Pop out the first element
        int tmp = input.top();
        input.pop();

        // While the temporary stack is not empty and the top
        // of the stack is lesser than 'tmp'
        while (!tmpStack.empty() && tmpStack.top() < tmp) {
            // Pop from the temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        // Push 'tmp' into the temporary stack
        tmpStack.push(tmp);
    }

    return tmpStack;
}

// Main function
int main() {
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    // Use the sortStack function to sort the 'input' stack
    stack<int> tmpStack = sortStack(input);
    cout << "Sorted numbers are:\n";

    // Print the sorted numbers from the temporary stack
    while (!tmpStack.empty()) {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }

    return 0;
}

/*
This program sorts a given stack of integers using an auxiliary stack. It uses a temporary stack (tmpStack) to hold the sorted elements.
The main idea is to iterate through the input stack (input), pop elements one by one, and insert them into the tmpStack at the
appropriate positions to maintain the sorting order

*/


