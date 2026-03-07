// Knight’s Tour
// The Knight’s Tour is a classic backtracking problem on a chessboard
// A knight must visit every square of the board exactly once
// In chess, a knight moves in 8 possible ways
// The knight moves in L-shape:
//      (±2, ±1)
//      (±1, ±2)
// Total 8 possible moves.
// Problem Statement
//      Given an N × N chessboard:
//          Start from (0,0)
//          Move the knight so that it visits every square exactly once
// Return the board showing the order of moves.
// Example (5×5):
// 0  5 14  9 20
// 13 8 19  4 15
// 18 1  6 21 10
// 7 12 23 16  3
// 24 17  2 11 22

#include <bits/stdc++.h>
using namespace std;

// approach -> 
// Use Backtracking.
// Algorithm:
//      Place knight at (0,0)
//      Try all 8 moves
//      If move is valid and not visited
//      Mark move number
//      Recurse
//      If stuck -> backtrack
// Move Arrays
// xMove = {2,1,-1,-2,-2,-1,1,2}
// yMove = {1,2,2,1,-1,-2,-2,-1}
// These represent the 8 knight directions
const int N = 8;
int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isSafe(int x, int y, vector<vector<int>> &board)
{
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}
bool solve(int x, int y, int moveCount, vector<vector<int>> &board)
{
    if (moveCount == N * N)
        return true;
    for (int k = 0; k < 8; k++)
    {
        int nextX = x + xMove[k];
        int nextY = y + yMove[k];
        if (isSafe(nextX, nextY, board))
        {
            board[nextX][nextY] = moveCount;
            if (solve(nextX, nextY, moveCount + 1, board))
                return true;
            board[nextX][nextY] = -1; // backtrack
        }
    }
    return false;
}
// Time Complexity: O(8 ^ (N^2))
// Very large search space.
// That is why naive backtracking is slow for large boards

// optimal approach -> (Warnsdorff's Algorithm) - O(N^2)
// The optimal practical solution to the Knight’s Tour uses a heuristic called Warnsdorff's Rule.
// Instead of blindly exploring all moves (backtracking), we always move to the square that has minimum onward moves.
// This dramatically reduces the search space.
// Warnsdorff's Rule
// Rule:
// Always move the knight to the square with the fewest valid next moves.
// Why this works:
// Squares with fewer options are more restrictive
// If we delay visiting them, they may become unreachable later
// So we visit them early.
// This removes most backtracking.
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isValid(int x, int y, int N, vector<vector<int>> &board)
{
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}
int countMoves(int x, int y, int N, vector<vector<int>> &board)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, N, board))
            count++;
    }
    return count;
}
bool knightsTour(int x, int y, int move, int N, vector<vector<int>> &board)
{
    if (move == N * N)
        return true;
    vector<pair<int, pair<int, int>>> nextMoves;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, N, board))
        {
            int degree = countMoves(nx, ny, N, board);
            nextMoves.push_back({degree, {nx, ny}});
        }
    }
    sort(nextMoves.begin(), nextMoves.end());
    for (auto &m : nextMoves)
    {
        int nx = m.second.first;
        int ny = m.second.second;
        board[nx][ny] = move;
        if (knightsTour(nx, ny, move + 1, N, board))
            return true;
        board[nx][ny] = -1;
    }
    return false;
}
// Why Competitive Programmers Use This ->
//  Because it converts an exponential search problem into a greedy heuristic traversal.
//  This is a common trick in competitive programming:
//      Backtracking + Heuristic = Fast Solution

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vector<vector<int>> board(N, vector<int>(N, -1));
    // board[0][0] = 0;
    // if (solve(0, 0, 1, board))
    // {
    //     for (auto &row : board)
    //     {
    //         for (int x : row)
    //             cout << setw(2) << x << " ";
    //         cout << "\n";
    //     }
    // }
    // else
    //     cout << "No solution";

    int N = 8;
    vector<vector<int>> board(N, vector<int>(N, -1));
    board[0][0] = 0;
    if (knightsTour(0, 0, 1, N, board))
    {
        for (auto &row : board)
        {
            for (int x : row)
                cout << setw(2) << x << " ";
            cout << "\n";
        }
    }
    else
        cout << "No solution";
    return 0;
}