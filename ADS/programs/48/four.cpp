/*
Write CPP program to swap two numbers using bit manipulation

Input: a=5 b=7
Output: a=7 b=5

*/

#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 7;
	cout<<"Before Swapping, a = "<<a<<" "<<"b = "<<b<<endl;
	a ^= b;
	b ^= a;
	a ^= b;
	cout<<"After Swapping, a = "<<a<<" "<<"b = "<<b<<endl;
	return 0;
}

/*
In the main function, two integer variables, a and b, are declared and initialized with the values 5 and 7, respectively.

The program prints the values of a and b before swapping to the console using the cout statement. The output displays "Before Swapping, a = 5 b = 7."

The swapping process begins using bitwise XOR (^) operations. XOR is used because it has the property that if you XOR a value twice with the same other value, it returns the original value. This property allows us to swap values without using a temporary variable.

The following lines perform the swap:

a ^= b;: This line XORs a with b and stores the result back in a. Now, a contains the XOR of the original a and b.
b ^= a;: This line XORs b with the updated a and stores the result back in b. This effectively replaces the original b with the original a.
a ^= b;: Finally, this line XORs the updated a with the updated b and stores the result back in a. This step replaces the original a with the original b, completing the swap.
After the swap, the program prints the updated values of a and b to the console using the cout statement. The output displays "After Swapping, a = 7 b = 5."

*/
