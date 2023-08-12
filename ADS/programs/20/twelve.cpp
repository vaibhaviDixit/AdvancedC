/*
Given a robot cleaner and a room represented by a 2D matrix, clean all the accessible cells.

Input:
{0, 1, 0, 0, 0},
{0, 0, 0, 1, 0},
{0, 0, 1, 1, 1},
{0, 0, 0, 1, 0},
{0, 0, 0, 0, 0}

Output:
Cleaning cell at (0, 0)
Cleaning cell at (1, 0)
Cleaning cell at (2, 0)
Cleaning cell at (3, 0)
Cleaning cell at (4, 0)
Cleaning cell at (4, 1)
Cleaning cell at (3, 1)
Cleaning cell at (2, 1)
Cleaning cell at (1, 1)
Cleaning cell at (1, 2)
Cleaning cell at (0, 2)
Cleaning cell at (0, 3)
Cleaning cell at (0, 4)
Cleaning cell at (1, 4)
Cleaning cell at (3, 2)
Cleaning cell at (4, 2)
Cleaning cell at (4, 3)
Cleaning cell at (4, 4)
Cleaning cell at (3, 4)

*/

#include <iostream>
#include <vector>

// Helper function to clean a cell (represented by (row, col)) in the room
void cleanCell(int row, int col) {
    // Your robot cleaner logic to clean the cell goes here
    std::cout << "Cleaning cell at (" << row << ", " << col << ")" << std::endl;
}

// Function to recursively clean all accessible cells in the room
void cleanRoomRecursive(std::vector<std::vector<int>>& room, int row, int col) {
    // Base case: If the current cell is inaccessible or has already been cleaned, return
    if (row < 0 || row >= room.size() || col < 0 || col >= room[0].size() || room[row][col] == 1) {
        return;
    }

    // Mark the current cell as cleaned
    room[row][col] = 1;

    // Clean the current cell
    cleanCell(row, col);

    // Recur for adjacent cells (up, down, left, right) to continue cleaning the room
    cleanRoomRecursive(room, row - 1, col); // up
    cleanRoomRecursive(room, row + 1, col); // down
    cleanRoomRecursive(room, row, col - 1); // left
    cleanRoomRecursive(room, row, col + 1); // right
}

// Function to clean the entire room
void cleanRoom(std::vector<std::vector<int>>& room) {
    // Assuming the starting position of the robot is (0, 0)
    int startRow = 0;
    int startCol = 0;

    // Clean the room recursively starting from the robot's position
    cleanRoomRecursive(room, startRow, startCol);
}

int main() {
    // Example room represented by a 2D matrix
    std::vector<std::vector<int>> room = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Clean the entire room starting from the robot's position
    cleanRoom(room);

    return 0;
}

/*
The program uses a 2D matrix (room) to represent the given room. The matrix is of size MxN, where M is the number of rows and N is the number of columns.
The function cleanCell is a helper function that represents the action of the robot cleaner to clean a particular cell (row, col) in the room.
The function cleanRoomRecursive is a recursive function that starts from a given cell (row, col) and cleans all the accessible cells in the room. It uses depth-first search (DFS) to traverse through the accessible cells, marking them as cleaned along the way.
The function cleanRoom serves as the main entry point to the cleaning process. It assumes that the robot starts from the position (0, 0) in the room and calls cleanRoomRecursive to clean the entire room.
The main function creates an example room represented by a 2D matrix and calls the cleanRoom function to clean the entire room starting from the robot's position (0, 0). The cleaning process is then printed to the console using the cleanCell function.

*/


