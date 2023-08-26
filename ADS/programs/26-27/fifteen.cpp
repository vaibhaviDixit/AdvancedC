/*
Given a sequence of n strings, the task is to check if any two similar words come together and then destroy each other then print the number of words
left in the sequence after this pairwise destruction.


Input : ab aa aa bcd ab
Output : 3

*/


#include<bits/stdc++.h>
using namespace std;

// Function to find the size of the manipulated sequence
int removeConsecutiveSame(vector<string> v) {
    stack<string> st;

    // Start traversing the sequence
    for (int i = 0; i < v.size(); i++) {
        // Push the current string if the stack is empty
        if (st.empty())
            st.push(v[i]);
        else {
            string str = st.top();

            // Compare the current string with the stack top
            // If equal, pop the top
            if (str.compare(v[i]) == 0)
                st.pop();
            // Otherwise, push the current string
            else
                st.push(v[i]);
        }
    }

    // Return stack size, which represents the size of the manipulated sequence
    return st.size();
}


int main() {
    vector<string> V = { "ab", "aa", "aa", "bcd", "ab" };

    // Call the removeConsecutiveSame function and print the result
    cout << "Size of manipulated sequence: " << removeConsecutiveSame(V);
    return 0;
}

/*
This C++ program implements a method to find the size of a manipulated sequence by removing consecutive same elements.
The removeConsecutiveSame function takes a vector of strings as input and uses a stack to process the elements.
It iterates through the vector and checks if the current string is the same as the one at the top of the stack.
If they are the same, the top element is popped; otherwise, the current string is pushed onto the stack. After processing all elements,
the size of the stack represents the size of the manipulated sequence. The main function initializes a vector with strings, calls the
removeConsecutiveSame function, and prints the size of the manipulated sequence. This code demonstrates the use of a stack to manipulate
and compute properties of a sequence of elements.

*/


