// Search a 2D Matrix
// you are given a 2D matrix, and you need to search for a target element
// there are two common types of matrix structures used in problems -> matrix I and matrix II

#include <bits/stdc++.h>
using namespace std;

// case 1: Search in matrix I
// matrix properties: each row is sorteed in ascending order
//                    first element of each row is greater than the last element of the previous row
// example -> (1, 3, 5, 7),
//            (10, 11, 16, 20),
//            (23, 30, 34, 50)
// approach -> binary search - O(log(m * n))
// treat the 2D matrix as a 1D sorted array
// total elements: m*n
// map 1D index to 2D with: row = index / n
//                          col = index % n
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int low = 0, high = rows * cols - 1;
    while (low <= high)
    {
        /* code */
        int mid = low + (high - low) / 2;
        int midValue = matrix[mid / cols][mid % cols];
        if (midValue == target)
        {
            /* code */
            return true;
        }
        else if (midValue < target)
        {
            /* code */
            low = mid + 1;
        }
        else
        {
            /* code */
            high = mid - 1;
        }
    }
    return false;
}

// case 2: Search in matrix II
// matrix properties: each row is sorted in ascending order
//                    each column is sorted in ascending order
// example -> (1, 4, 7, 11),
//            (2, 5, 8, 12),
//            (3, 6, 9, 16),
//            (10, 13, 14, 17)
// approach -> stairecase search - O(m + n)
// start form top-right corner:
// if target < current -> move left
// if target > current -> move down
bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size(), cols = matrix[0].size();
    int r = 0, c = cols - 1;
    while (r < rows && c >= 0)
    {
        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] > target)
            c--;
        else
            r++;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}};
    cout << "Is 30 is present in matrix: " << (searchMatrix(matrix1, 30) ? "yes" : "no") << "\n";
    
    vector<vector<int>> matrix2 = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    cout << "Is 14 is present in matrix: " << (searchMatrix2(matrix2, 14) ? "yes" : "no") << "\n";

    return 0;
}