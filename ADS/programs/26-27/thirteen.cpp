/*
Given an array of integers, find the nearest smaller number for every element such that the smaller element is on the left side.

Input:  arr[] = {1, 6, 4, 10, 2, 5}
Output: {_, 1, 1,  4, 1, 2}

*/

#include <iostream>
#include <stack>
using namespace std;

// Prints smaller elements on the left side of every element
void printPrevSmaller(int arr[], int n) {
    // Create an empty stack
    stack<int> S;

    // Traverse all array elements
    for (int i = 0; i < n; i++) {
        // Keep removing the top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= arr[i])
            S.pop();

        // If all elements in S were greater than arr[i]
        if (S.empty())
            cout << "_, ";
        else // Else, print the nearest smaller element
            cout << S.top() << ", ";

        // Push this element into the stack
        S.push(arr[i]);
    }
}

int main() {
    int arr[] = {1, 3, 0, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function to print smaller elements on the left side
    printPrevSmaller(arr, n);

    return 0;
}

/*
This C++ program demonstrates an efficient algorithm to find and print the nearest smaller element on the left side of each element in an array.
The printPrevSmaller function utilizes a stack to maintain a history of smaller elements encountered so far. It iterates through the array and for
each element, it pops elements from the stack until it finds an element smaller than the current one. If no smaller element is found in the stack,
it prints "_," to indicate that there's no smaller element on the left side. Otherwise, it prints the nearest smaller element. After processing an
element, the current element is pushed onto the stack. The main function initializes an array and calls the printPrevSmaller function to print the
results. This code showcases the use of a stack to efficiently solve the problem of finding smaller elements on the left side of each element in an
array.

*/

