// Largest rectangle in a histogram
// given an array heights[], where each element represents bar height (width = 1),
// find the area of the largest rectangle in the histogram
// example -> Input:  [2, 1, 5, 6, 2, 3]
//            Output : 10
// why? -> largest rectangle = height 5 and 6 → width 2 → area 10

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// for each bar:
//      expand left until smaller height
//      expand right until smaller height
//      area = height × width
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int left = i, right = i;
        while (left >= 0 && heights[left] >= heights[i])
            left--;
        while (right < n && heights[right] >= heights[i])
            right++;
        int width = right - left - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

// better approach (precompute NSE & PSE) - O(n)
// find:
//      previous Smaller Element (PSE)
//      next Smaller Element (NSE)
// using stack.
// width:
//      NSE[i] - PSE[i] - 1
int largestRectangleAreaOptimal(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    vector<int> left(n), right(n);
    // Previous Smaller
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    // Next Smaller
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}