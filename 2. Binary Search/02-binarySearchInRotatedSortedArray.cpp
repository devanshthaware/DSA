// Binary search in rotated sorted array
// a rotated sorted array is an array that was initially sortedd in ascending order but then rotated (shifted at some unknown pivot)
// problem: given a rotated sorted array and a target return the index of the target if it exists, otherwise return -1
// example --> input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//             output: 4

#include <bits/stdc++.h>
using namespace std;

// approach:
// at any point in the array, onehalf will alway be sorted
// use a modified binary search:
//      check if left half is sorted -> nums[low] <= nums[mid]
//      if so, see if target is in that range
//      else, the right half must be sorted -> check if target lie there
// narrow the search range based on where the target could  lie
// time complexity: O(logn)
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        // check if left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // right half is sorted
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0);
    return 0;
}