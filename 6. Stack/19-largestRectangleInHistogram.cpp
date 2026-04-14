// Largest rectangle in histogram
// you are given an array height[] representing the height of bars in histogram
// each bar has width 1
// return the area of the largest rectangle that can be formed
// example -> input: heights = [2, 1, 5, 6, 2, 3]
//            output: 10
// explanation -> bars: 5 and 6
//                width: 2
//                height: 5
//                area = 5 * 2 = 10
// for each bar:
//      find:
//          left boundary -> previous smaller elements
//          right boundary -> next smaller elements
//          width = right - left - 1
//          area = height * width

#include <bits/stdc++.h>
using namespace std;

// brute force
// complexity -> time: O(n^2), space: O(1)
// for every bar:
//  expand left until smaller height
//  expand right until smaller height
//  compute area
int largestRectangleArea (vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int left = i;
        int right = i;
        while (left >= 0 && heights[left] >= heights[i])
            left--;
        while (right < n && heights[right] >= heights[i])
            right++;
        int width = right - left - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// better approach -> precompute NSE & PSE
// complexity -> time: O(n), space: O(n)
// precompute:
//  PSE = previous smaller element
//  NSE = next smaller element
// then compute area in one pass
int largestRectangleAreaBetter (vector<int>& heights) {
    int n = heights.size();
    vector<int> pse(n), nse(n);
    stack<int> st;
    // previous smaller element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    // next smaller element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        if (st.empty())
            nse[i] = n;
        else
            nse[i] = st.top();
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

// optimal approach -> single stack
// complexity -> time: O(n), space: O(n)
// maintain: increasing stack of indices
// when a smaller bar appears:
//  pop
//  calculate area immediately
int largestRectangleAreaOptimal (vector<int>& heights) {
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Brute: "
         << largestRectangleArea(heights)
         << "\n";
    cout << "Better: "
         << largestRectangleAreaBetter(heights)
         << "\n";
    cout << "Optimal: "
         << largestRectangleAreaOptimal(heights)
         << "\n";
    return 0;
}