/*
Given a dictionary, and two words ‘start’ and ‘target’ (both of same length). Find length of the smallest chain from ‘start’ to ‘target’ if it exists, such that adjacent words in the chain only differ by one character and each word in the chain is a valid word i.e., it exists in the dictionary. It may be assumed that the ‘target’ word exists in dictionary and length of all dictionary words is same.

Input: Dictionary = {POON, PLEE, SAME, POIE, PLEA, PLIE, POIN}, start = TOON, target = PLEA
Output: 7

Input: Dictionary = {ABCD, EBAD, EBCD, XYZA}, start = ABCV, target = EBAD
Output: 4

*/

// C++ program to find length of the shortest chain transformation from source to target
#include <bits/stdc++.h>
using namespace std;

// Returns length of shortest chain to reach 'target' from 'start'
// using minimum number of adjacent moves. D is dictionary
int shortestChainLen(
string start, string target,
set<string>& D)
{

	if(start == target)
	return 0;

	// If the target string is not present in the dictionary
	if (D.find(target) == D.end())
		return 0;

	// To store the current chain length and the length of the words
	int level = 0, wordlength = start.size();

	// Push the starting word into the queue
	queue<string> Q;
	Q.push(start);

	// While the queue is non-empty
	while (!Q.empty()) {

		// Increment the chain length
		++level;

		// Current size of the queue
		int sizeofQ = Q.size();

		// Since the queue is being updated while it is being traversed so only the
		// elements which were already present in the queue before the start of this loop will be traversed for now
		for (int i = 0; i < sizeofQ; ++i) {

			// Remove the first word from the queue
			string word = Q.front();
			Q.pop();

			// For every character of the word
			for (int pos = 0; pos < wordlength; ++pos) {

				// Retain the original character
				// at the current position
				char orig_char = word[pos];

				// Replace the current character with
				// every possible lowercase alphabet
				for (char c = 'a'; c <= 'z'; ++c) {
					word[pos] = c;

					// If the new word is equal
					// to the target word
					if (word == target)
						return level + 1;

					// Remove the word from the set
					// if it is found in it
					if (D.find(word) == D.end())
						continue;
					D.erase(word);

					// And push the newly generated word
					// which will be a part of the chain
					Q.push(word);
				}

				// Restore the original character
				// at the current position
				word[pos] = orig_char;
			}
		}
	}

	return 0;
}

int main()
{
	// make dictionary
	set<string> D;
	D.insert("poon");
	D.insert("plee");
	D.insert("same");
	D.insert("poie");
	D.insert("plie");
	D.insert("poin");
	D.insert("plea");
	string start = "toon";
	string target = "plea";
	cout << "Length of shortest chain is: "
		<< shortestChainLen(start, target, D);
	return 0;
}

/*

The shortestChainLen function calculates the length of the shortest chain transformation:

The function takes the source word (start), target word (target), and a set of valid words (D) as inputs.
If the source word is the same as the target word, the transformation length is 0 (no transformation needed).
If the target word is not present in the dictionary, the transformation is not possible, so it returns 0.
A queue (Q) is used to store words for BFS traversal.
The BFS loop iterates until the queue is empty.
Inside the loop, the function:
Increments the chain length (level).
Retrieves the size of the queue (sizeofQ) to only process the words that were in the queue before the loop started.
For each word in the queue:
Iterates through each character of the word.
Replaces the character with each lowercase alphabet to generate new words.
If a newly generated word matches the target word, the chain length + 1 is returned.
If the newly generated word is not in the dictionary, it's skipped.
Otherwise, the newly generated word is removed from the dictionary, and it's pushed into the queue for further traversal.
If no transformation sequence is found, the function returns 0.
The main function:

Creates a dictionary of valid words (D) using a set data structure.
Specifies the source and target words (start and target).
Calls the shortestChainLen function to calculate and print the length of the shortest transformation sequence.

*/




