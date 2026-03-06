// N-Queens Problem
// you have an NxN chessboard
// you need to place N queens on the board
// constraints -> no two queens can attack each other
//   that means-> no two queens on the same row
//                no two queens on the same column
//                no two queens on the same diagonal
// input -> integer n (size of board)
// output -> all possible ways to place N queens safely, as board arrangements
// example for n = 4 ->
//                      . Q . .
//                      . . . Q
//                      Q . . .
//                      . . Q .

#include <bits/stdc++.h>
using namespace std;

// approach 1 -> backtracking
// place queens row by row
// for each row, try all columns
// before placing, check if its safe (no threats from earlier rows)
// if safe -> place queen -> recurse to next row
// if no safe positions -> backtrack (remove queen, try next position)
// if you reach row n -> one valid solution
// checking isSafe condition:
//  at position (row, col):
//      check same column upwards
//      check upper left diagonal
//      check upper right diagonal
//  we only check upwards because we're filling row by row top-down
// initialize the board:
//  we use 2D vector<string>:
//      each row -> a string like ". Q . ."
//      '.' -> empty, 'Q' -> queen
bool isSafe(int row, int col, vector<string> &board, int n)
{ // check if placing a queen at board[row][col] isSafe
    // check same column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;
    // check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    // check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
void solve(int row, vector<string> &board, vector<vector<string>> &result, int n)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(row + 1, board, result, n);
            board[row][col] = '.'; // backtrack
        }
    }
}
// time complexity: right upper bound -> O(n!) because at each row we try up to n choices
// actual time -> much better due to pruning from isSafe

// approach 2 -> optimized N-Queens using bitmasking
// why? -> the regular backtracking solution checks:
//          is the column safe?
//          is the left diagonal safe?
//          is the right diagonal safe?
// but with bitmasks, we can track:
//      columns -> with an integer
//      left diagonals -> with an integer
//      right diagonals -> with an integer
// this avoids scanning arrays and makes everything O(1):
// optimized approach ->
// we use: column -> bitmask for columns
//         diagonal 1 -> bitmask for (row + col)
//         diagonal 2 -> bbitmask for (row - col + n - 1)
// at each step:
//      check if the current position is safe by masking
//      place the queen (set the bit)
//      backtrack (unset the bit)
int totalSolutions = 0;
void solveOptimal(int n, int row, int columns, int diagonal1, int diagonal2)
{
    if (row == n)
    {
        totalSolutions++;
        return;
    }

    int available = ((1 << n) - 1) & ~(columns | diagonal1 | diagonal2);

    while (available)
    {
        int pos = available & -available; // get the rightmost 1 bit
        available &= (available - 1); // remove the rightmost 1bit

        solveOptimal(n, row + 1,
                     columns | pos,
                     (diagonal1 | pos) << 1,
                     (diagonal2 | pos) >> 1);
    }
}
// time complexity: this method is ultrs fast, especially for n <= 15, beccause bit operations are lightning quick

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int n = 4;
    // vector<vector<string>> result;
    // vector<string> board(n, string(n, '.'));
    // solve(0, board, result, n);
    // for (auto &solution : result)
    // {
    //     for (auto &row : solution)
    //         cout << row << "\n";
    //     cout << "\n";
    // }
    // cout << "Total solutions: " << result.size() << "\n";

    int n = 8;
    solveOptimal(n, 0, 0, 0, 0);
    cout << totalSolutions;
    return 0;
}