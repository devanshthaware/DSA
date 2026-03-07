// Sort an array of 0s, 1s, 2s (Dutch National Flag Problem)
// given an array containing only 0, 1, and 2, sort it in-place
// example --> input: [2, 0, 2, 1, 1, 0]
//             output: [0, 0, 1, 1, 2, 2]

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// use a general sorting algorithm (like bubble sort, selection sort, or built-in sort())
// since the array contains only 0, 1, 2, sorting it normally will work
// void sortColors(vector<int> &nums) // --> using built in sort - O(nlogn)
// {
//     sort(nums.begin(), nums.end());
// }
void sortColors(vector<int> &nums) // --> using bubble sort
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

// better approach (counting) - O(n)
// count number of 0s, 1s, 2s
// overwite the array
void sortColorsBetter(vector<int> &nums)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int num : nums)
    {
        if (num == 0)
            count0++;
        else if (num == 1)
            count1++;
        else
            count2++;
    }
    int i = 0;
    while (count0--)
        nums[i++] = 0;
    while (count1--)
        nums[i++] = 1;
    while (count2--)
        nums[i++] = 2;
}

// optimal approach (dutch natinal flag algorithm)
// three pointers
// low -> boundary for 0
// mid -> current element
// high -> boundary for 2
// if nums[mid] == 0 -> swap with low, move both
// if nums[mid] == 1 -> move mid
// if nums[mid] == 2 -> swap with high, move high
void sortColorsOptimal(vector<int> &nums)
{
    int low = 0, mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else // --> nums[mid] == 2
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}