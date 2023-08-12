/*
Given a collection of candidate numbers and a target value, find all unique combinations in the candidates where the chosen numbers sum to
the target. Each number in candidates may only be used once.

Input:
candidates = {10, 1, 2, 7, 6, 1, 5}
target = 8

Output:
Combinations that sum up to 8:
1 1 6
1 2 5
1 7
2 6

*/

// Code for Combination Sum II

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
        if (i > start && candidates[i] == candidates[i - 1])
            continue; // Skip duplicates

        current.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;

    findCombinations(candidates, target, 0, current, result);

    return result;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = combinationSum2(candidates, target);

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
The Combination Sum II program is similar to the previous Combination Sum program, but here, each number in candidates may only be used once
in a combination. The findCombinations function has a small modification to handle duplicates. We skip over duplicates by checking if the
current candidate is the same as the previous candidate. If it is, we skip that candidate to avoid generating duplicate combinations.
This ensures that the result contains unique combinations.

*/

