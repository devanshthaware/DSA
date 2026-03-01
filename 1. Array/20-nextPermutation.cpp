// Next permutation
// rearrange numbers into the next lexicographically greater permutation
// if not possible → return the smallest permutation (sorted ascending)

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n! * n)
// generate all permutations
// sort them
// find current permutation
// return next one
void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> perms;
    sort(nums.begin(), nums.end());
    do
    {
        perms.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    // find original and return next (simplified idea)
}

// better approach - O(nlogn)
// Traverse from right
// find first decreasing pair
// swap with smallest greater element on right
// sort the right half
void nextPermutationBetter(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    sort(nums.begin() + ind + 1, nums.end());
}

// optimal approach - O(n)
// the right side after breakpoint is always descending
// so instead of sorting, just reverse it
// steps:
//      find breakpoint
//      swap with just greater element
//      reverse suffix
void nextPermutationOptimal(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;
    // step 1: Find breakpoint
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    // if no breakpoint
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    // step 2: find just greater element
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    // step 3: reverse right half
    reverse(nums.begin() + ind + 1, nums.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}