/*
The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate the span of the
stock’s price for all N days. The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before
the given day, for which the price of the stock on the current day is less than its price on the given day.

Input: N = 6, price[] = [10 4 5 90 120 80]
Output:1 1 2 4 5 1

*/


#include <bits/stdc++.h>
using namespace std;

// A stack-based efficient method to calculate stock span values
void calculateSpan(int price[], int n, int S[]) {
    // Create a stack and push the index of the first element to it
    stack<int> st;
    st.push(0);

    // The span value of the first element is always 1
    S[0] = 1;

    // Calculate span values for the rest of the elements
    for (int i = 1; i < n; i++) {
        // Pop elements from the stack while the stack is not
        // empty and the top of the stack is smaller than price[i]
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        // If the stack becomes empty, then price[i] is greater
        // than all elements on the left of it, i.e., price[0],
        // price[1], ..price[i-1]. Otherwise, price[i] is greater
        // than elements after the top of the stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push this element's index to the stack
        st.push(i);
    }
}

// A utility function to print elements of an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int price[] = { 10, 4, 5, 90, 120, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];

    // Fill the span values in array S[]
    calculateSpan(price, n, S);

    // Print the calculated span values
    printArray(S, n);

    return 0;
}

/*
This program demonstrates an efficient algorithm for calculating the stock span of a given array, which represents the number of consecutive
days before the current day where the stock price was less than or equal to the current day's price. The calculateSpan function uses a stack-based
approach to iterate through the array and calculate the span values. It pushes the indices of the elements onto the stack while comparing their prices.
The span values are calculated using the difference between the current index and the top of the stack. The program then prints the calculated span
values using the printArray function. This code showcases an application of stacks for solving stock market-related problems with linear time complexity.

*/



