/*
Write a C++ program that creates a deque with the following elements (30, 10, 50, 20, 40).
Use the std::sort algorithm to sort the deque in ascending order and print the sorted deque.

Input: myDeque = {50, 20, 10, 40, 30}
Output: Sorted Deque: 10 20 30 40 50

*/

#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::deque<int> myDeque = {50, 20, 10, 40, 30};

    // Sorting the deque in ascending order
    std::sort(myDeque.begin(), myDeque.end());

    // Printing the sorted elements of the deque
    std::cout << "Sorted Deque: ";
    for (int num : myDeque) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Output:
    // Sorted Deque: 10 20 30 40 50

    return 0;
}


/*
This program demonstrates how to sort a deque using the std::sort algorithm from the C++ STL.
The std::sort function takes the beginning and ending iterators of the deque as arguments and rearranges its elements in ascending order.

*/
