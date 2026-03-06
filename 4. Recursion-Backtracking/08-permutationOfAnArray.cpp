// Permutation of an array/string
// a permutation is a rearrangment of elements in all possible orders
// for array [1, 2, 3], the permutations are: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]
// for a string like "abc", its similar: "abc", "bac", "bca", "cab", "cba"
// why use backtracking -> we explore all positions
//                         we try placing each unused number character
//                         we undo (backtrack) to swap back after each recursive call

#include <bits/stdc++.h>
using namespace std;

// approach -> use recursion + backtracking
// at each index swap every number that hasn't been fixed yet
// recurse to the next inndex
// after recursion, swap backk to undo (backtrack)
void permutation(int index, vector<int> &nums, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);            // place ith element at current index
        permutation(index + 1, nums, result); // recurse for next index
        swap(nums[index], nums[i]);            // backtrack (undo swap)
    }
}
// time complexity -> O(n! * n)
// (O(n!)) -> number of permutations
// each permutation takes O(n) time to copy
// time complexity is factorial because all possible arrangements are explored

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result;
    permutation(0, nums, result);
    cout << "[";
    for (int i = 0; i < result.size(); i++){
        cout << "[";
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if ( i != result.size() - 1)
            cout << ",\n";
    }
    cout << "]" << "\n";
    return 0;
}