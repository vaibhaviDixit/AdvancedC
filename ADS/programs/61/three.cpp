/*
Given a set of strings, find the longest common prefix.

Input  : {"apple", "ape", "april"}
Output : "ap"

Input: {"zee", "zebra","zomato", "zen"}
Output : "z"

*/

// A Program to find the longest common prefix of the given words

#include<bits/stdc++.h>
using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isLeaf is true if the node represents end of a word
	bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	if (pNode)
	{
		int i;

		pNode->isLeaf = false;

		for (i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}

	return pNode;
}

// If not present, inserts the key into the trie
// If the key is a prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key)
{
	int length = key.length();
	int index;

	struct TrieNode *pCrawl = root;

	for (int level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isLeaf = true;
}

// Counts and returns the number of children of the current node
int countChildren(struct TrieNode *node, int *index)
{
	int count = 0;
	for (int i=0; i<ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)
		{
			count++;
			*index = i;
		}
	}
	return (count);
}

// Perform a walk on the trie and return the longest common prefix string
string walkTrie(struct TrieNode *root)
{
	struct TrieNode *pCrawl = root;
	int index;
	string prefix;

	while (countChildren(pCrawl, &index) == 1 &&
			pCrawl->isLeaf == false)
	{
		pCrawl = pCrawl->children[index];
		prefix.push_back('a'+index);
	}
	return (prefix);
}

// A Function to construct trie
void constructTrie(string arr[], int n, struct TrieNode *root)
{
	for (int i = 0; i < n; i++)
		insert (root, arr[i]);
	return;
}

// A Function that returns the longest common prefix from the array of strings
string commonPrefix(string arr[], int n)
{
	struct TrieNode *root = getNode();
	constructTrie(arr, n, root);

	// Perform a walk on the trie
	return walkTrie(root);
}

int main()
{
	string arr[] = {"mango", "pizza",
					"chole", "rabdi"};
	int n = sizeof (arr) / sizeof (arr[0]);

	string ans = commonPrefix(arr, n);

	if (ans.length())
		cout << "The longest common prefix is "
			<< ans;
	else
		cout << "There is no common prefix";
	return (0);
}

/*
TrieNode Structure: This structure defines a node in the Trie. It includes an array of pointers to child nodes and a boolean flag to indicate if it's a leaf node (end of a word).

Creating a New Trie Node: The getNode() function creates a new Trie node and initializes its members. Each child is initially set to NULL.

Insert Function: The insert function inserts a word into the Trie character by character, following the same pattern as previous examples.

Count Children Function: The countChildren function counts the number of children a given node has and returns that count. It also updates the index variable to hold the index of the first non-NULL child.

Walk Trie Function: The walkTrie function takes a Trie node as input and performs a walk on the Trie. It continues walking down the Trie until it reaches a node with either more than one child or a leaf node.

Construct Trie Function: The constructTrie function constructs the Trie by inserting an array of words into it.

Common Prefix Function: The commonPrefix function constructs the Trie using the input array of words and then uses the walkTrie function to find and return the longest common prefix.

Main Function: In the main function:

An array of strings is defined.
The commonPrefix function is used to find the longest common prefix among the strings.
The result is printed.

*/


