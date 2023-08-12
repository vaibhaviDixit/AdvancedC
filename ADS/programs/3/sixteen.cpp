/*
Given an array of integers, find all elements that appear more than once in the array.
Time complexity should be O(n).

Input: arr=  {4, 3, 2, 7, 8, 2, 9, 1,9}
Output: 2, 9

*/

#include <iostream>
using namespace std;

void findDuplicates(int arr[], int n) {
    const int MAX = 100000; // Assuming maximum value of array elements
    int bitset[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (bitset[arr[i]] == 1) {
            cout << arr[i] << " ";
        }
        bitset[arr[i]]++;
    }
}

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Duplicate elements: ";
    findDuplicates(arr, n);

    return 0;
}
