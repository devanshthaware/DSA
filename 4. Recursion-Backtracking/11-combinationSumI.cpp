// Combination sum I
// combination sum is a classic backtracking/recursion problem that teaches how to explore all possible combinations
// given an array of distinct integers candidates
// an integer target
// return all unique combinations of candidates where:
// number can be used unlimited times
// the sum equals target
// example -> Input: candidates = [2,3,6,7]
//                   target = 7
//            Output:
//                   [
//                      [2,2,3],
//                      [7]
//                   ]
// Explanation:
// 2 + 2 + 3 = 7
// 7 = 7

#include <bits/stdc++.h>
using namespace std;

// approach -> This problem uses Backtracking (DFS on decision tree).
// At every step you decide:
//  Pick current number
//  OR
//  Skip current number
// But since repetition is allowed, when you pick a number you stay at the same index
// Backtracking Algorithm
// Steps:
//  Maintain a current combination
//  If target == 0
//      push combination to result
//  Iterate candidates from start
//  Choose candidate
//  Recurse with reduced target
//  Undo choice (backtrack)
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
        if (candidates[i] > target)
            break;
        current.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i], current, result);
        current.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    solve(0, candidates, target, current, result);
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}