// Spiral Matrix
// given a 2D matrix, print or return all elements in spiral order, starting from the top left and moving clockwise
// example -> input: [1, 2, 3]        output: 1 2 3 6 9 8 7 4 5
//                   [4, 5, 6]
//                   [7, 8, 9]

#include <bits/stdc++.h>
using namespace std;

// approach -> use four boundaries to track the limits: top, bottom, left, right
// repeat this in order:
//                       traverse left to right (top row)
//                       traverse top to bottom (right column)
//                       traverse right to left (bottom row)
//                       traverse bottom to top (left colummn)
// update the boundaries after each direction
// edge case -> matrix is empty: matrix.size() == 0
//              matrix has only one row or one column
//              matrix is not square (e.g. 3 * 4)
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty() || matrix[0].empty()) // --> edge case
    {
        /* code */
        return result;
    }
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    while (top <= bottom && left <= right)
    {
        /* code */
        for (int col = left; col <= right; col++) // --> left to right
        {
            /* code */
            result.push_back(matrix[top][col]);
        }
        top++;
        for (int row = top; row <= bottom; row++) // --> top to bottom
        {
            /* code */
            result.push_back(matrix[row][right]);
        }
        right--;
        if (top <= bottom)
        {
            /* code */
            for (int col = right; col >= left; col--) // --> right to left
            {
                /* code */
                result.push_back(matrix[bottom][col]);
            }
            bottom--;
        }
        if (left <= right){
            for (int row = bottom; row >= top; row--) // --> bottom to top
            {
                /* code */
                result.push_back(matrix[row][left]);
                
            }
            left++;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    vector<int> result = spiralOrder(matrix);
    cout << "Spiral order: ";
    for(int val:result){
        cout << val << " ";
    }
    return 0;
}