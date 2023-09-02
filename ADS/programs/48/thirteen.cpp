/*
Write a C++ code to rotate bits of number n by specified number d.

Input:  n=16 d=2
Output:
Left Rotation of 16 by 2 is 64
Right Rotation of 16 by 2 is 4

*/

#include<iostream>

using namespace std;
#define INT_BITS 32
class test
{

/*Function to left rotate n by d bits*/
public:
int leftRotate(int n, unsigned int d)
{

	/* In n<<d, last d bits are 0. To put first 3 bits of n at
	last, do bitwise or of n<<d with n >>(INT_BITS - d) */
	return (n << d)|(n >> (INT_BITS - d));
}

/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d)
{
	/* In n>>d, first d bits are 0.To put last 3 bits of at first, do bitwise or of n>>d with n <<(INT_BITS - d) */
	return (n >> d)|(n << (INT_BITS - d));
}
};

int main()
{
	test g;
	int n = 16;
	int d = 2;
	cout << "Left Rotation of " << n <<" by " << d << " is ";
	cout << g.leftRotate(n, d);
	cout << "\nRight Rotation of " << n <<" by " << d << " is ";
	cout << g.rightRotate(n, d);
	getchar();
}

/*
It defines a test class, which contains two member functions: leftRotate and rightRotate.

Inside the leftRotate function:

It takes two parameters: an integer n and an unsigned integer d, where n is the number to be rotated, and d is the number of bits to rotate it by to the left.
The function performs a left rotation by d bits using bitwise operations.
It left-shifts n by d bits ( n << d ) to move the last d bits to the leftmost position.
It then performs a right shift of n by (INT_BITS - d) bits to bring the first (INT_BITS - d) bits from n to the rightmost position.
Finally, it performs a bitwise OR operation between the left-shifted and right-shifted values to combine them and get the left-rotated result.
Inside the rightRotate function:

It takes two parameters, similar to the leftRotate function: an integer n and an unsigned integer d.
The function performs a right rotation by d bits using bitwise operations.
It right-shifts n by d bits (n >> d) to move the last d bits to the rightmost position.
It then performs a left shift of n by (INT_BITS - d) bits to bring the first (INT_BITS - d) bits from n to the leftmost position.
Finally, it performs a bitwise OR operation between the right-shifted and left-shifted values to combine them and get the right-rotated result.

*/



