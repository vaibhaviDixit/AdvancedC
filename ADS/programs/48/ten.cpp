/*
Compute the minimum or maximum of two integers without branching

Input: x=15 y=6
Output:
Minimum of 15 and 6 is 6
Maximum of 15 and 6 is 15

*/

// C++ program to Compute the minimum or maximum of two integers without branching
#include<iostream>
using namespace std;

class gfg
{

    /*Function to find minimum of x and y*/
public:
    int min(int x, int y)
    {
        return y ^ ((x ^ y) & -(x < y));
    }

    /*Function to find maximum of x and y*/
    int max(int x, int y)
    {
        return x ^ ((x ^ y) & -(x < y));
    }
};


int main()
{
    gfg g;
    int x = 15;
    int y = 6;
    cout << "Minimum of " << x <<
         " and " << y << " is ";
    cout << g. min(x, y);
    cout << "\nMaximum of " << x <<
         " and " << y << " is ";
    cout << g.max(x, y);
    getchar();
}

/*
It defines a class named gfg (short for GeeksforGeeks) to encapsulate the minimum and maximum functions.

Inside the gfg class:

The min function takes two integers x and y as parameters and returns the minimum of the two.

It computes the minimum by performing the following operations:
x < y is evaluated, which results in a boolean value (1 if true, 0 if false).
- (x < y) calculates the two's complement of the boolean value. This is used to create a mask with all bits set to 1 if x is less than y and all bits set to 0 otherwise.
(x ^ y) & -(x < y) combines x and y using XOR and the mask from step 2. This effectively selects x if x is less than y and selects y otherwise. This is achieved by XORing x and y and then applying the mask.
The max function is similar but returns the maximum of x and y instead.

In the main function:

An instance of the gfg class is created and named g.
Two integer variables x and y are initialized with the values 15 and 6, respectively.
The program prints the minimum of x and y by calling g.min(x, y) and displays the result.

It then prints the maximum of x and y by calling g.max(x, y) and displays the result.

*/
