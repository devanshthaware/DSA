// Three sum
// given an array of integers nums[]
// return all unique triplets [nums[i], nums[j], nums[k]] such that
// nums[i] + nums[j] + nums[k] = 0
// example --> input: nums = [-1, 0, 1, 2, -1, -4]
//             output: [[-1, -1, 2], [-1, 0, 1]]

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^3)
// try every possible triplet in the array
// for every combination of i, j, k check if their sum equals 0
// to avoid duplicates, sort each triplet before storing
vector<vector<int>> threeSumBrute(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st; // --> to avoid duplicate triplets

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// better approach - O(n^2 logn)
// fix one element
// reduce the problem to two sum
// for each i, find pairs (j, k) such that
// nums[j] + nums[k] = -nums[i]
// use a hash set to track seen numbers
// use set to avoid duplicate triplets
vector<vector<int>> threeSumBetter(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> seen;

        for (int j = i + 1; j < n; j++)
        {
            int complement = -nums[i] - nums[j];

            if (seen.find(complement) != seen.end())
            {
                vector<int> temp = {nums[i], nums[j], complement};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            seen.insert(nums[j]);
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

// optimal - O(n^2)
// sort the array first
// fix one element
// use two pointers to find the remaining two elements
// skip duplicates directly instead of using a set
vector<vector<int>> threeSumOptimal(vector<int> &nums)
{
    vector<vector<int>> result;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
       
        if (i > 0 && nums[i] == nums[i - 1]) // --> skip duplicate values for i
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                // skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++; // --> need bigger sum (moving left increases sum)
            }
            else
            {
                right--; // --> need smaller sum (moving right decreases sum)
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}