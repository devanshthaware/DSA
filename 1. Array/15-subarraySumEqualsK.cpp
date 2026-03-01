// Subarray sum equals k
// given an integer array nums and an integer k, count the number of continuous subarrays whose sum equals k
// example --> input: nums = [1, 1, 1], k = 2
//             output: 2
// why? -> [1, 1] & [1, 1] (two subarrays)

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// check all subarrays by nested loops
// compute the sum for each subarray
int subarraySumBrute (vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

// optimal using hash map - O(n)
// use prefix sum + hash map
// map[prefix_sum] = count of occurrences
// if sum[i] - k exists in map, there’s a subarray ending at i with sum k
int subarraySumOptimal (vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;

    for (int num : nums)
    {
        sum += num;
        if (mp.find(sum - k) != mp.end())
            count += mp[sum - k];
        mp[sum]++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 1, 1};
    cout << "Subarray sum equals k=2 (brute): " << subarraySumBrute(nums, 2) << "\n";
    cout << "Subarray sum equals k=2 (optimal): " << subarraySumOptimal(nums, 2) << "\n";
    return 0;
}