// frist negative number in every window of size k
// given:
//  an array arr
//  a window size k
// for each window of size k, find the first negative number
// if no negative number exists, return 0

// example -> input: arr = [12, -1, -7, 8, -15, 30, 16, 28]
//                      k = 3
//          output: [-1, -1, -7, -15, -15, 0]
// visualization ->
//  window 1: [12 -1 -7] -> -1
//  window 2: [-1 -7 8] -> -1
//  window 3: [-7 8 -15] -> -7
//  window 4: [8 -15 30] -> -15
//  window 5: [-15 30 16] -> -15
//  window 6: [30 16 28] -> 0

// optimal approach -> sliding window + queue/deque
// we store indices of negative numbers
// idea ->
//  add index if element is negative
//  remove index if it goes out of window
//  front of queue = first negative

// algorithm ->
// for each index i:
//  if arr[i] is negative:
//      push index into queue
//  remove front if:
//      index <= i - k
//  if window formed:
//      if queue empty:
//          answer = 0
//      else:
//          answer = arr[queue.front()]

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative (vector<int> &arr, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        // step 1: add negative numbers
        if (arr[i] < 0)
            dq.push_back(i);
        // step 2: remove out-of-window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // step 3: record answer
        if (i >= k - 1) {
            if (dq.empty())
                result.push_back(0);
            else
                result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    vector<int> ans = firstNegative(arr, k);
    for (int x : ans)
        cout << x << " ";
    return 0;
}