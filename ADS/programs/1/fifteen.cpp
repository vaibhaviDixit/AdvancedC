/*
Given an array of integers representing trees in a row, where each tree produces a fruit, find the maximum number of fruits you can collect,
given that you can only collect fruits from two types of trees (tree types are represented by integers).

Input: tree = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}
Output: Maximum number of fruits you can collect: 5

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int totalFruit(vector<int>& tree) {
    int maxFruits = 0;
    unordered_map<int, int> fruitFrequency;

    int left = 0;
    for (int right = 0; right < tree.size(); right++) {
        fruitFrequency[tree[right]]++;

        // Shrink the window from the left if the number of distinct tree types exceeds 2
        while (fruitFrequency.size() > 2) {
            fruitFrequency[tree[left]]--;
            if (fruitFrequency[tree[left]] == 0) {
                fruitFrequency.erase(tree[left]);
            }
            left++;
        }

        maxFruits = max(maxFruits, right - left + 1);
    }

    return maxFruits;
}

int main() {
    vector<int> tree = {1,2,3,2,2};

    int result = totalFruit(tree);
    cout << "Maximum number of fruits you can collect: " << result << endl;

    return 0;
}

/*
In this problem, we use a sliding window to find the maximum number of fruits you can collect, given that you can only collect fruits from
two types of trees. We maintain two pointers left and right to expand the window to the right. The fruitFrequency map keeps track of the
frequency of fruit types in the current window. If the number of distinct fruit types exceeds 2, we shrink the window from the left until
the number of distinct fruit types becomes less than or equal to 2.
The maximum number of fruits you can collect is updated in the variable maxFruits.

*/



