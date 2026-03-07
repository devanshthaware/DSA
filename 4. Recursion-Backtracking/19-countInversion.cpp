// Count Inversions in an Array
// The Count Inversions problem asks:
//  How many pairs (i, j) exist such that
//      i < j and arr[i] > arr[j]
// It measures how far an array is from being sorted
// Example
//          Array = [8, 4, 2, 1]
// Inversions:
//              (8,4)
//              (8,2)
//              (8,1)
//              (4,2)
//              (4,1)
//              (2,1)
// Total: 6

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// In the brute force method, we check every pair (i, j) where:
//  i < j
// and count if:
//  arr[i] > arr[j]
// Each such pair is an inversion
int countInversions(vector<int> &arr)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

// optimal approach - O(nlogn)
// modify Merge Sort to count inversions during merging.
// Key observation:
//      If
//          left[i] > right[j]
//      then all remaining elements in left are also greater.
// So inversions:
//                  mid - i + 1
// Example
//  Left  = [3,5]
//  Right = [2,4]
// When merging:
//          3 > 2
// Remaining elements in left:
//          3,5
// Inversions added:
//          2
long long merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;
    long long inv = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            inv += (mid - i + 1);
            j++;
        }
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++)
        arr[k] = temp[k - left];
    return inv;
}
long long countInversionsOptimal(vector<int> &arr, int left, int right)
{
    long long inv = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        inv += countInversionsOptimal(arr, left, mid);
        inv += countInversionsOptimal(arr, mid + 1, right);
        inv += merge(arr, left, mid, right);
    }
    return inv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {8, 4, 2, 1};
    cout << "Count Inversion (brute): " << countInversions(arr) << "\n";
    cout << "Count Inversion (optimal): " << countInversionsOptimal(arr, 0, arr.size() - 1);
    return 0;
}