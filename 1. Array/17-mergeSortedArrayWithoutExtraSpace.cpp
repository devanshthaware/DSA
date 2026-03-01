// Merge two sorted arrays without using extra space
// you are given two arrays arr1[] of size n, arr2[] of size m  both are already sorted
// merge these two arrays in a single sorted array
// after merging
// arr1 contains the first n smallest elements
// arr2 contains the remaining m largest elements

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n + m)log(n + m)
// copy both array into a third array
// sort it
// put first n elements back to arr1[]
// remaining into arr2[]
void merge(long long arr1[], long long arr2[], int n, int m)
{
    vector<long long> temp;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        temp.push_back(arr1[i]);
    }
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        temp.push_back(arr2[i]);
    }
    sort(temp.begin(), temp.end());
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        arr1[i] = temp[i];
    }
    for (size_t i = 0; i < m; i++)
    {
        /* code */
        arr2[i] = temp[n + i];
    }
}

// better approach - O(n + m)
// use two pointers
// compare arr1[i] & arr2[j]
// store in temp array(like merge step of merge sort)
void mergeBetter(long long arr1[], long long arr2[], int n, int m)
{
    vector<long long> temp;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        /* code */
        if (arr1[i] <= arr2[j])
        {
            /* code */
            temp.push_back(arr1[i++]);
        }
        else
        {
            /* code */
            temp.push_back(arr2[j++]);
        }
        while (i < n)
            temp.push_back(arr1[i++]);

        while (j < m)
            temp.push_back(arr2[j++]);

        for (int k = 0; k < n; k++)
            arr1[k] = temp[k];

        for (int k = 0; k < m; k++)
            arr2[k] = temp[n + k];
    }
}

// optimal approach - O((n + m)log(n + m)), space = O(1)
// gap method
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int gap = nextGap(n + m);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;

        while (j < n + m)
        {
            if (j < n && arr1[i] > arr1[j]) // --> both pointers in arr1
                swap(arr1[i], arr1[j]);
            else if (i < n && j >= n && arr1[i] > arr2[j - n]) // --> i in arr1, j in arr2
                swap(arr1[i], arr2[j - n]);           
            else if (i >= n && arr2[i - n] > arr2[j - n]) // --> both in arr2
                swap(arr2[i - n], arr2[j - n]);
            i++;
            j++;
        }
        gap = nextGap(gap);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}