/*
Given a string of length n of lowercase alphabet characters, we need to count total number of distinct substrings of this string.

Input  : str = “ababa”
Output : 10

*/

// A C++ program to find the count of distinct substring of a string using trie data structure
#include <bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;

// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
public:
	SuffixTrieNode *children[MAX_CHAR];
	SuffixTrieNode() // Constructor
	{
		// Initialize all child pointers as NULL
		for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	}

	// A recursive function to insert a suffix of the s in subtree rooted with this node
	void insertSuffix(string suffix);
};

// A Trie of all suffixes
class SuffixTrie
{
	SuffixTrieNode *root;
	int _countNodesInTrie(SuffixTrieNode *);
public:
	// Constructor (Builds a trie of suffies of the given text)
	SuffixTrie(string s)
	{
		root = new SuffixTrieNode();

		// Consider all suffixes of given string and insert them into the Suffix Trie using recursive function
		// insertSuffix() in SuffixTrieNode class
		for (int i = 0; i < s.length(); i++)
			root->insertSuffix(s.substr(i));
	}

	// method to count total nodes in suffix trie
	int countNodesInTrie() { return _countNodesInTrie(root); }
};

// A recursive function to insert a suffix of the s in subtree rooted with this node
void SuffixTrieNode::insertSuffix(string s)
{
	// If string has more characters
	if (s.length() > 0)
	{
		// Find the first character and convert it into 0-25 range.
		char cIndex = s.at(0) - 'a';

		// If there is no edge for this character, add a new edge
		if (children[cIndex] == NULL)
			children[cIndex] = new SuffixTrieNode();

		// Recur for next suffix
		children[cIndex]->insertSuffix(s.substr(1));
	}
}

// A recursive function to count nodes in trie
int SuffixTrie::_countNodesInTrie(SuffixTrieNode* node)
{
	// If all characters of pattern have been processed,
	if (node == NULL)
		return 0;

	int count = 0;
	for (int i = 0; i < MAX_CHAR; i++)
	{
		// if children is not NULL then find count of all nodes in this subtrie
		if (node->children[i] != NULL)
			count += _countNodesInTrie(node->children[i]);
	}

	// return count of nodes of subtrie and plus 1 because of node's own count
	return (1 + count);
}

// Returns count of distinct substrings of str
int countDistinctSubstring(string str)
{
	// Construct a Trie of all suffixes
	SuffixTrie sTrie(str);

	// Return count of nodes in Trie of Suffixes
	return sTrie.countNodesInTrie();
}

int main()
{
	string str = "ababa";
	cout << "Count of distinct substrings is "
		<< countDistinctSubstring(str);
	return 0;
}

/*
SuffixTrieNode Class: This class represents a node in the Suffix Trie. It has an array of pointers to child nodes for each character ('a' to 'z'). The constructor initializes all child pointers as NULL.

Insert Suffix Function: The insertSuffix function recursively inserts a suffix of a string into the Suffix Trie. It traverses the Trie nodes according to the characters of the suffix, creating new nodes as necessary.

SuffixTrie Class: This class constructs a Suffix Trie of all the suffixes of a given string. It utilizes the insertSuffix function in the SuffixTrieNode class to build the Trie.

Count Nodes in Trie Function: The _countNodesInTrie function recursively counts the total number of nodes in the Suffix Trie by traversing all child nodes of a given node.

Count Distinct Substrings Function: The countDistinctSubstring function constructs a Suffix Trie using the input string and then returns the count of nodes in the Trie. Each node in the Suffix Trie corresponds to a distinct substring.

Main Function: In the main function:

A string is defined.
The countDistinctSubstring function is used to find the count of distinct substrings of the string.
The result is printed.

*/


