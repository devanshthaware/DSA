// Reverse pairs
// given an array nums, count pairs (i, j) such that:
//          i < j  AND  nums[i] > 2 * nums[j]
// example -> Input:  [1, 3, 2, 3, 1]
//            Output : 2
// why? -> Valid pairs: (3, 1), (3, 1)

#include <bits/stdc++.h>
using namespace std;

// brute force - (n^2)
// check every pair (i, j)
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((long long)nums[i] > 2LL * nums[j])
                count++;
        }
    }
    return count;
}

// optimal approach - O(nlogn)
// condition is:
//              nums[i] > 2 * nums[j]
// while merging:
//              count valid pairs before merging
//              then perform normal merge
int merge(vector<int> &nums, int low, int mid, int high)
{
    int count = 0;
    int j = mid + 1;
    // Count reverse pairs
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && (long long)nums[i] > 2LL * nums[j])
            j++;
        count += (j - (mid + 1));
    }
    // Merge step
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }
    while (left <= mid)
        temp.push_back(nums[left++]);

    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];

    return count;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    int count = 0;

    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);

    return count;
}
int reversePairsOptimal(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}