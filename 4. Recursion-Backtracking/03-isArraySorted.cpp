// check whether a given array is strictly increasing (or non-decreasing)

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
bool isSorted(int (&arr)[N], size_t index = N - 1)
{
    if (index == 0)
        return true;

    if (arr[index] < arr[index - 1])
        return false;

    return isSorted(arr, index - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[] = {1, 2, 3, 4};
    cout << (isSorted(arr) ? "True" : "False");
    return 0;
}