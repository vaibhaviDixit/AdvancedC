/* Write a  C++ Program for Huffman Coding  using Priority Queue

Input: arr = { 'a', 'b', 'c', 'd', 'e', 'f' };
	  freq = { 5, 9, 45, 13, 16, 12 }
Output:
c 0
f 100
d 101
a 1100
b 1101
e 111

*/

#include <iostream>
#include <queue>
using namespace std;

// Maximum Height of Huffman Tree.
#define MAX_SIZE 100

class HuffmanTreeNode {
public:
	// Stores character
	char data;

	// Stores frequency of the character
	int freq;

	// Left child of the current node
	HuffmanTreeNode* left;

	// Right child of the current node
	HuffmanTreeNode* right;

	// Initializing the current node
	HuffmanTreeNode(char character,
					int frequency)
	{
		data = character;
		freq = frequency;
		left = right = NULL;
	}
};

// Custom comparator class
class Compare {
public:
	bool operator()(HuffmanTreeNode* a,
					HuffmanTreeNode* b)
	{
		// Defining priority on
		// the basis of frequency
		return a->freq > b->freq;
	}
};

// Function to generate Huffman Encoding Tree
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,
							vector<HuffmanTreeNode*>,
											Compare> pq)
{

	// We keep on looping till only one node remains in the Priority Queue
	while (pq.size() != 1) {

		// Node which has least
		// frequency
		HuffmanTreeNode* left = pq.top();

		// Remove node from Priority Queue
		pq.pop();

		// Node which has least frequency
		HuffmanTreeNode* right = pq.top();

		pq.pop();

		// A new node is formed
		// with frequency left->freq
		// + right->freq

		// We take data as '$' because we are only  concerned with the frequency
		HuffmanTreeNode* node = new HuffmanTreeNode('$',
								left->freq + right->freq);
		node->left = left;
		node->right = right;
		pq.push(node);
	}

	return pq.top();
}

// Function to print the
// huffman code for each
// character.

// It uses arr to store the codes
void printCodes(HuffmanTreeNode* root,
				int arr[], int top)
{
	// Assign 0 to the left node
	// and recur
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left,
				arr, top + 1);
	}

	// Assign 1 to the right
	// node and recur
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	// If this is a leaf node,
	// then we print root->data

	// We also print the code
	// for this character from arr
	if (!root->left && !root->right) {
		cout << root->data << " ";
		for (int i = 0; i < top; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
}

void HuffmanCodes(char data[],
				int freq[], int size)
{

	// Declaring priority queue
	// using custom comparator
	priority_queue<HuffmanTreeNode*,
				vector<HuffmanTreeNode*>,
				Compare>
		pq;

	// Populating the priority
	// queue
	for (int i = 0; i < size; i++) {
		HuffmanTreeNode* newNode
			= new HuffmanTreeNode(data[i], freq[i]);
		pq.push(newNode);
	}

	// Generate Huffman Encoding Tree and get the root node
	HuffmanTreeNode* root = generateTree(pq);

	// Print Huffman Codes
	int arr[MAX_SIZE], top = 0;
	printCodes(root, arr, top);
}


int main()
{
	char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 45, 13, 16, 12 };
	int size = sizeof(data) / sizeof(data[0]);

	HuffmanCodes(data, freq, size);
	return 0;
}

/*
This C++ program demonstrates the Huffman coding algorithm, which is a lossless data compression technique that assigns shorter codes to more frequent characters and longer codes to less frequent characters.

Here's a breakdown of the program:

The HuffmanTreeNode class represents a node in the Huffman tree. Each node has a character (data), frequency (freq), and pointers to its left and right children (left and right).

The Compare class is a custom comparator used to define the priority queue's order. The nodes with lower frequency values are assigned higher priority.

The generateTree function constructs the Huffman tree. It uses a priority queue to repeatedly merge nodes with the lowest frequencies until only one node remains, which becomes the root of the Huffman tree.

The printCodes function recursively traverses the Huffman tree and prints the characters along with their corresponding Huffman codes.

The HuffmanCodes function takes an array of characters, their frequencies, and the size of the arrays. It populates a priority queue with nodes created from the characters and frequencies, then generates the Huffman tree and prints the Huffman codes.

In the main function, sample characters and their frequencies are provided. The HuffmanCodes function is called to demonstrate the generation of Huffman codes and their associated characters.

The program begins with an array of characters (data[]) and their respective frequencies (freq[]). It uses a priority queue to build the Huffman tree. After constructing the tree, it prints the characters and their corresponding Huffman codes.

*/
