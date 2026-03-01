// Peak index in mountain array
// a mountain array is an array where:
//      elements first strictly increase to a peak, and then
//      strictly decrease afterwards
// Problem: given an mountain array, return the index of the peak element
// example --> input: arr = [0, 2, 4, 3, 1]
//             output: 2 (because 4 is the peak)

#include <bits/stdc++.h>
using namespace std;

// approach: O(logn)
// if arr[mid] > arr[mid + 1], we are in the increasing part -> go left
// repeat until low == high (that index will be peak)
// handling edge cases:
//      valid mountain array:
//          length >= 3
//          must have at least one increase then decrease
//      invalid:
//          [1, 2, 3] or [3, 2, 1] -> no peak like a mountain -> problem assumes valid input -> but we can add a check if required in real-world problems
int peakIndexInMountainArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1; // -> ascending part
        else
            high = mid; // -> descending part or peak
    }
    return low; // or return high
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {1, 3, 5, 7, 6, 2};
    cout << peakIndexInMountainArray(arr);
    return 0;
}