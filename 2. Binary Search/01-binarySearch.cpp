// Binary search algorithm
// binary search is an efficient algorithm to find an element in a sorted array by repeatedly dividing the search interval in half
// binary search approach -->
//      set low = 0 and high = n-1
//      while low <= high:
//          compute mid = (low + high) / 2
//          if arr[mid] == target, return index
//          if arr[mid] < target, search in right half: low = mid + 1
//          else, search in left half: high = mid - 1

// optimization -> use: mid = low + (high - low) / 2 instead of mid = (low + high) / 2
//                 to prevent integer overflow

#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t N>
int binarySearch(T (&arr)[N], int target)
{
    int low = 0, high = N - 1;
    while (low <= high){
        int mid = low + (high - low) / 2; // --> overflow  safe mid calculation
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // --> element not found
};

// Recursive binary search
template <typename T, size_t N>
int recursiveBinarySearch(T (&arr)[N], int low, int high, T target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return recursiveBinarySearch(arr, low, mid - 1, target);
    else
        return recursiveBinarySearch(arr, mid + 1, high, target);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {1, 3, 5, 7, 9, 11};
    int result = binarySearch(arr, 7);
    int resultRecursive = recursiveBinarySearch(arr, 0, 5, 7);

    cout << result << "\n";
    cout << resultRecursive;
    return 0;
}