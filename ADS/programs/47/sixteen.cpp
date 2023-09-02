/*
Given a number of friends who have to give or take some amount of money from one another. Design an algorithm by which the total cash flow among all the
friends is minimized.

Input:
{ 0, 1000, 2000 }
{ 0, 0, 5000 }
{ 0, 0, 0 }

Output:
Person 1 pays 4000 to Person 2
Person 0 pays 3000 to Person 2

*/


// C++ program to find maximum cash flow among a set of persons
#include <bits/stdc++.h>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
	int minInd = 0;
	for (int i = 1; i < N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
	int maxInd = 0;
	for (int i = 1; i < N; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y) { return (x < y) ? x : y; }

// amount[p] indicates the net amount to be credited/debited to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]
void minCashFlowRec(int amount[])
{
	// Find the indexes of minimum and maximum values in amount[] amount[mxCredit] indicates the maximum
	// amount to be given (or credited) to any person .
	// And amount[mxDebit] indicates the maximum amount to
	// be taken (or debited) from any person.
	// So if there is a positive value in amount[], then there must be a negative value
	int mxCredit = getMax(amount), mxDebit = getMin(amount);

	// If both amounts are 0, then all amounts are settled
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	// Find the minimum of two amounts
	int min = minOf2(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= min;
	amount[mxDebit] += min;

	// If minimum is the maximum amount to be
	cout << "Person " << mxDebit << " pays " << min
		<< " to "
		<< "Person " << mxCredit << endl;

	// Recur for the amount array. Note that it is guaranteed that the recursion would terminate as
	// either amount[mxCredit] or amount[mxDebit] becomes 0
	minCashFlowRec(amount);
}

// Given a set of persons as graph[] where graph[i][j] indicates the amount that person i needs to pay person j,
// this function finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
	// Create an array amount[], initialize all value in it as 0.
	int amount[N] = { 0 };

	// Calculate the net amount to be paid to person 'p',
	// and stores it in amount[p]. The value of amount[p] can be calculated by subtracting debts of 'p' from credits of 'p'
	for (int p = 0; p < N; p++)
		for (int i = 0; i < N; i++)
			amount[p] += (graph[i][p] - graph[p][i]);

	minCashFlowRec(amount);
}

int main()
{
	// graph[i][j] indicates the amount that person i needs to pay person j
	int graph[N][N] = {
		{ 0, 1000, 2000 },
		{ 0, 0, 5000 },
		{ 0, 0, 0 },
	};

	// Print the solution
	minCashFlow(graph);
	return 0;
}

/*
The program defines some constants:

N: The number of persons or entities involved.
Two utility functions are defined:

getMin(arr): This function takes an array arr as input and returns the index of the minimum value in the array.
getMax(arr): This function takes an array arr as input and returns the index of the maximum value in the array.
These functions are used to find the persons who owe the most and those who are owed the most.
Another utility function is defined:

minOf2(x, y): This function takes two integers x and y as input and returns the minimum of the two values.
The core of the program is the minCashFlowRec function, which calculates and prints the minimum cash flow to settle debts and credits recursively. It takes the following parameters:

amount[]: An array representing the net amount to be credited or debited to/from each person.
Inside the function:

It calculates the persons who owe the most (mxDebit) and those who are owed the most (mxCredit) using the getMin and getMax utility functions.
If both amounts are zero, it means all amounts are settled, so the function returns.
It finds the minimum amount to be settled (the minimum of the absolute values of the debits and credits) and performs the settlement, reducing the amount to be credited to the creditor and increasing the amount to be debited from the debtor.
It prints the settlement operation, showing the person who pays and the person who receives.
The function then calls itself recursively to settle the remaining amounts.
The minCashFlow function is the main function that calculates the minimum cash flow. It takes a 2D array graph[][] as input, where graph[i][j] indicates the amount that person i needs to pay to person j.

Inside the function:

An array amount[] is created and initialized to all zeros. This array will store the net amount to be paid to each person.
A nested loop calculates the net amount to be paid to each person by iterating over all transactions in the graph[][] array.
After calculating the net amounts, the minCashFlowRec function is called with the amount[] array to find and print the minimum cash flow.
In the main function:

A 2D array graph[N][N] is defined to represent the transactions between persons. In this example, the array is initialized with sample data.
The minCashFlow function is called with the graph[][] array to find the minimum cash flow and settle the debts and credits.
The program prints the results to the console.

*/


