/*
Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 32. You have to copy the set bits of 'Y' in the range L to R in 'X'.
Return this modified X.

Note: Range count will be from Right to Left & start from 1.

Input:
X = 44, Y = 3
L = 1,  R = 5
Output:
47

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to set bits in the range [l, r] of integer x based on corresponding bits in integer y.
    int setSetBit(int x, int y, int l, int r) {
        int i = 1;
        while (i <= r) {
            if (i >= l) {
                if (y & 1) {
                    int mask = 1 << (i - 1);   // Create a bitmask with the i-th bit set.
                    x = x | mask;             // Set the corresponding bit in x based on the i-th bit of y.
                }
            }
            y /= 2;  // Right shift y to check the next bit.
            i++;
        }
        return x;
    }
};


int main() {
    int x, y, l, r;
    cin >> x >> y >> l >> r;

    Solution ob;
    cout << ob.setSetBit(x, y, l, r) << "\n";   // Call the setSetBit function and print the result.

    return 0;
}

/*
The #include <bits/stdc++.h> is a shortcut to include all standard library headers in one line.
While it's convenient for quick coding and competitions, it's not recommended for production code as it increases compilation time and can include
unnecessary headers.

The using namespace std; statement allows using standard library functions and classes without explicitly specifying the std:: namespace prefix.
The class Solution defines a class that contains the function setSetBit to modify bits in the integer x.

The setSetBit function takes four parameters: x (the integer in which bits will be set), y (the integer whose bits will be used to set bits in x), l (the starting index of the range), and r (the ending index of the range).
The function initializes i to 1, which represents the position of the least significant bit in the binary representation.

The while loop is used to iterate over each bit of y from the least significant bit (rightmost bit) to the most significant bit (leftmost bit).
The condition i >= l ensures that we are only considering bits in the range [l, r].

The condition y & 1 checks if the least significant bit of y is set (equal to 1). If true, it means we need to set the corresponding bit in x.
To set the corresponding bit in x, a bitmask is created using 1 << (i-1). This creates a bitmask with the i-th bit set (1-based indexing).
The bitwise OR operation x = x | mask sets the i-th bit of x to 1 if it needs to be set.
After processing the current bit, y is right-shifted by 1 position using y /= 2, effectively moving to the next bit for processing.
The loop continues until all bits of y have been processed.
Finally, the function returns the modified integer x.
In the main function, the user is prompted to enter four integers x, y, l, and r.
An object of the Solution class is created (named ob).
The setSetBit function is called on the object ob, passing the entered integers x, y, l, and r.
The modified value of x with bits set according to y is printed on the console.

*/


