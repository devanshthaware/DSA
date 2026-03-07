// Trapping rainwater
// given an array height[] representing elevation map,
// compute how much water it can trap after raining
// example -> Input:  [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//            Output : 6

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// for every index:
//      find max height on left
//      find max height on right
//      water = min(leftMax, rightMax) - height[i]
int trap(vector<int> &height)
{
    int n = height.size();
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int leftMax = 0, rightMax = 0;

        for (int j = 0; j <= i; j++)
            leftMax = max(leftMax, height[j]);

        for (int j = i; j < n; j++)
            rightMax = max(rightMax, height[j]);

        total += min(leftMax, rightMax) - height[i];
    }
    return total;
}

// better approach - O(n)
// Precompute:
//      leftMax[i]
//      rightMax[i]
// then calculate water in one pass
int trapBetter(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    vector<int> leftMax(n), rightMax(n);
    int total = 0;

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);

    for (int i = 0; i < n; i++)
        total += min(leftMax[i], rightMax[i]) - height[i];

    return total;
}

// optimal approach (two pointer) - O(n)
// water depends on smaller boundary
// use:
//      left pointer
//      right pointer
// track leftMax and rightMax
int trapOptimal(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int total = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                total += leftMax - height[left];

            left++;
        }
        else
        {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                total += rightMax - height[right];
            right--;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}