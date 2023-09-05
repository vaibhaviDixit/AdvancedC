/*
 Write a CPP code to calculate expected value of an array.

 Input: arr= { 1.0, 2.0, 3.0,4.0, 5.0, 6.0 } , n=6.0
 Output: Expectation of array E(X) is : 3.5

*/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate expectation
float calc_Expectation(float a[], float n)
{
	/*variable prb is for probability
	of each element which is same for
	each element */
	float prb = (1 / n);

	// calculating expectation overall
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * prb;

	// returning expectation as sum
	return sum;
}


int main()
{
	float expect, n = 6.0;
	float a[6] = { 1.0, 2.0, 3.0,4.0, 5.0, 6.0 };

	// Function for calculating expectation
	expect = calc_Expectation(a, n);

	// Display expectation of given array
	cout << "Expectation of array E(X) is : "
		<< expect << "\n";
	return 0;
}


/*
float calc_Expectation(float a[], float n): This is a function named calc_Expectation that takes two arguments: an array of floating-point numbers a[] and the number of elements in the array n. It calculates and returns the expectation (expected value) of the array.

Inside the function:

float prb = (1 / n);: It calculates the probability prb of each element in the array by dividing 1 by n. Since each element in the array has an equal probability of occurring, this value is constant for all elements.

float sum = 0;: It initializes a variable sum to store the sum of the products of each element with its probability.

The for loop iterates through each element of the array:

for (int i = 0; i < n; i++)
Inside the loop, it calculates the product of the current element a[i] and its probability prb and adds this product to the sum.
After calculating the sum, the function returns it as the expectation.

int main(): This is the main function where the program execution begins.

The variables expect, n, and a are declared and initialized with different values. n represents the number of elements in the array, and a is an array of floating-point numbers containing the data.

expect = calc_Expectation(a, n);: The calc_Expectation function is called with the array a and the number of elements n, and the result (the expectation of the array) is stored in the variable expect.

*/
