// Single element in a sorted array
// given a sorted array where every elements appears exactly twice for one element that appears only once
// problem: find the singlee non-duplicate element in O(logn) time and O(1) space
// example: input: {1, 2, 2, 3, 4, 4, 5, 5}
//          output: 3

#include <bits/stdc++.h>
using namespace std;

// approach:
// (binary search with index pattern)
// before the single element: first instnce is at even index
// after the single element: this pattern breaks
// handling edge cases:
// empty array -> return -01 or throw error
// array with only one element -> return that element
// array not following pair pattern -> optional validation
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    // edge case 1
    if (n == 0)
    {
        cerr << "Error: Empty array!" << "\n";
        return -1;
    }
    // edge case 2
    if (n == 1)
        return nums[0];
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (mid % 2 == 1) // make sure mid is even
            mid--;
        // check pair validity
        if (mid + 1 < n && nums[mid] == nums[mid + 1])
            low = mid + 2;
        else
            high = mid;
    }
    return nums[low];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    cout << singleNonDuplicate(nums) << "\n";
    return 0;
}