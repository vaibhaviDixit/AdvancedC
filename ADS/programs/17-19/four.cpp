/*
Given a set of candidate numbers and a target value, find all unique combinations of candidates where the chosen numbers sum to the target.

Input:Combinations that sum up to 7:
Output:
2 2 3
7


*/

// Code for Combination Sum

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target < 0)
        return;

    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        current.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], i, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;

    findCombinations(candidates, target, 0, current, result);

    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations that sum up to " << target << ":\n";
    for (const vector<int>& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
The Combination Sum program finds all unique combinations of a set of candidate numbers that sum up to a target value.
It uses a recursive backtracking approach to explore all possible combinations of candidates. The findCombinations function is called
recursively, considering each candidate and updating the target value accordingly. When the target becomes zero, it means a valid combination
is found, and it is added to the result vector. The combinationSum function sorts the candidates initially and calls the recursive function
with the appropriate parameters to start the search.

*/


