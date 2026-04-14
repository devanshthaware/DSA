// sliding window maximum
// given an array and window size k, return the maximum element in every window
// nums = [1, 3, -1, -3, 5, 3, 6, 7]
// k = 3
// output: [3, 3, 5, 5, 6, 7]
// Why Deque?
// We maintain a decreasing deque of indices
// Front -> Maximum of current window
// Back  -> Smaller elements removed
// So the deque always contains useful candidates only
// Visualization:
// Window size = 3
// [1 3 -1] -3 5 3 6 7
//    ^
//  Max = 3
// Deque stores indices of elements in decreasing order

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(
    vector<int> &nums,
    int k)
{
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        // Remove out-of-window index
        if (!dq.empty() &&
            dq.front() == i - k)
        {
            dq.pop_front();
        }
        // Remove smaller elements
        while (!dq.empty() &&
               nums[dq.back()] <
                   nums[i])
        {
            dq.pop_back();
        }
        // Add current index
        dq.push_back(i);
        // Window ready
        if (i >= k - 1)
        {
            result.push_back(
                nums[dq.front()]);
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums =
        {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;

    vector<int> ans =
        maxSlidingWindow(nums, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}