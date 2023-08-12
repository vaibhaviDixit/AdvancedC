/*
You are given a lock which is made up of n-different circular rings and each ring has 0-9 digit printed serially on it.
Initially all n-rings together show a n-digit integer but there is particular code only which can open the lock.
You can rotate each ring any number of time in either direction. You have to find the minimum number of rotation done on rings of lock to open the
lock.

Input : Input = 1919, Unlock code = 0000
Output : Rotations required = 4

*/

// CPP program for min rotation to unlock
#include <bits/stdc++.h>
using namespace std;

// function for min rotation
int minRotation(int input, int unlock_code)
{
	int rotation = 0;
	int input_digit, code_digit;

	// iterate till input and unlock code become 0
	while (input || unlock_code) {

		// input and unlock last digit as reminder
		input_digit = input % 10;
		code_digit = unlock_code % 10;

		// find min rotation
		rotation += min(abs(input_digit - code_digit),
				10 - abs(input_digit - code_digit));

		// update code and input
		input /= 10;
		unlock_code /= 10;
	}

	return rotation;
}

int main()
{
	int input = 28756;
	int unlock_code = 98234;
	cout << "Minimum Rotation = "
		<< minRotation(input, unlock_code);
	return 0;
}

/*
The program defines a function minRotation that takes two integer arguments: input and unlock_code.

The function iterates until both input and unlock_code become 0. In each iteration, it performs the following steps:

a. It calculates the last digit of input and unlock_code using the modulo operator (%) and stores them in input_digit and code_digit, respectively.

b. To find the minimum rotation needed to move from input_digit to code_digit, it calculates the absolute difference between the two digits. Since the digits can be in a cyclic order (0 to 9), it also considers the "wrapping around" difference (e.g., the difference between 0 and 9 is also 1). This is done using the expression min(abs(input_digit - code_digit), 10 - abs(input_digit - code_digit)).

c. The calculated rotation value is added to the rotation variable, which keeps track of the total minimum rotation needed.

d. It updates the input and unlock_code by removing their last digits (by dividing both by 10).

After the loop finishes, the rotation variable contains the total minimum rotation needed to move from the initial input to the unlock_code.

The main function sets the values of input and unlock_code as per the problem statement.

It calls the minRotation function with the given inputs and prints the result as "Minimum Rotation = <value>".

*/



