/*
Given a number n, the task is to find the largest perfect cube that can be formed by deleting minimum digits(possibly 0) from the number.
X is called a perfect cube if X = Y3 for some Y.

Input : 4125
Output : 125
Explanation
125 = 53. We can form 125 by deleting digit 4 from 4125

Input : 876
Output :8

*/

/* C++ code to implement maximum perfect cube formed after deleting minimum digits */
#include <bits/stdc++.h>
using namespace std;

// Returns vector of Pre Processed perfect cubes
vector<string> preProcess(long long int n)
{
	vector<string> preProcessedCubes;
	for (int i = 1; i * i * i <= n; i++) {
		long long int iThCube = i * i * i;

		// convert the cube to string and push into preProcessedCubes vector
		string cubeString = to_string(iThCube);
		preProcessedCubes.push_back(cubeString);
	}
	return preProcessedCubes;
}

/* Utility function for findLargestCube(). Returns the Largest cube number that can be formed */
string findLargestCubeUtil(string num,
					vector<string> preProcessedCubes)
{
	// reverse the preProcessed cubes so that we have the largest cube in the beginning of the vector
	reverse(preProcessedCubes.begin(), preProcessedCubes.end());

	int totalCubes = preProcessedCubes.size();

	// iterate over all cubes
	for (int i = 0; i < totalCubes; i++) {
		string currCube = preProcessedCubes[i];

		int digitsInCube = currCube.length();
		int index = 0;
		int digitsInNumber = num.length();
		for (int j = 0; j < digitsInNumber; j++) {

			// check if the current digit of the cube
			// matches with that of the number num
			if (num[j] == currCube[index])
				index++;

			if (digitsInCube == index)
				return currCube;
		}
	}

	// if control reaches here, the its
	// not possible to form a perfect cube
	return "Not Possible";
}

// wrapper for findLargestCubeUtil()
void findLargestCube(long long int n)
{
	// pre process perfect cubes
	vector<string> preProcessedCubes = preProcess(n);

	// convert number n to string
	string num = to_string(n);

	string ans = findLargestCubeUtil(num, preProcessedCubes);

	cout << "Largest Cube that can be formed from "
		<< n << " is " << ans << endl;
}

int main()
{
	long long int n;
	n = 4125;
	findLargestCube(n);

	n = 876;
	findLargestCube(n);

	return 0;
}

/*
The preProcess function is defined to precompute and store perfect cubes up to the cube root of the input number n. It takes one parameter:

n: A long long integer representing the input number.
Inside the function:

A vector of strings named preProcessedCubes is created to store the perfect cubes as strings.
A loop iterates from 1 to the largest integer i such that i * i * i <= n.
In each iteration, iThCube is calculated as i * i * i.
The to_string function is used to convert iThCube to a string, and this string is then pushed into the preProcessedCubes vector.
After the loop, the vector preProcessedCubes containing precomputed perfect cubes is returned.
The findLargestCubeUtil function is a utility function that finds the largest perfect cube that can be formed by deleting a minimum number of digits from the given number num. It takes two parameters:

num: A string representing the input number as a string.
preProcessedCubes: A vector of strings containing precomputed perfect cubes.
Inside the function:

The preProcessedCubes vector is reversed so that the largest cube is at the beginning.
The function iterates over all the cubes in the preProcessedCubes vector.
For each cube, it checks if the digits of the cube can be found in the input number num. If they can, the cube is considered as the largest cube that can be formed, and it is returned as a string.
If no cube can be formed from the input number, it returns "Not Possible."
The findLargestCube function serves as a wrapper for the findLargestCubeUtil function. It takes one parameter:

n: A long long integer representing the input number.
Inside the function:

It calls the preProcess function to precompute perfect cubes.
The input number n is converted to a string, num.
The findLargestCubeUtil function is called with num and the vector of precomputed cubes as parameters.
The result is stored in the string variable ans.
In the main function:

Two long long integers, n1 and n2, are defined as test cases.
The findLargestCube function is called twice, once with n1 and once with n2.
The results for both test cases are printed to the console.

*/

