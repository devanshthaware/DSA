// Two sum
// given an array of integers nums[] and an integer target, return the indices of the two numbers suct that they add up to target
// example --> input: nums = [2, 7, 11, 15], target = 9
//             output: [0, 1] because nums[0] + nums[1] = 2 + 7 = 9

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// try every possible pair of element in the array
// for every each pair, check if their sum equals the target
pair<int, int> twoSumBrute(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<pair<int, int>> ans;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        for (size_t j = i + 1; j < n; j++)
        {
            /* code */
            if (nums[i] + nums[j] == target)
            {
                /* code */
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// better approach (sorted two pointer) - n(nlogn) due to sorting
// sort the array (if order doesn't matter)
// use two pointers: one at start, one at end
// if the sum is too small -> move the left pointer
// if the ssum is too big -> move the right pointer
pair<int, int> twoSumBetter(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        /* code */
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            /* code */
            return {left, right};
        }
        else if (sum < target)
        {
            /* code */
            left++;
        }
        else
        {
            /* code */
            right--;
        }
    }
    return {-1, -1};
}

// optimal approach (using hash map) - O(n)
// create a map to store value -> index
// for each number x, compute target y (this is the number we want)
// if that number is already in the map. you've found the pair
// why? -> because if x + y = target and you already saw y, just return indices
pair<int, int> twoSumOptimal (vector<int>& nums, int target){
    unordered_map<int, int> mp;
    for (size_t i = 0; i < nums.size(); i++)
    {
        /* code */
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end())
        {
            /* code */
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
        }
        return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {2, 7, 11, 15};
    pair<int, int> ansBrute = twoSumBrute(nums, 9);
    cout << "Two sum (brute): " << ansBrute.first << ", " << ansBrute.second << "\n";
    pair<int, int> ansBetter = twoSumBetter(nums, 9);
    cout << "Two sum (better): " << ansBetter.first << ", " << ansBetter.second << "\n";
    pair<int, int> ansOptimal = twoSumOptimal(nums, 9);
    cout << "Two sum (optimal): " << ansOptimal.first << ", " << ansOptimal.second;
    return 0;
}