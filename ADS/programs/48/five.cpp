/*

Write a  C++ program for getbit, setbit and clearbit in the number.

Input: 70
Output:
The bit at the 3rd position from LSB is: 0
The value of the given number after setting the bit at LSB is: 71
The value of the given number after clearing the bit at LSB is: 70

*/

#include <bits/stdc++.h>
using namespace std;

// Function to get the bit at the ith position
bool getBit(int num, int i)
{
	// Return true if the ith bit is
	// set. Otherwise return false
	return ((num & (1 << i)) != 0);
}

// Function to set the ith bit of the given number num
int setBit(int num, int i)
{
	// Sets the ith bit and return
	// the updated value
	return num | (1 << i);
}

// Function to clear the ith bit of the given number num
int clearBit(int num, int i)
{

	// Create the mask for the ith
	// bit unset
	int mask = ~(1 << i);

	// Return the updated value
	return num & mask;
}


int main()
{
	// Given number N
	int N = 70;

	cout << "The bit at the 3rd position from LSB is: "
		<< (getBit(N, 3) ? '1' : '0')
		<< endl;

	cout << "The value of the given number after setting the bit at LSB is: "
		<< setBit(N, 0) << endl;

	cout << "The value of the given number after clearing the bit at LSB is: "
		<< clearBit(N, 0) << endl;

	return 0;
}

/*
Three functions are defined to perform bitwise operations on an integer num:

getBit(int num, int i): This function checks if the i-th bit (0-based index from the right) of the given num is set (1) or unset (0). It uses a bitwise AND operation (&) with a mask to isolate the i-th bit and returns true if the result is non-zero (bit set), and false otherwise.
setBit(int num, int i): This function sets the i-th bit of the given num to 1 and returns the updated value. It uses a bitwise OR operation (|) with a mask that has only the i-th bit set to 1.
clearBit(int num, int i): This function clears (sets to 0) the i-th bit of the given num and returns the updated value. It creates a mask by flipping (inverting) only the i-th bit to 0 and uses a bitwise AND operation (&) with the mask to clear the bit.
In the main function:

An integer N is initialized with the value 70.
The program demonstrates the three bitwise operations:

It calls getBit(N, 3) to check if the 3rd bit from the least significant bit (LSB) of N is set (1) or unset (0). It prints the result, which is either '1' or '0', indicating the state of the bit.
It calls setBit(N, 0) to set the least significant bit (LSB) of N to 1 and prints the updated value of N.
It calls clearBit(N, 0) to clear the least significant bit (LSB) of N by setting it to 0 and prints the updated value of N.

*/


