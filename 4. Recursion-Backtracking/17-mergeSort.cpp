// Merge Sort
// Merge Sort is a Divide and Conquer sorting algorithm.
// Idea:
//      Divide the array into two halves
//      Recursively sort both halves
//      Merge the sorted halves
// Example:
//  Array = [8,3,5,4,7,6,1,2]
// Divide:
//  [8,3,5,4]   [7,6,1,2]
// Divide again:
//  [8,3] [5,4] [7,6] [1,2]
// Single elements:
//  [8] [3] [5] [4] [7] [6] [1] [2]
// Merge sorted:
//  [3,8] [4,5] [6,7] [1,2]
// Final merge:
//  [1,2,3,4,5,6,7,8]

#include <bits/stdc++.h>
using namespace std;

// approach - O(nlogn)
// Merge sort has two main steps:
//  1. Divide
//  2. Merge
// Recursive structure:
//  mergeSort(left)
//  mergeSort(right)
//  merge(left, right)
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {8, 3, 5, 4, 7, 6, 1, 2};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}