// Single Number
// case1: given an integer array where every elment appears twice except one, find that single one
// case2: given an integer array where every element appears three times except one, find that single one

#include <bits/stdc++.h>
using namespace std;

// case1: Single number I

// brute force - O(n^2)
// for each element, count its frequency
int singleNumber(vector<int> nums)
{
    int n = nums.size();
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        int count = 0;
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            if (nums[i] == nums[j])
            {
                /* code */
                count++;
            }
        }
        if (count == 1)
        {
            /* code */
            return nums[i];
        }
    }
    return -1;
}

// better (using hashing) - O(n)
// store in a frequency map
int singleNumberBetter(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int num : nums)
        mp[num]++;

    for (auto it : mp)
    {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}

// optimal approach (using XOR) - O(n)
// XOR properties:
//      a ^ a = 0
//      a ^ 0 = a
//      XOR is commutative & associative
// so duplicate numbers cancel out
int singleNumberOptimal (vector<int> nums){
    int result = 0;
    for (int num : nums){
        result ^= num;
    }
    return result;
}

// case2: Single number II

// brute force - O(n^2)
// count frequency of every element
int singleNumberII(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
                count++;
        }
        if (count == 1)
            return nums[i];
    }
    return -1;
}

// better (hash map) - O(n)
int singleNumeberIIBetter (vector<int> nums){
    unordered_map<int, int> mp;
    for (int num : nums)
        mp[num]++;

    for (auto it : mp)
    {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}

// optimal approach (bit manipulation)
// since every number appears 3 times
// their bits also appear 3 times
// count set bits at each position (0–31)
// take % 3
// rebuild the number
int singleNumberIIOptimal(vector<int> &nums)
{
    int result = 0;
    for (int bit = 0; bit < 32; bit++)
    {
        int count = 0;
        for (int num : nums)
        {
            if (num & (1 << bit))
                count++;
        }
        if (count % 3 != 0)
            result |= (1 << bit);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}