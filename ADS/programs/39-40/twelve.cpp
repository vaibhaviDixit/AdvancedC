/*
Given an array representation of min Heap, convert it to max Heap.

Input: arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9}
Output: arr[] = {20, 18, 10, 12, 9, 9, 3, 5, 6, 8}

*/


#include <bits/stdc++.h>
using namespace std;

// to heapify a subtree with root at given index
void MaxHeapify(int arr[], int i, int N)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	if (l < N && arr[l] > arr[i])
		largest = l;
	if (r < N && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		MaxHeapify(arr, largest, N);
	}
}

// This function basically builds max heap
void convertMaxHeap(int arr[], int N)
{
	// Start from bottommost and rightmost internal node and heapify all internal nodes in bottom up way
	for (int i = (N - 2) / 2; i >= 0; --i)
		MaxHeapify(arr, i, N);
}

// A utility function to print a given array of given size
void printArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
}

int main()
{
	// array representing Min Heap
	int arr[] = { 3, 5, 9, 6, 8, 20, 10, 12, 18, 9 };
	int N = sizeof(arr) / sizeof(arr[0]);

	printf("Min Heap array : ");
	printArray(arr, N);

	// Function call
	convertMaxHeap(arr, N);

	printf("\nMax Heap array : ");
	printArray(arr, N);

	return 0;
}

/*
This C++ program demonstrates the conversion of a min-heap into a max-heap. A min-heap is a binary tree where the parent node has a value less than or equal to the values of its children, and a max-heap is a binary tree where the parent node has a value greater than or equal to the values of its children.

The program starts with an array representing a min-heap and performs the conversion by swapping nodes while maintaining the max-heap property. It uses the MaxHeapify function to ensure that the subtree rooted at a given index follows the max-heap property. The convertMaxHeap function is used to build the max-heap from the given min-heap array.

After the conversion, the program prints the original min-heap array and the resulting max-heap array.

The output of the program showcases the transformation of the input min-heap array into a valid max-heap array.

*/

