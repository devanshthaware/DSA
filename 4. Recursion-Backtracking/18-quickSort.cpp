// Quick Sort
// Quick Sort is one of the fastest sorting algorithms in practice.
// It uses Divide and Conquer, but instead of merging like merge sort, it partitions the array around a pivot.
// Idea:
//  Choose a pivot
//  Place pivot in its correct sorted position
//  Elements smaller → left
//  Elements greater → right
//  Recursively sort both parts

// Example: Array = [8,3,1,7,0,10,2]
//          Pivot = 2
// Partition:
//              [1,0] 2 [8,3,7,10]
// Then recursively sort both parts.
// Partition Concept ->
// Partition rearranges the array so that:
//      elements < pivot | pivot | elements > pivot
// This places the pivot in its final sorted position.

#include <bits/stdc++.h>
using namespace std;

// approach - O(n^2)
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}