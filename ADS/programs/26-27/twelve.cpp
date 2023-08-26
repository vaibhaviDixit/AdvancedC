/*
Given an array arr[] of size N, the task to reverse the array using Stack.

Input: arr[] = { 100, 200, 300, 400, 500 }
Output: 500 400 300 200 100

*/

#include <iostream>
#include <stack> // Including Stack ( push, pop, empty, size... etc)

using namespace std;

// Function to reverse an array using a stack
void reverse(int arr[], int n) {
    stack<int> st; // Create a stack containing integers

    // Push all elements of the array into the stack
    for (int i = 0; i < n; i++) {
        st.push(arr[i]);
    }

    int i = 0; // To update elements of array at ith index

    // Run a loop until the stack is not empty
    while (!st.empty()) {
        // Get the top element of the stack and pop it
        int top = st.top();
        st.pop();

        // Update the ith index of the array
        arr[i] = top;

        // Increment i
        i++;
    }

    // Traverse the array to print all elements
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return;
}

int main() {
    int n = 4;

    // Create a new array
    int arr[] = {100, 200, 300, 400};

    // Call the reverse method
    reverse(arr, n);

    return 0;
}

/*
This C++ program demonstrates how to reverse an array using a stack. The program includes the necessary header <iostream> for input/output and <stack>
for using the stack container. The reverse function takes an array and its size as parameters and reverses the array using a stack.
It pushes all the elements of the array onto the stack and then pops them off one by one to update the array in reverse order.
The main function creates an array, calls the reverse function, and prints the reversed array. The program showcases the use of
the stack container to efficiently reverse the elements of an array.

*/

