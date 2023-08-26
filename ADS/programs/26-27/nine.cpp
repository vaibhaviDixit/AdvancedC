
/*
Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of
every element in the array.

Input : arr[] = {2, 1, 8}
Output : 1

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4

*/


#include<bits/stdc++.h>
using namespace std;

// Function to fill left smaller element for every
// element of arr[0..n-1]. These values are filled
// in SE[0..n-1]
void leftSmaller(int arr[], int n, int SE[]) {
    // Create an empty stack
    stack<int> S;

    // Traverse all array elements
    // compute nearest smaller elements of every element
    for (int i = 0; i < n; i++) {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= arr[i])
            S.pop();

        // Store the smaller element of the current element
        if (!S.empty())
            SE[i] = S.top();

        // If all elements in S were greater than arr[i]
        else
            SE[i] = 0;

        // Push this element
        S.push(arr[i]);
    }
}

// Function returns the maximum difference between
// Left & right smaller elements
int findMaxDiff(int arr[], int n) {
    int LS[n]; // To store left smaller elements

    // Find left smaller element of every element
    leftSmaller(arr, n, LS);

    // Find right smaller element of every element
    // First reverse the array and do the same process
    int RRS[n]; // To store right smaller elements in reverse array
    reverse(arr, arr + n);
    leftSmaller(arr, n, RRS);

    // Find the maximum absolute difference between LS & RRS
    // In the reversed array, right smaller for arr[i] is stored at RRS[n-i-1]
    int result = -1;
    for (int i = 0; i < n; i++)
        result = max(result, abs(LS[i] - RRS[n - 1 - i]));

    // Return the maximum difference between LS & RRS
    return result;
}


int main() {
    int arr[] = {12, 8, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum diff : " << findMaxDiff(arr, n) << endl;
    return 0;
}

/*
This program calculates the maximum difference between the left and right smaller elements of each element in the given array.
It uses a stack-based approach to compute the nearest smaller elements on the left for each element. Then, by reversing the array and using the
same approach, it calculates the nearest smaller elements on the right for each element. The program then computes the maximum absolute difference
between the left and right smaller elements for each element in the original array. This code showcases an application of stacks for solving problems
related to finding elements smaller than the current element on both sides.

*/


