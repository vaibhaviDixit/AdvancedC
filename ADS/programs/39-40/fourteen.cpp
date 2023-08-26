/*
Given an array arr[] containing n elements. The problem is to find the maximum number of distinct elements (non-repeating) after removing k elements from the array.
Note: 1 <= k <= n.

Input : arr[] = {5, 7, 5, 5, 1, 2, 2}, k = 3
Output : 4

Input : arr[] = {1, 2, 3, 4, 5, 6, 7}, k = 5
Output : 2

Input : arr[] = {1, 2, 2, 2}, k = 1
Output : 1

*/

#include <bits/stdc++.h>
using namespace std;

// function to find maximum distinct elements after removing k elements
int maxDistinctNum(int a[], int n, int k)
{
    int i;
    multiset<int> s;
   // making multiset from given array
    for(i=0; i<n; i++)
    {
        if(s.find(a[i])==s.end()||k==0)
            s.insert(a[i]);
        else
        {
            k--;
        }
    }

    if(k!=0)
        return s.size()-k;
    else
    {
        set<int> st;
        for(auto it:s)
        {
            st.insert(it);
        }
        return st.size();
    }
}

int main()
{
    int arr[] = { 5, 7, 5, 5, 1, 2, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // Function Call
    cout << "Maximum distinct elements = "
         << maxDistinctNum(arr, n, k);
    return 0;
}


/*
This C++ program finds the maximum number of distinct elements that can be obtained by removing at most k elements from an array.
It uses a multiset data structure to store the elements of the array, allowing duplicates while maintaining a sorted order.
The program iterates through the array, adding each element to the multiset while also considering the removal of k elements.

The main logic revolves around maintaining the multiset such that it contains only distinct elements.
If a duplicate element is encountered, one of the occurrences is removed as long as there are available removals (k > 0).
If k becomes zero, the program creates a set from the remaining elements in the multiset to ensure uniqueness and then returns the size of the set.
Otherwise, if k is still available, the program returns the size of the multiset minus k.

*/


