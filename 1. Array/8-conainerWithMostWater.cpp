// Container with most water problem
// Given an array height[], where each element represents the height of vertical line drawn at position i on the x-axis.
// you need to find two lines that, together with the x-axis, from a container that holds the most water.
// note --> area = min(height[i], height[j]) * (j - i)
//          container formed by any two lines
//          you can't tilt the container (water is vertical only)
//          you must return the maximum area possible
#include <bits/stdc++.h>
using namespace std;

// brute force approach - O(n^2)
// try all pairs(i, j) -> compute area -> track max
int maxAreaBrute (vector<int>& height){
    int n = height.size(), maxArea = 0;
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        for (size_t j = i + 1; j < n; j++)
        {
            /* code */
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, area);
        }
        
    }
    return maxArea;
}

// optimal two pointer approach - O(n)
// start with two pointers: left = 0, right = n - 1
// calsulate area
// move the pointer with smaller height inward, hoping for ataller line
// why move the smaller one -> because area is limited by the shorter height moving the taller one doesn't help
int maxAreaOptimal (vector<int>& height){
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        /* code */
        int h = min(height[left], height[right]);
        int w = right - left;
        maxArea = max(maxArea, h * w);
        if (height[left] < height[right])
        {
            /* code */
            left++;
        }
        else
        {
            /* code */
            right--;
        }
        
    }
    return maxArea;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Container with most water (Brute force): " << maxAreaBrute(height) << "\n";
    cout << "Container with most water (Optimal): " << maxAreaOptimal(height) << "\n";

    return 0;
}