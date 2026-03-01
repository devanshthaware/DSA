// Painters partition problem
// given painters and set of boards (with length)
// each contiguous boards and all painters paint at the same speed
// goal: minimize the time to paint all boards
// problem: given n boards of lengths in array boards[], and k painters, find the minimum time needed tto paint all boards, if a painter takees 1unit time per unit length
// consteraints:
//      each painter only contiguous boards
//      a board cannot be split
//      all painter start at the same time
//      speed = 1 unit length per 1 unit time
// example -> input: boards = {10, 20, 30, 40}
//            output: 60
// why? -> one painter paints [10, 20, 30], another paints [40]

#include <bits/stdc++.h>
using namespace std;

// approach:
// binary search on answer
// steps:
//      (1) binary search the answer
//          low = max(boards) - one painter paints the biggest board
//          high = sum(boards) - one painter points all board
//      (2) at each mid, check:
//          can we paint all boards with k painters such that no painter paints more than mid time?
// how to check if mid is valid (possible or not):
// use greedy approach:
//      Assign boards to the current painter while total time <= mid
//      if exceeded, assign to next painter
//      if painters > k, then mid is invalid
bool isPossible(const vector<int> &boards, int k, int maxTime)
{
    int painters = 1, time = 0;
    for (int len : boards)
    {
        if (len > maxTime)
            return false;
        if (time + len > maxTime)
        {
            painters++;
            time = len;
            if (painters > k)
                return false;
        }
        else
        {
            time += len;
        }
    }
    return true;
}
int minTimeToPaint(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, k, mid))
        {
            result = mid;
            high = mid - 1; // try smaller max
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    cout << minTimeToPaint(boards, painters);
    return 0;
}