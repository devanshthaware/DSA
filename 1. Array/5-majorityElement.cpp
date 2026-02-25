// Majority element --> an element that appears more than [n/2] time in an array of size n.

#include <bits/stdc++.h>
using namespace std;

// Brute force - O(N^2) --> count frequency of each element using 2 loops
int majorityElement(vector<int> &v)
{
    int n = v.size();
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        int count = 0;
        for (size_t j = 0; j < n; j++)
        {
            /* code */
            if (v[i] == v[j])
            {
                /* code */
                count++;
            }
            if (count > n / 2)
                return v[i];
        }
    }
    return -1;
}

// Better approach using sorting - O(NlogN)
// if a number is majority, it will be at index n/2 after sorting
int majorityElementBetter(vector<int> v)
{
    sort(v.begin(), v.end());
    return v[v.size() / 2];
}

// Moore's voting algorithm - Optimal O(N)
// Maintain a candidate and a count - if count is 0 -> set candidate, if current element == candidate -> count++ else -> count--
int majorityElementOptimal(vector<int> v)
{
    int count = 0, candidate = 0;
    for (int num : v)
    {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element (brute force): " << majorityElement(nums) << "\n";
    cout << "Majority Element (better): " << majorityElementBetter(nums) << "\n";
    cout << "Majority Element (optimal): " << majorityElementOptimal(nums) << "\n";
    return 0;
}