/*
The Tower of Hanoi puzzle is a classic mathematical problem that involves three pegs and a number of disks of different sizes. The objective of the puzzle is to move all the disks from the starting peg (source peg) to the destination peg, using the middle peg (auxiliary peg) as an intermediate, following these rules:

Only one disk can be moved at a time.
A larger disk cannot be placed on top of a smaller disk.
Your task is to implement a C++ program to solve the Tower of Hanoi puzzle using recursion.

Input: Enter the number of disks: 3
Output:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C

*/

#include <iostream>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

/*
void towerOfHanoi(int n, char source, char auxiliary, char destination): This is the recursive function definition to solve the Tower of Hanoi puzzle. The function takes four parameters:

n: The number of disks to be moved.
source: The peg (represented by a character) from which the disks are initially located.
auxiliary: The peg (represented by a character) used as an intermediate during the disk movements.
destination: The peg (represented by a character) where the disks should be moved.
if (n == 1): This is the base case of the recursion. When there's only one disk to move (i.e., n is 1), the function prints the move directly from the source peg to the destination peg and returns.

towerOfHanoi(n - 1, source, destination, auxiliary);: This line represents the recursive step. Before moving the nth disk from the source peg to the destination peg, the function first moves the n-1 disks from the source peg to the auxiliary peg using the destination peg as an intermediate.

std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;: After the recursive call (which has moved the n-1 disks to the auxiliary peg), this line prints the move of the nth disk from the source peg to the destination peg.

towerOfHanoi(n - 1, auxiliary, source, destination);: Finally, this line represents the second recursive call. After moving the nth disk to the destination peg, the function now moves the n-1 disks from the auxiliary peg to the destination peg using the source peg as an intermediate.

*/




