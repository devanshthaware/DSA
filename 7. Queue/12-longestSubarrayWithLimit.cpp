// Longest subarray with limit
// given:
//  an array nums
//  an integer limit
// find the length of the longest continuous subarray such that:
//  |max(nums[i] - num[j])| <= limit
// for all elements in the subarray
// example -> input: nums = [8, 2, 4, 7]
//                   limit = 4
//            output: 2
// because valid subarrays include:
//  [8]
//  [2, 4]
//  [4, 7]
// but:
//  [2, 4, 7]
//  max - min = 7 - 2 = 5 > 4

// approach -> sliding window + two monotonic deques
// we maintain:
//  maxDeque -> decreasing values (front = maximum)
//  minDeque -> increasing vlues (front = minimum)
// then we check:
//  maxDeque.front() - minDeque.front() > limit
// if true -> shrink window

// why two deque ->
// because we need:
//  current maximum
//  current minimum
// in O(1) time

// algorithm ->
// left = 0
// for right from 0 to n - 1:
//  maintain decreasing maxDeque
//  maintain increasing minDeque
//  while max - min > limit:
//      move left forward
//      remove old indices
//  update answer

#include <bits/stdc++.h>
using namespace std;

int longestSubarray (vector<int> &nums, int limit) {
    deque<int> maxDq;
    deque<int> minDq;
    int left = 0;
    int maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        // maintain max deque
        while (!maxDq.empty() && nums[maxDq.back()] < nums[right])
            maxDq.pop_back();
        maxDq.push_back(right);
        // maintain min deque
        while (!minDq.empty() && nums[minDq.back()] > nums[right])
            minDq.pop_back();
        minDq.push_back(right);
        // shrink window
        while (nums[maxDq.front()] - nums[minDq.front()] > limit) {
            if (maxDq.front() == left)
                maxDq.pop_front();
            if (minDq.front() == left)
                minDq.pop_front();
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    cout << longestSubarray(nums, limit);
    return 0;
}