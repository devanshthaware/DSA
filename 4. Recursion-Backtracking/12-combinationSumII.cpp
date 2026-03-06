// Combination sum II
// combination sum II is a backtracking problemm with duplicates
// It is very similar to Combination Sum I, but there are two important differences
// Given:
//  candidates (may contain duplicates)
//  target
// Return unique combinations where:
//  each number can be used only once
//  sum = target
// example -> Input: candidates = [10,1,2,7,6,1,5]
//                   target = 8
//            Output:
//                   [
//                      [1,1,6],
//                      [1,2,5],
//                      [1,7],
//                      [2,6]
//                   ]

#include <bits/stdc++.h>
using namespace std;

// approach - O(2^n)
// Sort the array
// Skip duplicates during iteration
// Use element only once
// Duplicate skipping condition:
//  if (i > index && candidates[i] == candidates[i-1])
//     continue;
// Why Sorting is Required
// Sorting groups duplicates:
//  Before sorting
//  [10,1,2,7,6,1,5]
//  After sorting
//  [1,1,2,5,6,7,10]
// Now duplicate combinations can be skipped easily.
// Backtracking Algorithm
// At each index:
//  Choose element
//  Reduce target
//  Move to next index
//  Backtrack
void solve(int index, vector<int> &candidates, int target,
           vector<int> &current, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        // skip duplicates
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        current.push_back(candidates[i]);
        solve(i + 1, candidates, target - candidates[i], current, result);
        current.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    solve(0, candidates, target, current, result);
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(nums, target);
    for (auto &v : ans)
    {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]\n";
    }
    return 0;
}