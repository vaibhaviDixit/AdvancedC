/*
Given a list of tickets, find itinerary in order using the given list. Use hashing technique.

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,

*/

#include <bits/stdc++.h>
using namespace std;

void printItinerary(map<string, string> dataSet)
{
	// To store reverse of given map
	map<string, string> reversemap;
	map<string, string>::iterator it;

	// To fill reverse map, iterate through the given map
	for (it = dataSet.begin(); it!=dataSet.end(); it++)
		reversemap[it->second] = it->first;

	// Find the starting point of itinerary
	string start;

	for (it = dataSet.begin(); it!=dataSet.end(); it++)
	{
		if (reversemap.find(it->first) == reversemap.end())
		{
			start = it->first;
			break;
		}
	}

	// If we could not find a starting point, then something wrong with input
	if (start.empty())
	{
		cout << "Invalid Input" << endl;
		return;
	}

	// Once we have starting point, we simple need to go next, next of next using given hash map
	it = dataSet.find(start);
	while (it != dataSet.end())
	{
		cout << it->first << "->" << it->second << endl;
		it = dataSet.find(it->second);
	}

}

int main()
{
	map<string, string> dataSet;
	dataSet["Chennai"] = "Banglore";
	dataSet["Bombay"] = "Delhi";
	dataSet["Goa"] = "Chennai";
	dataSet["Delhi"] = "Goa";

	printItinerary(dataSet);

	return 0;
}

/*
printItinerary() Function: This function takes a map<string, string> named dataSet as an argument. The map represents a travel itinerary where the keys are destinations and the values are the next destinations in the itinerary.

Reverse Map Creation: The code first creates a reversemap by reversing the dataSet. In the reversemap, the values of dataSet become keys, and the keys of dataSet become values. This map will be used to find the starting point of the itinerary.

Finding Starting Point: The code then iterates through the original dataSet to find the starting point of the itinerary. The starting point is the key that is not present in the reversemap.

Printing Itinerary: Once the starting point is determined, the code uses an iterator to traverse the itinerary. It starts at the starting point and keeps printing the current destination and its next destination. The next destination is obtained by looking up the current destination in the original dataSet.

The loop continues until there is no next destination to visit, which indicates the end of the itinerary.

*/

