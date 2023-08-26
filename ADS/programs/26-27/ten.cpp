/*
Given a stack S, the task is to copy the content of the given stack S to another stack T maintaining the same order.

Input: Source:- 5 4 3 2 1
Output: Destination:- 5 4 3 2 1

*/

#include <bits/stdc++.h>
using namespace std;

// Auxiliary function to copy elements
// of the source stack to the destination stack
void RecursiveCloneStack(stack<int>& S, stack<int>& Des) {
    // Base case for Recursion
    if (S.size() == 0)
        return;

    // Stores the top element of the source stack
    int val = S.top();

    // Removes the top element of the source stack
    S.pop();

    // Recursive call to the function with the remaining stack
    RecursiveCloneStack(S, Des);

    // Push the top element of the source stack into the Destination stack
    Des.push(val);
}

// Function to copy the elements of the source stack to the destination stack
void cloneStack(stack<int>& S) {
    // Stores the destination stack
    stack<int> Des;

    // Recursive function call to copy the source stack to the destination stack
    RecursiveCloneStack(S, Des);

    cout << "Destination:- ";
    int f = 0;

    // Iterate until stack Des is non-empty
    while (!Des.empty()) {
        if (f == 0) {
            cout << Des.top();
            f = 1;
        } else
            cout << "           " << Des.top();
        Des.pop();
        cout << '\n';
    }
}

int main() {
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    cloneStack(S);
    return 0;
}

/*
This program demonstrates a recursive approach to copying elements from one stack to another while maintaining their order.
The RecursiveCloneStack function uses recursion to copy elements from the source stack (S) to the destination stack (Des).
It pops the top element from the source stack, recursively calls itself for the remaining elements, and then pushes the popped element
into the destination stack. The cloneStack function is the entry point that initializes the destination stack and calls the recursive function.
After copying, the program prints the elements of the destination stack. This code showcases the use of recursion for operations on stacks and
demonstrates how to clone a stack while preserving its order.

*/

