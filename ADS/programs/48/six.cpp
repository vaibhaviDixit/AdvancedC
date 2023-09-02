/*
Given a number x, find next number with same number of 1 bits in it’s binary representation.
For example, consider x = 12, whose binary representation is 1100 (excluding leading zeros on 32 bit machine). It contains two logic 1 bits.
The next higher number with two logic 1 bits is 17 (100012).

Input: 156
Output: Next higher number with same number of set bits is 163

*/

#include<iostream>

using namespace std;

typedef unsigned int uint_t;

// this function returns next higher number with same number of set bits as x.
uint_t snoob(uint_t x)
{

    uint_t rightOne;
    uint_t nextHigherOneBit;
    uint_t rightOnesPattern;

    uint_t next = 0;

    if(x)
    {

        // right most set bit
        rightOne = x & -(signed)x;

        // reset the pattern and set next higher bit
        // left part of x will be here
        nextHigherOneBit = x + rightOne;

        // nextHigherOneBit is now part [D] of the above explanation.

        // isolate the pattern
        rightOnesPattern = x ^ nextHigherOneBit;

        // right adjust pattern
        rightOnesPattern = (rightOnesPattern)/rightOne;

        // correction factor
        rightOnesPattern >>= 2;

        // rightOnesPattern is now part [A] of the above explanation.

        // integrate new pattern (Add [D] and [A])
        next = nextHigherOneBit | rightOnesPattern;
    }

    return next;
}

int main()
{
    int x = 156;
    cout<<"Next higher number with same number of set bits is "<<snoob(x);

    getchar();
    return 0;
}

/*
It defines a type alias uint_t to represent an unsigned integer.

The snoob function takes an unsigned integer x as input and returns the next higher number with the same number of set bits as x.

Inside the snoob function:

It declares several unsigned integer variables, including rightOne, nextHigherOneBit, rightOnesPattern, and next, which will be used for intermediate calculations.
It checks if x is not equal to 0 (i.e., x is a non-zero value).
If x is non-zero, it proceeds with the following steps:
It calculates the rightmost set bit of x and stores it in rightOne by performing a bitwise AND operation with the two's complement of x (-(signed)x). This operation isolates the rightmost set bit.
It calculates the next higher number with the same number of set bits as x by adding rightOne to x and stores the result in nextHigherOneBit.
It calculates rightOnesPattern by XORing x with nextHigherOneBit. This operation isolates the pattern of set bits that need to be adjusted.
It right-adjusts the pattern in rightOnesPattern by dividing it by rightOne (the rightmost set bit) and stores the result back in rightOnesPattern.
It applies a correction factor by right-shifting rightOnesPattern by 2 bits.
Finally, it integrates the new pattern by performing a bitwise OR operation between nextHigherOneBit and rightOnesPattern, which gives the next higher number with the same number of set bits.
In the main function:

An integer variable x is initialized with the value 156.
The program calls the snoob function with x as an argument to find the next higher number with the same number of set bits.
It then prints the result to the console using cout, along with a descriptive message.

*/



