/*
Given the volume V of a tank in liter. There is a pump which is filling the tank at speed of M liter per minute. There is a leakage at the
bottom of the tank which wasting water at speed N liter per minute. Given N is less than M. The task is to calculate how much amount of water
will be wasted if leakage is seen after filling the full tank.

Input : V = 700, M = 10, N = 3
Output : 300

Input : V = 1000, M = 100, N = 50
Output : 1000

*/

// C++ program to find the volume of water wasted
#include <iostream>
using namespace std;

// Function to calculate amount of wasted water
double wastedWater(double V, double M, double N)
{
	double wasted_amt, amt_per_min, time_to_fill;

	// filled amount of water in one minute
	amt_per_min = M - N;

	// total time taken to fill the tank because of leakage
	time_to_fill = V / amt_per_min;

	// wasted amount of water
	wasted_amt = N * time_to_fill;

	return wasted_amt;
}

int main()
{
	double V, M, N;
	V = 700;
	M = 10;
	N = 3;
	cout << wastedWater(V, M, N) << endl;

	V = 1000;
	M = 100;
	N = 50;
	cout << wastedWater(V, M, N) << endl;

	return 0;
}

/*

double wastedWater(double V, double M, double N): This is a function named wastedWater that takes three double precision floating-point arguments: V (total volume of the tank), M (rate at which water is being filled into the tank), and N (rate of leakage from the tank). It calculates the volume of water wasted due to leakage and returns it as a double precision floating-point value.

Inside the function:

amt_per_min = M - N;: It calculates the amount of water filled in one minute by subtracting the leakage rate N from the filling rate M. This represents the net rate of water addition to the tank.

time_to_fill = V / amt_per_min;: It calculates the total time taken to fill the tank completely, considering the net rate of water addition. The time is calculated as the ratio of the total volume V to the net filling rate amt_per_min.

wasted_amt = N * time_to_fill;: It calculates the volume of water wasted by multiplying the leakage rate N by the total time it takes to fill the tank, time_to_fill. This represents the amount of water that leaks out during the filling process.

Finally, the function returns the calculated wasted_amt as the result.

*/
