// Count Inversion
// given an array, count the number of inversions
// an inversion is a pair (i, j) such that:
//          i < j  AND  arr[i] > arr[j]
// example -> Input:  [5, 3, 2, 4, 1]
//            Output : 8
// why? -> inversions:  (5,3), (5,2), (5,4), (5,1),
//                      (3, 2), (3, 1),
//                      (2, 1),
//                      (4, 1)
//          total = 8

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// check every pair (i, j)
long long countInversions(vector<int> &arr)
{
    int n = arr.size();
    long long count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

// optimal approach - O(nlogn)
// During merge step:
//      if: left[i] > right[j], then all remaining elements in left are greater than right[j]
// so: count += (mid - i + 1)
long long merge(vector<int> &arr, int low, int mid, int high)
{

    vector<int> temp;
    int left = low;
    int right = mid + 1;
    long long count = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            count += (mid - left + 1);
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
        temp.push_back(arr[left++]);

    while (right <= high)
        temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return count;
}
long long mergeSort(vector<int> &arr, int low, int high)
{
    long long count = 0;
    if (low < high)
    {
        int mid = (low + high) / 2;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }

    return count;
}
long long countInversionsOptimal(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}