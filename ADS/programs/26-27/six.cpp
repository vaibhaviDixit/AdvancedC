/*
Design a stack that supports getMin() in O(1) time and O(1) extra space

Input:  stack= 3 5 2 1
Output: Minimum Element in the stack is: 1
*/

#include <bits/stdc++.h>
using namespace std;

// A user-defined stack that supports getMin() in
// addition to push() and pop()
struct MyStack {
	stack<int> s; // Main stack to store elements
	int minEle;   // Variable to store the current minimum element

	// Prints the minimum element in MyStack
	void getMin() {
		if (s.empty())
			cout << "Stack is empty\n";
		else
			cout << "Minimum Element in the stack is: " << minEle << "\n";
	}

	// Prints the top element of MyStack
	void peek() {
		if (s.empty()) {
			cout << "Stack is empty ";
			return;
		}

		int t = s.top(); // Top element.

		cout << "Top Most Element is: ";

		// If t < minEle, it means minEle stores the value of t.
		(t < minEle) ? cout << minEle : cout << t;
	}

	// Removes the top element from MyStack
	void pop() {
		if (s.empty()) {
			cout << "Stack is empty\n";
			return;
		}

		cout << "Top Most Element Removed: ";
		int t = s.top();
		s.pop();

		// Minimum will change as the minimum element
		// of the stack is being removed.
		if (t < minEle) {
			cout << minEle << "\n";
			minEle = 2 * minEle - t;
		} else
			cout << t << "\n";
	}

	// Inserts an element into MyStack
	void push(int x) {
		// Insert the new number into the stack
		if (s.empty()) {
			minEle = x;
			s.push(x);
			cout << "Number Inserted: " << x << "\n";
			return;
		}

		// If the new number is less than minEle
		else if (x < minEle) {
			s.push(2 * x - minEle);
			minEle = x;
		} else
			s.push(x);

		cout << "Number Inserted: " << x << "\n";
	}
};


int main() {
	MyStack s;

	// Function calls
	s.push(3);
	s.push(5);
	s.getMin();
	s.push(2);
	s.push(1);
	s.getMin();
	s.pop();
	s.getMin();
	s.pop();
	s.peek();

	return 0;
}

/*
This program implements a special stack called MyStack that supports the operations push, pop, peek, and getMin in constant time complexity
and uses O(1) extra space for storing the minimum element. The key concept here is to use the minEle variable to track the minimum element and
use a transformation when pushing an element less than minEle. This transformation helps maintain the history of the minimum elements.
The getMin operation simply prints the current minimum element, and the peek operation prints the top element, considering the minimum element
condition

*/


