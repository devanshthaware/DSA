// Four sum
// given an array of integers nums and a target value target, find all unique quadruplets [a, b, c, d] such that: a + b + c + d = target
// each quadruplet should be unique, meaning no duplicate sets in the result.
// example --> input: nums = [1, 0, -1, 0, -2, 2], target = 0
//             output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^4)
// check all quadruplets with 4 nested loops
// works for tiny arrays only
vector<vector<int>> fourSumBrute(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                for (int l = k + 1; l < n; ++l)
                {
                    if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
                    {
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(quad);
                    }
                }
            }
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end()); // --> remove duplicates
    return res;
}

// better approach - O(n^4)
// use sorting + two pointers to reduce one loop 
// skip duplicates while iterating
vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // --> skip duplicates
            continue; 
        for (int j = i + 1; j < n - 2; ++j)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) // --> skip duplicates
                continue; 

            int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return res;
}

// optimal - O(n^2) average with hashing (when array is large)
// reduce one layer of looping by using a hash map of pairs sums:
// store all pair sums in a map<long long, vector<pair<int,int>>>
// for each pair sum, check if target - pair_sum exists in map
// combine indices carefully to avoid overlaps
vector<vector<int>> fourSumOptimal(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> res;
    unordered_map<long long, vector<pair<int, int>>> mp;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            mp[(long long)nums[i] + nums[j]].push_back({i, j});
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            long long remain = (long long)target - nums[i] - nums[j];
            if (mp.find(remain) != mp.end())
            {
                for (auto &p : mp[remain])
                {
                    int k = p.first, l = p.second;
                    if (k > j) // --> ensure unique indices
                    { 
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        sort(quad.begin(), quad.end());
                        res.insert(quad);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(res.begin(), res.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}