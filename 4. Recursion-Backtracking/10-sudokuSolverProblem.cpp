// Sudoku solver
// fill a 9 × 9 Sudoku board so that:
//  each row contains digits 1–9
//  each column contains digits 1–9
//  each 3×3 subgrid contains digits 1–9
//  empty cells are represented by '.'

#include <bits/stdc++.h>
using namespace std;

// approach 1 -> bactracking
// time complexity: O(9^(empty cell))
// find an empty cell
// try numbers 1 -> 9
// check if placing the number is valid
// if valid -> place it and recurse
// if it leads to dead end -> backtrack
// A number is valid if:
//  not in same row
//  not in same column
//  not in same 3×3 box
//  box index:
//  row/3 * 3 , col/3 * 3
bool isValid(vector<vector<char>> &board, int row, int col, char num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
        int r = 3 * (row / 3) + i / 3;
        int c = 3 * (col / 3) + i % 3;
        if (board[r][c] == num)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                for (char num = '1'; num <= '9'; num++)
                {
                    if (isValid(board, row, col, num))
                    {
                        board[row][col] = num;

                        if (solve(board))
                            return true;
                        board[row][col] = '.'; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// approach 2 -> bitmasks + backtracking + minimum choice heuristic
// instead of checking row/column/box every time, maintain bitmasks:
//      rowMask[9]
//      colMask[9]
//      boxMask[9]
// each mask stores which numbers are already used.
// example:
//  rowMask[0] = 001010010
// means digits 2,5,7 are used in row 0.
// bit Representation
// digit d -> bit (1 << d)
// example:
//  1 << 5 = 100000
// allowed Numbers Trick
//  int mask = ~(rowMask[r] | colMask[c] | boxMask[b]) & 0x3FE;
// why 0x3FE?
//  1111111110
// bits 1–9 allowed, ignoring bit 0.
// extract Possible Numbers
//  int bit = mask & -mask
// this extracts the lowest set bit.
// example:
//  mask = 1011000
//  bit  = 0001000
vector<vector<char>> board;
int rowMask[9] = {0};
int colMask[9] = {0};
int boxMask[9] = {0};
bool solveOptimal()
{
    int r = -1, c = -1;
    int minOptions = 10;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                int b = (i / 3) * 3 + j / 3;
                int mask = ~(rowMask[i] | colMask[j] | boxMask[b]) & 0x3FE;
                int options = __builtin_popcount(mask);
                if (options < minOptions)
                {
                    minOptions = options;
                    r = i;
                    c = j;
                }
            }
        }
    }
    if (r == -1)
        return true;
    int b = (r / 3) * 3 + c / 3;
    int mask = ~(rowMask[r] | colMask[c] | boxMask[b]) & 0x3FE;
    while (mask)
    {
        int bit = mask & -mask;
        mask ^= bit;
        int num = __builtin_ctz(bit);
        board[r][c] = '0' + num;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;
        if (solveOptimal())
            return true;
        rowMask[r] ^= bit;
        colMask[c] ^= bit;
        boxMask[b] ^= bit;
        board[r][c] = '.';
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vector<vector<char>> board =
    //     {
    //         {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // solve(board);

    // for (auto &row : board)
    // {
    //     for (char c : row)
    //         cout << c << " ";
    //     cout << "\n";
    // }
    board =
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0';
                int bit = 1 << num;
                int b = (i / 3) * 3 + j / 3;
                rowMask[i] |= bit;
                colMask[j] |= bit;
                boxMask[b] |= bit;
            }
    solveOptimal();
    for (auto &row : board)
    {
        for (char c : row)
            cout << c << " ";
        cout << "\n";
    }
    return 0;
}