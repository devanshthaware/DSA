// Maximal Rectangle (Binary Matrix)
// given a binary matrix filled with '0' and '1'
// return the area of the largest rectangle containing only 1's
// example -> input: [
//                      ["1", "0", "1", "0", "0"],
//                      ["1", "0", "1", "1", "1"],
//                      ["1", "1", "1", "1", "1"],
//                      ["1", "0", "0", "1", "0"]
//                   ]
//            output: 6
// core idea -> convert each row into histogram, then solve:
//      largest rectangle in histogram
// rule:
//      if matrix[r][c] == '1'
//          height[c]++
//      else
//          height[c] = 0
// then compute largest rectangle for that row

#include <bits/stdc++.h>
using namespace std;

// brute force
// check all possible rectangles and verify all cells are 1
// complexity -> time: O(n^4), space: O(1)
int maximalRectangleBrute(vector<vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea = 0;
    for (int r1 = 0; r1 < rows; r1++) {
        for (int c1 = 0; c1 < cols; c1++) {
            if (matrix[r1][c1] == '0')
                continue;
            for (int r2 = r1; r2 < rows; r2++) {
                for (int c2 = c1; c2 < cols; c2++) {
                    bool valid = true;
                    for (int i = r1; i <= r2 && valid; i++) {
                        for (int j = c1; j <= c2; j++) {
                            if (matrix[i][j] == '0') {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (valid) {
                        int area = (r2 - r1 + 1) * (c2 - c1 + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }
    }
    return maxArea;
}

// better approach (histogram + brute histogram)
// time: O(rows * cols^2)
int largestHistogramBrute (vector<int> &heights) {
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        for (int j = i; j < n; j++) {
            minHeight = min(minHeight, heights[j]);
            int width = j - i + 1;
            maxArea = max(maxArea, minHeight * width);
        }
    }
    return maxArea;
}
int maximalRectangleBetter (vector<vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (matrix[r][c] == '1')
                heights[c]++;
            else
                heights[c] = 0;
        }
        maxArea = max(maxArea, largestHistogramBrute(heights));
    }
    return maxArea;
}

// optimal approach (histogram + monotonic stack)
// time: O(rows * cols)
int largestHistogramOptimal(vector<int> &heights) {
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() &&
               (i == n ||
                heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
int maximalRectangleOptimal (vector<vector<char>> &matrix) {
    if (matrix.empty())
        return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (matrix[r][c] == '1')
                heights[c]++;
            else
                heights[c] = 0;
        }
        maxArea = max(maxArea, largestHistogramOptimal(heights));
    }
    return maxArea;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Brute: "
         << maximalRectangleBrute(matrix)
         << "\n";

    cout << "Better: "
         << maximalRectangleBetter(matrix)
         << "\n";

    cout << "Optimal: "
         << maximalRectangleOptimal(matrix)
         << "\n";
    return 0;
}