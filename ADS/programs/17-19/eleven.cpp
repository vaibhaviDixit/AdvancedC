/*
 Given a set of distinct integers, nums, return all possible subsets (the power set).

 Input: {1, 2, 3}

 Output:

 Subsets:
1
1 2
1 2 3
1 3
2
2 3
3

*/

// Code for Subsets

#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        generateSubsets(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    cout << "Subsets:\n";
    for (const vector<int>& subset : result) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
The Subsets program generates all possible subsets (the power set) of a given set of distinct integers.
It uses a backtracking recursion approach. The generateSubsets function generates subsets recursively by including or excluding each element at
a particular index. For each index, we add the current subset to the result and then explore all possible subsets by including the element at that
index and moving to the next index. After the recursive call, we remove the last element from the current subset to backtrack to the previous state.
The subsets function calls the generateSubsets function to generate all possible subsets.

*/

