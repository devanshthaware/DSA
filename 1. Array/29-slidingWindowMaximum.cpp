// Sliding window maximum
// given an array nums and window size k,
// return the maximum element in every window of size k.
// example -> Input:  nums = [1,3,-1,-3,5,3,6,7], k = 3
//            Output : [ 3, 3, 5, 5, 6, 7 ]

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n*k)
// for every window:
//      traverse k elements
//      find maximum
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i <= n - k; i++)
    {
        int maxi = nums[i];
        for (int j = i; j < i + k; j++)
        {
            maxi = max(maxi, nums[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

// better approach - O(nlogk)
// use a max heap (priority_queue)
// store {value, index}
// remove elements outside window
vector<int> maxSlidingWindowBetter(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
        // Remove elements outside window
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        if (i >= k - 1)
            ans.push_back(pq.top().first);
    }
    return ans;
}

// optimal approach - O(n)
// maintain a monotonic decreasing deque:
// store indices
// front = maximum element
// remove:
//      elements outside window
//      smaller elements from back
vector<int> maxSlidingWindowOptimal(vector<int> &nums, int k)
{
    deque<int> dq; // stores indices
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        // Remove out-of-window indices
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // Remove smaller elements
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        // Add max to result
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}