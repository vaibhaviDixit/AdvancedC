/*
Given a positive integer N, print count of set bits in it.

Input: N = 6
Output: 2

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of set bits in the binary representation of N.
    int setBits(int N) {
        int count = 0;
        while (N > 0) {
            if ((N & 1) == 1)   // Check if the last bit is set (equal to 1).
                count++;
            N = N >> 1;         // Right shift N to remove the last bit.
        }
        return count;
    }
};

int main() {
    int N;
    cin >> N;

    Solution ob;
    int cnt = ob.setBits(N);    // Call the setBits function to count the set bits.
    cout << cnt << endl;

    return 0;
}

/*
This C++ program demonstrates how to count the number of set bits in the binary representation of a given integer N. The program uses the class Solution to encapsulate the function setBits.

The #include <bits/stdc++.h> is a shortcut to include all standard library headers in one line. While it's convenient for quick coding and competitions, it's not recommended for production code as it increases compilation time and can include unnecessary headers.
The using namespace std; statement allows using standard library functions and classes without explicitly specifying the std:: namespace prefix.
The class Solution defines a class that contains the function setBits to count the set bits in an integer.
Inside the setBits function, the variable count is used to keep track of the number of set bits.
The while loop is used to check each bit of the integer N one by one from the least significant bit (rightmost bit).
The condition (N & 1) == 1 checks if the last bit of N is set (equal to 1). If true, it increments the count.
The N = N >> 1 statement right-shifts N by one position, effectively removing the last bit and setting up the next bit to be checked in the next iteration.
The loop continues until all bits of N have been checked (i.e., N becomes 0).
Finally, the function returns the count of set bits.
In the main function, the user is prompted to enter an integer N.
An object of the Solution class is created (named ob).
The setBits function is called on the object ob, passing the entered integer N.
The result (count of set bits) is stored in the variable cnt and displayed on the console.

*/
