// Aggressive cows problem
// given stalls and a number of cows
// you need to place the cows in the stalls such that the minimum distance between any two cow is as large as possible
// given an array of n stall positions (unsorted) and an integer k (number of cows)
// place the cows in stalls such that the minimum distance between any two cows is maximized
// return the maximum possible minimum distance
// example -> input: stalls = {1, 2, 8, 4, 9}, cows = 3
//            output: 3
// place cows at positions: 1, 4, 8 (min distance 3)

#include <bits/stdc++.h>
using namespace std;

// approach:
// binary search on distance -> goal: maximize the minimum sistance between cows
// steps:
//      (1) sort the stall positions
//      (2) binary search on distance:
//          low = 1 (min possible gap)
//          high = max(stalls) - min(stalls) (maxgaps)
//      (3) at each mid, check:
//          can we placee all k cows with at least mid distance between them?
// isPossible: how to check if mid is valid -> use agreedy approach
//      place the first cow at the first stall
//      for each next stall:
//          if distance from last placeed cow >= mid, place a cow
//      if you placed at least k cows, return true
bool isPossible(vector<int> &stalls, int k, int dist)
{
    int cows = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= dist)
        {
            cows++;
            lastPos = stalls[i];
            if (cows == k)
                return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls[0];
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, k, mid))
        {
            result = mid;
            low = mid + 1; // try bigger distance
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows);
    return 0;
}