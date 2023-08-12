/*
Implement a C++ program for Heap Sort, a comparison-based sorting algorithm that utilizes a binary heap data structure to arrange
elements in ascending order.

Input: arr={ 60 ,20 ,40 ,70, 30, 10}
Output:
After heapifying array is
70 60 40 20 30 10
Sorted array is
10 20 30 40 60 70

*/

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root Since we are using 0 based indexing
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	int arr[] = { 60 ,20 ,40 ,70, 30, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	for(int i=n/2 -1;i>=0;i--){
	heapify(arr,n,i);
}

cout << "After heapifying array is \n";
	printArray(arr, n);


	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArray(arr, n);

return 0;
}

/*
Heap Sort is a sorting algorithm that utilizes the properties of a binary heap to efficiently arrange elements in ascending order. The heap is a complete binary tree where each node is greater than or equal to its children (in a max heap), or each node is less than or equal to its children (in a min heap).

The given C++ program implements the Heap Sort algorithm. Here's how the program works:

The heapify function is used to transform an array into a max heap. It takes an array, the size of the heap (n), and the index of the root node (i) as arguments. The function compares the root with its left and right children and swaps elements if necessary to maintain the heap property.

In the heapSort function, the initial heap is built by calling heapify for all non-leaf nodes in reverse order. This ensures that the array represents a valid max heap.

After building the heap, the heapSort function performs the actual sorting. It repeatedly extracts the maximum element from the root (which is always the largest element in a max heap) and places it at the end of the array. Then, it calls heapify to restore the heap property on the remaining heap.

The printArray function is a utility function to print the contents of an array.

The main function initializes an array and its size. It first calls heapify on the entire array to convert it into a max heap, and then prints the heapified array. After that, it invokes heapSort to sort the array in ascending order using the heap structure. Finally, it prints the sorted array.

The Heap Sort algorithm has a time complexity of O(n log n) for its worst-case, average-case, and best-case scenarios. It's a good choice when memory is not a constraint and stable sorting is not required.

*/
