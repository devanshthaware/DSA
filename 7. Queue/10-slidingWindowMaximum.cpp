// Sliding Window Maximum
// given:
//  an array nums
//  a window size k
// return the maximum element in every window of size k

// example ->
//  input: nums = [1, 3, -1, -3, 5, 3, 6, 7]
//         k = 3
//  output: [3, 3, 5, 5, 6, 7]
// visualiztion ->
//  window 1: [1 3 -1] -> max = 3
//  window 2: [3 -1 -3] -> max = 3
//  window 3: [-1 -3 5] -> max = 5
//  window 4: [-3 5 3] -> max = 5
//  window 5: [5 3 6] -> max = 6
//  window 6: [3 6 7] -> max = 7

#include <bits/stdc++.h>
using namespace std;

// optimal approach - monotonic deque
// we maintain a deque of indices such that:
//  elements are in decreasing order
//  front always contains maximum

// for each element:
//  remove indices outside window
//  remove smaller elements from back
//  add current index
//  record front as maximum

// why deque works
//  front -> maximum
//  back -> smaller elements
// each element:
//  inserted once
//  removed once
// so: O(n)

vector<int> maxSlidingWindow (vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        // 1. remove out-of-window indices
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        
        // 2. remove smaller elements
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        // 3. add index
        dq.push_back(i);
        // 4. record answer
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int x : ans)
        cout << x << " ";
    return 0;
}