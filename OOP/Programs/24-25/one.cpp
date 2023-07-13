/*
Calculate the sum of elements in an integer array using pointer arithmetic.

Input: {1, 2, 3, 4, 5}
Output: Sum of array elements: 15

*/

#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    int sum = 0;

    while (ptr < arr + 5) {
        sum += *ptr;
        ptr++;
    }

    std::cout << "Sum of array elements: " << sum << std::endl;

    return 0;
}


/*
The program initializes an integer array arr and a pointer ptr pointing to the first element of the array.
It then uses a while loop to iterate through the array using pointer arithmetic.
The value pointed to by ptr is added to the sum variable, and the pointer is incremented to point to the next
element.
Finally, the program prints the sum of the array elements.
*/
