/*
Write a C++ program for insert and search operations on Trie tree

Input: keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" }
       searchkey= the
Output: the --- Present in trie

Input: keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" }
       searchkey= these
Output: these --- Not present in trie

Input: keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" }
       searchkey= their
Output: their --- Present in trie


*/

#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}


int main()
{
	// Input keys (use only 'a' through 'z' and lower case)
	string keys[] = {"the", "a", "there",
					"answer", "any", "by",
					"bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct TrieNode *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	// Search for different keys
	char output[][32] = {"Not present in trie", "Present in trie"};

	// Search for different keys
	cout<<"the"<<" --- "<<output[search(root, "the")]<<endl;
	cout<<"these"<<" --- "<<output[search(root, "these")]<<endl;
	cout<<"their"<<" --- "<<output[search(root, "their")]<<endl;
	cout<<"thaw"<<" --- "<<output[search(root, "thaw")]<<endl;
	return 0;
}

/*
Alphabet Size: The constant ALPHABET_SIZE is defined as 26, assuming lowercase English alphabet characters.

Trie Node Structure: The TrieNode struct represents a node in the Trie. It contains an array of pointers to child nodes, each corresponding to a letter in the alphabet, and a boolean flag isEndOfWord to indicate if a word ends at that node.

Creating a New Trie Node: The getNode() function creates a new Trie node and initializes its members. It returns a pointer to the newly created node.

Insert Function: The insert function inserts a given key (string) into the Trie. It starts at the root and iterates through each character of the key. For each character, if the corresponding child node doesn't exist, a new node is created and linked. The last node in the path is marked as the end of a word.

Search Function: The search function checks whether a given key is present in the Trie. It follows a similar process as the insertion, traversing the Trie based on characters of the key. If the traversal reaches a null child pointer before the key is fully traversed, the key is not present. Otherwise, the function returns true if the last node is marked as the end of a word.

*/

