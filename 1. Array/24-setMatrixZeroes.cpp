// Set matrix zeroes
// given an m x n matrix,
// if an element is 0, set its entire row and column to 0
// do it in-place
// example --> Input:
//                  [
//                      [ 1, 1, 1 ],
//                      [ 1, 0, 1 ],
//                      [ 1, 1, 1 ]
//                  ]
//             Output: [
//                          [ 1, 0, 1 ],
//                          [ 0, 0, 0 ],
//                          [ 1, 0, 1 ]
//                     ]

#include <bits/stdc++.h>
using namespace std;

// brute force - O((m * n) + (m + n))
// traverse matrix
// if matrix[i][j] == 0, mark its row and column with a special value (like -1)
// after traversal, convert -1 to 0
// works only if matrix doesn’t contain -1
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // mark rows and columns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
                for (int k = 0; k < m; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }
    // convert -1 to 0
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// better approach (using extra arrays) - O(m * n)
// use two arrays: row[m] and col[n]
// marks rows and columns containing zero
// traverse again and set to zero
void setZeroesBetter(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 1 || col[j] == 1)
                matrix[i][j] = 0;
        }
    }
}

// optimal approach (using first row and column as markers) - O(m * n)
// first row to mark columns
// first column to mark rows
// use an extra variable col0 to track first column separately
void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;
    // step1: mark rows & columns
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;

        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    // Step2: traverse in reverse
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}