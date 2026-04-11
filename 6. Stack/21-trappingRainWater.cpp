// Trapping Rain Water
// given an array:
//  height[i] = elevation height
// return the total water trapped after raining
// example -> input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//            output: 6
// core formula -> water at index i :
//      water = min(leftMax, rightMax) - height[i]

#include <bits/stdc++.h>
using namespace std;

// brute force
// complexity -> time: O(n^2), space: O(1)
// for every index:
//  find maximum on left
//  find maximum on right
//  compute water
int trapBrute (vector<int>& height) {
    int n = height.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
        int leftMax = 0;
        int rightMax = 0;
        for (int j = 0; j <= i; i++)
            leftMax = max(leftMax, height[j]);
        for (int j = i; j < n; j++)
            rightMax = max(rightMax, height[j]);
        total += min(leftMax, rightMax) - height[i];
    }
    return total;
}

// better (prefix and suffix array)
// complexity -> time: O(n), space: O(n)
// precompute:
//      leftMax[i]
//      rightMax[i]
int trapBetter (vector<int>& height) {
    int n = height.size();
    vector<int> leftMax(n);
    vector<int> rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);
    int total = 0;
    for (int i = 0; i < n; i++)
        total += min(leftMax[i], rightMax[i]) - height[i];
    return total;
}

// optimal - two pointer
// move the smaller side
//  if leftMax < rightmax
//      move left
//  else
//      move right
int trapOptimal (vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                total += leftMax - height[left];
            left++;
        }
        else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                total += rightMax - height[right];
            right--;
        }
    }
    return total;
}

// stack approach
// monotonic decreasing stack
int trapStack(vector<int> &height) {
    stack<int> st;
    int n = height.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int bottom = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance =
                i - st.top() - 1;
            int boundedHeight =
                min(height[i],
                    height[st.top()]) -
                height[bottom];
            total += distance * boundedHeight;
        }
        st.push(i);
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Brute: "
         << trapBrute(height)
         << "\n";

    cout << "Better: "
         << trapBetter(height)
         << "\n";

    cout << "Optimal: "
         << trapOptimal(height)
         << "\n";

    cout << "Stack: "
         << trapStack(height)
         << "\n";
    return 0;
}