/*
You are given an array of integers. Implement a program to find the kth smallest element in the array using a min-heap.

Input: arr = {10, 50, 40, 75, 60, 65, 45} ,k=5
Output: 60

*/

#include <bits/stdc++.h>
using namespace std;

// Structure for the heap
struct Heap {
	vector<int> v;
	int n; // Size of the heap

	Heap(int i = 0)
		: n(i)
	{
		v = vector<int>(n);
	}
};

// Generic function to
// swap two integers
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Returns the index of
// the parent node
inline int parent(int i)
{
	return (i - 1) / 2;
}

// Returns the index of
// the left child node
inline int left(int i)
{
	return 2 * i + 1;
}

// Returns the index of
// the right child node
inline int right(int i)
{
	return 2 * i + 2;
}

// Maintains the heap property
void heapify(Heap& h, int i)
{
	int l = left(i), r = right(i), m = i;
	if (l < h.n && h.v[i] > h.v[l])
		m = l;
	if (r < h.n && h.v[m] > h.v[r])
		m = r;
	if (m != i) {
		swap(h.v[m], h.v[i]);
		heapify(h, m);
	}
}

// Extracts the minimum element
int extractMin(Heap& h)
{
	if (!h.n)
		return -1;
	int m = h.v[0];
	h.v[0] = h.v[h.n-- - 1];
	heapify(h, 0);
	return m;
}

int findKthSmalles(Heap &h, int k)
{
	for (int i = 1; i < k; ++i)
		extractMin(h);
	return extractMin(h);
}

int main()
{
	Heap h(7);
	h.v = vector<int>{ 10, 50, 40, 75, 60, 65, 45 };
	int k = 5;
	cout << findKthSmalles(h, k);
	return 0;
}

/*
This program demonstrates finding the kth smallest element from an array using a heap-based approach.
The heap structure is implemented using the Heap struct, which includes a vector for the heap and the size of the heap.
The swap, parent, left, and right functions are utility functions for heap operations.
The heapify function is responsible for maintaining the heap property, and the extractMin function extracts the minimum element from the
heap while maintaining the heap property. The findKthSmallest function utilizes these operations to find the kth smallest element by
extracting k-1 elements and then returning the kth extracted element.
In the main function, a sample heap h is created, and the array is initialized with values. The value of k is set to 5, and the
program then prints the kth smallest element using the findKthSmallest function.
This program demonstrates how heap operations can be used to efficiently find the kth smallest element from an array, making it a
useful tool for interview problems that involve selecting kth order statistics from data.

*/


