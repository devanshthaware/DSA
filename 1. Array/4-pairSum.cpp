// Pair sum --> given an arrray and a target sum, find all pairs of elements in the array whose sum equals target.

#include <bits/stdc++.h>
using namespace std;

// Brute force - O(N^2)
vector<pair<int, int>> pairSum(vector<int> &v, int target)
{
    int n = v.size();
    vector<pair<int, int>> ans;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        for (size_t j = i + 1; j < n; j++)
        {
            /* code */
            if (v[i] + v[j] == target)
            {
                {
                    ans.push_back({v[i], v[j]});
                }
            }
        }
    }
    return ans;
}

// Better approach - O(N logN) <-- due to sorting
vector<pair<int, int>> pairSumTwoPointer(vector<int> &v, int target)
{
    sort(v.begin(), v.end());

    vector<pair<int, int>> ans;
    int left = 0, right = v.size() - 1;

    while (left < right)
    {
        int sum = v[left] + v[right];

        if (sum == target)
        {
            ans.push_back({v[left], v[right]});
            left++;
            right--;
        }
        else if (sum < target)
            left++;
        else
            right--;
    }

    return ans;
}

// Optimal approach (uses a hash set) - O(N) --> Hash-based optimization
vector<pair<int, int>> pairSumUniqueOptimal(vector<int> &v, int target) // <-- this will avoid duplicate pair
{
    unordered_set<int> seen;
    set<pair<int, int>> uniquePairs;

    for (int num : v)
    {
        int complement = target - num;

        if (seen.count(complement))
        {
            int a = min(num, complement);
            int b = max(num, complement);
            uniquePairs.insert({a, b});
        }

        seen.insert(num);
    }

    return vector<pair<int, int>>(uniquePairs.begin(), uniquePairs.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int target = 10;
    vector<int> v = {3, 5, 2, 8, 11};
    vector<pair<int, int>> result = pairSum(v, target);

    if (result.empty())
    {
        cout << "No pairs found\n";
    }
    else
    {
        cout << "Pairs found:\n";
        for (auto p : result)
        {
            cout << p.first << ", " << p.second << "\n";
        }
    }

    return 0;
}