/*
You need to implement a program that inserts elements into a min heap and displays the heap after each insertion

Input: heap_elements={15, 10, 20, 8, 25, 13}
Output:
Inserted: 15, Heap: 15
Inserted: 10, Heap: 10 15
Inserted: 20, Heap: 10 15 20
Inserted: 8, Heap: 8 10 20 15
Inserted: 25, Heap: 8 10 20 15 25
Inserted: 13, Heap: 8 10 13 15 25 20

*/

#include <iostream>
#include <vector>

// Function to maintain the min heap property after inserting an element
void heapifyUp(std::vector<int>& heap, int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to insert an element into the min heap
void insertMinHeap(std::vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}

int main() {
    std::vector<int> minHeap;
    int elements[] = {50,30,80,60,70,10,20};

    for (int element : elements) {
        insertMinHeap(minHeap, element);
        std::cout << "Inserted: " << element << ", Heap: ";
        for (int value : minHeap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
This program demonstrates inserting elements into a min heap. The insertMinHeap function inserts elements while maintaining the min
heap property using the heapifyUp function. The main function inserts elements one by one and displays the heap after each insertion.

*/
