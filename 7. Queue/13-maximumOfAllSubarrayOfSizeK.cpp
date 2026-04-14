// Maximum of all subarrays of size k
// given:
//  an array arr
//  an integer k
// find the maximum element of every contiguous subarray of size k
// example -> input: arr = [1, 3, -1, -3, 5, 3, 6, 7]
//                   k = 3
//            output: [3, 3, 5, 5, 6, 7]
// visualization ->
//  window 1: [1 3 -1] -> 3
//  window 2: [3 -1 -3] -> 3
//  window 3: [-1 -3 5] -> 5
//  window 4: [-3 5 3] -> 5
//  window 5: [5 3 6] -> 6
//  window 6: [3 6 7] -> 7

// optimal approach -> monotonic deque
// we maintain a deque of indices such that:
//  elements are in decreasing order
//  front always contains maximum

// for each index i:
//  remove indices outside window
//  remove smaller elements from back
//  insert current index
//  front = maximum

// why deque ->
// front -> maximum
// back -> smaller elements
// each element:
//  inserted once
//  removed once
// so: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarrays (vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        // 1. remove out-of-window indices
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        // 2. remove smaller eelements
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        // 3. add index
        dq.push_back(i);
        // 4. store result
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = maxOfSubarrays(arr, k);
    for (int x : ans)
        cout << x << " ";
    return 0;
}