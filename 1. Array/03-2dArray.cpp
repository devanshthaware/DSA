// A 2d array is like a grid or a table with rows and columns. It stores data in a matrix format.

#include <bits/stdc++.h>
using namespace std;

template <size_t R, size_t C>
void loopOn2dArray(int (&arr)[R][C]){
    for (size_t i = 0; i < R; i++)
    {
        /* code */
        for (size_t j = 0; j < C; j++)
        {
            /* code */
            cout << arr[R][C] << " ";
        }
        cout << "\n";
        }
    
}

// Linear search on a matrix
template <size_t R, size_t C>
bool findElement(int (&arr)[R][C], int target){
    for (size_t i = 0; i < R; i++)
    {
        /* code */
        for (size_t j = 0; j < C; j++)
        {
            /* code */
            if (arr[i][j] == target)
                return true;
        }
        
    }
    return false;
}

// Maximum row sum
template <size_t R, size_t C>
int maxRowSum (int (&arr)[R][C]){
    int maxSum = INT32_MIN;
    for (size_t i = 0; i < R; i++)
    {
        /* code */
        for (size_t j = 0; j < C; j++)
        {
            /* code */
            sum += arr[i][j];
        }
        maxSum = max(maxSum, sum);
        }
        return maxSum;
}

// Diagonal sum
template <size_t R, size_t C>
int diagonalSum (int (&arr)[R][C], int n){
    int sum = 0;
    for (size_t i = 0; i < R; i++)
    {
        /* code */
        sum += arr[i][i]; // <-- main diagonal
        if (i != n - i - 1)
            sum += arr[i][n - i - 1]; // <-- secondary diagonal
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // declaration of 2d array
    int arr[3][4]; // <-- 3 rows and 4 columns

    // accessing elements
    arr[1][2] = 10;
    cout << arr[1][2] << "\n";

    // 2d vector
    vector<vector<int>> vec(3, vector<int>(4)); // <-- declaration
    for (size_t i = 0; i < vec.size(); i++)
    {
        /* code */
        for (size_t j = 0; j < vec[i].size(); j++)
        {
            /* code */
            cin >> vec[i][j];
        }
        
    }
    
    return 0;
}