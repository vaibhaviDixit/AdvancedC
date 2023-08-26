/*
Write a program to reverse a stack using recursion, without using any loop.

Input: elements present in stack from top to bottom 1 2 3 4
Output: 4 3 2 1

*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to insert an element at the bottom of a stack
void insert_at_bottom(stack<int>& st, int x) {
    if (st.size() == 0) {
        st.push(x);
    } else {
        // Pop the top item from the stack and recursively insert
        // the element at the bottom of the remaining stack
        int a = st.top();
        st.pop();
        insert_at_bottom(st, x);
        // Push the popped item back after inserting the new element
        st.push(a);
    }
}

// Function to reverse a stack using insert_at_bottom()
void reverse(stack<int>& st) {
    if (st.size() > 0) {
        // Pop the top item and recursively reverse the remaining stack
        int x = st.top();
        st.pop();
        reverse(st);
        // Insert the popped item at the bottom of the reversed stack
        insert_at_bottom(st, x);
    }
    return;
}

int main() {
    stack<int> st, st2;

    // Push elements into the stack
    for (int i = 1; i <= 4; i++) {
        st.push(i);
    }

    st2 = st;

    cout << "Original Stack" << endl;
    // Printing the stack before reversal
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    // Function to reverse the stack
    reverse(st);
    cout << "Reversed Stack" << endl;
    // Printing the stack after reversal
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

/*
This C++ program demonstrates how to reverse a stack using recursion. The insert_at_bottom function is a recursive helper function that takes a
stack and an element as input and inserts the element at the bottom of the stack. The reverse function uses the insert_at_bottom function to
reverse the entire stack. It pops the top element from the stack, recursively reverses the remaining stack, and then inserts the popped element
at the bottom of the reversed stack. The main function initializes a stack, pushes elements into it, and demonstrates both the original and reversed
stacks. This code showcases the use of recursion to reverse the elements of a stack while maintaining its LIFO (Last In First Out) property.

*/

