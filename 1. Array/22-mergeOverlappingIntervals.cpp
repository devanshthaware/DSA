// Merge overlapping intervals
// given an array of intervals where intervals[i] = [start, end], merge all overlapping intervals
// example --> input:  [[1, 3], [2, 6], [8, 10], [15, 18]]
//             output : [ [ 1, 6 ], [ 8, 10 ], [ 15, 18 ] ]
// why? --> because [1,3] and [2,6] overlap -> merged into [1,6]

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// for each interval:
//      compare with all others
//      merge if overlapping
//      mark merged intervals
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        int start = intervals[i][0];
        int end = intervals[i][1];
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
                visited[j] = true;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// optimal approach - O(nlogn)
// sort intervals by start time
// compare current interval with last inserted interval
vector<vector<int>> mergeOptimal(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (auto interval : intervals)
    {
        if (ans.empty() || ans.back()[1] < interval[0])
        {
            ans.push_back(interval);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}