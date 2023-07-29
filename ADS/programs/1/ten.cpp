/*
Given n non-negative integers height representing the heights of vertical lines, find two lines that together with the x-axis forms a
container that contains the most water.


Input: {1, 8, 6, 2, 5, 4, 8, 3, 7}
Output:Maximum water that can be contained: 49

Input: {1, 5, 4, 3}
Output: Maximum water that can be contained: 6

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int current_area = (right - left) * min(height[left], height[right]);
        max_area = max(max_area, current_area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_area;
}

int main() {
    vector<int> height = {1, 5, 4, 3};

    int max_water = maxArea(height);
    cout << "Maximum water that can be contained: " << max_water << endl;

    return 0;
}

/*
 This program finds the two lines in an array of heights that, when combined with the x-axis, form a container with the maximum amount of water.
 It uses two pointers, left and right, initially pointing to the first and last elements of the array, respectively. While left is less than
 right, the program calculates the current water container's area and keeps track of the maximum area seen so far. The area is calculated by
 taking the width (difference between right and left) and the minimum of the heights at those indices. The pointer that points to the shorter
 height is moved inward towards the center, as moving the taller pointer wouldn't increase the container's area. The solution has a time
 complexity of O(n) as both pointers move towards each other and each element is visited once.

*/
