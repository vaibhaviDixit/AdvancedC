/*
Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.

Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
Output: 240
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg.
Hence total price will be 60+100+(2/3)(120) = 240

Input:  arr[] = {{500, 30}}, W = 10
Output: 166.667

*/


// C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and corresponding value of Item
struct Item {
	int profit, weight;

	// Constructor
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};

// Comparison function to sort Item according to profit/weight ratio
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {

		// If adding Item won't overflow, add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}

		// If we can't add current Item, add fractional part of it
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}


int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}

/*
Struct Item:

The Item struct defines the properties of each item in the problem: profit and weight.
Comparison Function:

The cmp function is used as a comparison function for sorting the items based on the profit-to-weight ratio. It is used to sort the items in descending order of their ratio, which helps in selecting items with higher ratios first.
Main Greedy Function fractionalKnapsack:

This function takes the total weight capacity W, an array of Item objects arr, and the number of items N.
It first sorts the arr array using the cmp comparison function, placing items with higher profit-to-weight ratios at the beginning.
It initializes finalvalue to 0.0, which will store the maximum possible value that can be obtained.
It iterates through the sorted array of items using a loop.
For each item, it checks whether the entire item can be added to the knapsack (arr[i].weight <= W). If so, the item's profit is added to finalvalue, and its weight is subtracted from W.
If the entire item cannot be added, a fractional part of the item is added to the knapsack, and the loop is terminated (break statement).
The function returns finalvalue, which represents the maximum value that can be obtained within the given weight capacity.
Main Function:

In the main function, the total weight capacity W is set to 50.
An array of Item objects arr is defined, containing the profit and weight of each item.
The number of items N is calculated using the sizeof operator.
The fractionalKnapsack function is called with the arguments W, arr, and N, and the result is printed.

*/


