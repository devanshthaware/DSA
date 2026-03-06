// Subsets II
// given an array nums that may contain duplicates
// return all possible unique subsets (the power set)
// if the innput has duplicate, we must avoid adding duplicate subsets
// example -> input: [1, 2, 2]
// native subsets -> [], [1], [2], [2], [1, 2], [1, 2], [2, 2], [1, 2, 2]
// notice duplicates
// expected unique -> [], [1], [2], [1, 2], [2, 2], [1, 2, 2]

#include <bits/stdc++.h>
using namespace std;

// approach -> setp 1 -> sort the array (so duplicates are next to each other)
// step 2 -> during recursion, skip duplicates at the same tree level
// specifically, if i > index && nums[i] == num[i - 1] -> skip to avoid repeating the same choice
// time complexity: O(2^n) -> maximum number of unique subsets (worst case, no duplicates)
// sorting -> O(nlogn)
// overall -> O(2^n * n) (because we copy subsets, each up to length n)
void backtrack(int index, vector<int> &nums, vector<int> &subset, vector<vector<int>> &result)
{
    result.push_back(subset);

    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;

        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset, result);
        subset.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 2, 2};
    sort(nums.begin(), nums.end());

    vector<int> subset;
    vector<vector<int>> result;

    backtrack(0, nums, subset, result);

    cout << "[";

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]\n";
    return 0;
}