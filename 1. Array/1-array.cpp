// A container that holds multiple elements of same type in contiguous memory location.

#include <bits/stdc++.h>
using namespace std;

// Size of array
template <size_t N>
size_t sizeOfArray(int (&arr)[N])
{
    return N;
}

// Loops on array (accept array by reference so sizeof works)
template <size_t N>
void loopOnArray(int (&arr)[N])
{
    for (size_t i = 0; i < N; ++i)
        cout << arr[i] << "\n";
}

// Find smallest element
template <size_t N>
int smallestElement(int (&arr)[N])
{
    int smallest = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
}

// Find largest element
template <size_t N>
int largestElement(int (&arr)[N])
{
    int largest = arr[0];
    for (size_t i = 1; i < N; i++)
    {
        /* code */
        if (arr[i] > largest)
        {
            /* code */
            largest = arr[i];
        }
    }
    return largest;
}

// Linear search: Search an element one by one in array
template <size_t N>
bool linearSearch(int (&arr)[N], int key)
{
    for (size_t i = 0; i < N; i++)
    {
        /* code */

        if (arr[i] == key)
        {
            /* code */
            return true;
        }
    }
    return false;
}

// Reverse an array
template <size_t N>
void reverseArray(int (&arr)[N])
{
    int start = 0, end = N - 1;
    while (start < end)
    {
        /* code */
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int arr[5] = {10, 20, 30, 40, 50};
    // loopOnArray(arr);

    int a[] = {4, 5, 3, 1, 2};
    // cout << smallestElement(a) << "\n";
    // cout << largestElement(a) << "\n";
    // cout << linearSearch(a, 4) << "\n";

    reverseArray(a);
    loopOnArray(a);
    return 0;
}