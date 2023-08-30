/*
Given a string, count all distinct substrings of the given string using trie tree.

Input : abcd
Output : Count of Distinct Substrings: 10

Input : aaa
Output : Count of Distinct Substrings: 3

*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	bool isWord;
	TrieNode* child[26];

	TrieNode()
	{
		isWord = 0;
		for (int i = 0; i < 26; i++) {
			child[i] = 0;
		}
	}
};

int countDistinctSubstring(string str)
{
	TrieNode* head = new TrieNode();

	// will hold the count of unique substrings
	int count = 0;
	// included count of substr " "

	for (int i = 0; i < str.length(); i++) {
		TrieNode* temp = head;

		for (int j = i; j < str.length(); j++) {
			// when char not present add it to the trie
			if (temp->child[str[j] - 'a'] == NULL) {
				temp->child[str[j] - 'a'] = new TrieNode();
				temp->isWord = 1;
				count++;
			}
			// move on to the next char
			temp = temp->child[str[j] - 'a'];
		}
	}

	return count;
}

int main()
{
	int count = countDistinctSubstring("abcd");

	cout << "Count of Distinct Substrings: " << count
		<< endl;

	return 0;
}

/*
TrieNode Class: This class represents a node in the Trie. It includes a boolean flag isWord to indicate whether the current node represents a valid word and an array of pointers to child nodes for each character ('a' to 'z'). The constructor initializes isWord as false and initializes all child pointers as NULL.

Count Distinct Substring Function: The countDistinctSubstring function takes a string as input and returns the count of distinct substrings. It utilizes a Trie to keep track of the encountered substrings.

Main Function: In the main function:

A string "aaabc" is used as an example input.
The countDistinctSubstring function is called to calculate the count of distinct substrings in the input string.
The result is printed.

*/

