/*
Given an array of integers. The task is to find the maximum subarray XOR value in the given array.

Input: arr[] = {1, 2, 3, 4}
Output: 7
Explanation: The subarray {3, 4} has maximum XOR value

Input: arr[] = {8, 1, 2, 12, 7, 6}
Output: 15
Explanation: The subarray {1, 2, 12} has maximum XOR value

Input: arr[] = {4, 6}
Output: 6
Explanation: The subarray {6} has maximum XOR value

*/

// C++ program for a Trie based O(n) solution to find max subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
	int value; // Only used in leaf nodes
	TrieNode *arr[2];
};

// Utility function to create a Trie node
TrieNode *newNode()
{
	TrieNode *temp = new TrieNode;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;

	// Start from the msb, insert all bits of pre_xor into Trie
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1<<i);

		// Create a new node if needed
		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	// Store value at leaf node
	temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in prefix XOR 'pre_xor' and returns the XOR of this maximum with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		// Find current bit in given prefix
		bool val = pre_xor & (1<<i);

		// Traverse Trie, first look for a prefix that has opposite bit
		if (temp->arr[1-val]!=NULL)
			temp = temp->arr[1-val];

		// If there is no prefix with opposite bit, then look for same bit.
		else if (temp->arr[val] != NULL)
			temp = temp->arr[val];
	}
	return pre_xor^(temp->value);
}

// Returns maximum XOR value of a subarray in arr[0..n-1]
int maxSubarrayXOR(int arr[], int n)
{
	// Create a Trie and insert 0 into it
	TrieNode *root = newNode();
	insert(root, 0);

	// Initialize answer and xor of current prefix
	int result = INT_MIN, pre_xor =0;

	// Traverse all input array element
	for (int i=0; i<n; i++)
	{
		// update current prefix xor and insert it into Trie
		pre_xor = pre_xor^arr[i];
		insert(root, pre_xor);

		// Query for current prefix xor in Trie and update
		// result if required
		result = max(result, query(root, pre_xor));
	}
	return result;
}

int main()
{
	int arr[] = {8, 1, 2, 12};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Max subarray XOR is " << maxSubarrayXOR(arr, n);
	return 0;
}

/*
It defines a constant INT_SIZE with a value of 32, which represents the assumed size of an integer (number of bits).

The program defines a structure TrieNode to represent nodes in the Trie. Each node has the following attributes:

value: An integer value, which is only used in leaf nodes to store the XOR value.
arr[2]: An array of two pointers to TrieNode, representing the two possible branches of the Trie (0 and 1).
It defines a utility function newNode() that creates and initializes a new Trie node. The value is set to 0, and both branches are set to NULL.

The insert function inserts a given pre_xor value into the Trie with the provided root. It works as follows:

It starts from the most significant bit (MSB) and iterates through all bits of pre_xor.
For each bit, it checks if the corresponding branch in the Trie exists. If not, it creates a new node for that branch.
It then moves to the next level of the Trie based on the bit value (0 or 1).
Finally, it stores the pre_xor value in the leaf node.
The query function finds the maximum XOR value ending with the last number in the prefix XOR pre_xor and returns the XOR of this maximum with pre_xor. It does this by traversing the Trie as follows:

It starts from the MSB and iterates through all bits of pre_xor.
For each bit, it checks if there is a prefix in the Trie that has the opposite bit value (i.e., if the current bit is 1, it looks for a prefix with a 0 bit at that position).
If such a prefix exists, it moves to that branch.
If there is no prefix with the opposite bit, it moves to the branch with the same bit value.
Finally, it returns the XOR of pre_xor with the value stored in the leaf node.
The maxSubarrayXOR function finds the maximum XOR value of a subarray in the given array of integers. It follows these steps:

It creates a Trie and inserts 0 into it initially.
It initializes result to the minimum possible integer value (INT_MIN) and pre_xor to 0.
It iterates through the input array elements and updates the pre_xor by XORing it with the current array element.
It inserts the updated pre_xor into the Trie.
It queries the Trie for the current pre_xor and updates the result with the maximum value.

*/


