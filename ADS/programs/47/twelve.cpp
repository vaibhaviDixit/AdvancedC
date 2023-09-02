/*
In operating systems, whenever a new page is referred and not present in memory, page fault occurs and Operating System replaces one of the existing pages
with newly needed page. Different page replacement algorithms suggest different ways to decide which page to replace. The target for all algorithms is to
reduce number of page faults. In this algorithm, OS replaces the page that will not be used for the longest period of time in future.

Input : Number of frames, fn = 3
        Reference String, pg[] = {7, 0, 1, 2,
               0, 3, 0, 4, 2, 3, 0, 3, 2, 1,
               2, 0, 1, 7, 0, 1};
Output : No. of hits = 11
         No. of misses = 9

Input : Number of frames, fn = 4
        Reference String, pg[] = {7, 0, 1, 2,
                  0, 3, 0, 4, 2, 3, 0, 3, 2};
Output : No. of hits = 7
         No. of misses = 6

*/


// CPP program to demonstrate optimal page replacement algorithm.
#include <bits/stdc++.h>
using namespace std;

// Function to check whether a page exists in a frame or not
bool search(int key, vector<int>& fr)
{
	for (int i = 0; i < fr.size(); i++)
		if (fr[i] == key)
			return true;
	return false;
}

// Function to find the frame that will not be used recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int>& fr, int pn, int index)
{
	// Store the index of pages which are going to be used recently in future
	int res = -1, farthest = index;
	for (int i = 0; i < fr.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (fr[i] == pg[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		// If a page is never referenced in future, return it.
		if (j == pn)
			return i;
	}

	// If all of the frames were not in future, return any of them, we return 0. Otherwise we return res.
	return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
	// Create an array for given number of frames and initialize it as empty.
	vector<int> fr;

	// Traverse through page reference array and check for miss and hit.
	int hit = 0;
	for (int i = 0; i < pn; i++) {

		// Page found in a frame : HIT
		if (search(pg[i], fr)) {
			hit++;
			continue;
		}

		// Page not found in a frame : MISS

		// If there is space available in frames.
		if (fr.size() < fn)
			fr.push_back(pg[i]);

		// Find the page to be replaced.
		else {
			int j = predict(pg, fr, pn, i + 1);
			fr[j] = pg[i];
		}
	}
	cout << "No. of hits = " << hit << endl;
	cout << "No. of misses = " << pn - hit << endl;
}

int main()
{
	int pg[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
	int pn = sizeof(pg) / sizeof(pg[0]);
	int fn = 4;
	optimalPage(pg, pn, fn);
	return 0;
}

/*
The search function checks whether a given page exists in a frame or not. It takes a page number key and a vector of frames fr as input and returns true if the page is found in any frame, otherwise false.

The predict function finds the frame that will not be used recently in the future after a given index in the page reference array pg. It takes the page reference array pg, a vector of frames fr, the total number of pages pn, and the current index index as input.

It initializes res to -1, which will store the index of the frame that will be replaced.
It initializes farthest to the current index.
It then checks each frame in fr and searches for the page in the pg array starting from the current index index. It keeps track of the farthest occurrence of each page in the farthest variable.
If a page is never referenced in the future (j == pn), it returns the index of that frame.
If all frames have a reference in the future, it returns the frame that will be used farthest in the future.
The optimalPage function simulates the Optimal Page Replacement algorithm. It takes the page reference array pg, the total number of pages pn, and the number of available frames fn as input.

It initializes an empty vector fr to represent the frames.
It iterates through the page reference array and checks whether each page is in the frame (search function).
If the page is found in a frame, it's considered a hit, and the hit counter is incremented.
If the page is not found in any frame (miss), it checks whether there is space available in the frames. If there is space, it adds the page to the frames.
If there is no space available in the frames, it calls the predict function to find the page to be replaced (j = predict(pg, fr, pn, i + 1)) and replaces it with the current page.
In the main function, sample data is provided:

An array pg represents the page reference sequence.
The total number of pages pn is calculated based on the size of the pg array.
The number of available frames fn is set to 4.
The optimalPage function is called with these parameters to simulate the Optimal Page Replacement algorithm.
The program prints the number of hits and misses.

*/

