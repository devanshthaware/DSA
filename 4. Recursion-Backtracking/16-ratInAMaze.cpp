// Rat in a Maze
// Rat in a Maze is a classic backtracking + grid traversal problem.
// Goal: find all possible paths from the top-left corner (0,0) to the bottom-right corner (n-1,n-1) in a maze.
// The rat can move only through cells containing 1 (open path).
// Cells with 0 are blocked.

// Example grid:
//              1 0 0 0
//              1 1 0 1
//              1 1 0 0
//              0 1 1 1
// Valid path example:
//  (0,0) → (1,0) → (2,0) → (2,1) → (3,1) → (3,2) → (3,3)
// Allowed Moves
// Typically four directions:
// D = Down
// L = Left
// R = Right
// U = Up
// Competitive programming problems usually require returning the path string.
// Example:
//      DDRDRR

#include <bits/stdc++.h>
using namespace std;

// Use Backtracking (DFS).
// Steps:
//  Start from (0,0)
//  Try all possible directions
//  If cell is valid and not visited
//  Move forward
//  Recursively explore
//  Backtrack if stuck
// Valid Cell Conditions
// A cell is valid if:
//      x >= 0
//      y >= 0
//      x < n
//      y < n
//      maze[x][y] == 1
//      not visited
void solve(int x, int y,
           vector<vector<int>> &maze,
           int n,
           vector<string> &ans,
           string path,
           vector<vector<int>> &vis)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // Down
    if (x + 1 < n && !vis[x + 1][y] && maze[x + 1][y] == 1)
    {
        vis[x][y] = 1;
        solve(x + 1, y, maze, n, ans, path + 'D', vis);
        vis[x][y] = 0;
    }
    // Left
    if (y - 1 >= 0 && !vis[x][y - 1] && maze[x][y - 1] == 1)
    {
        vis[x][y] = 1;
        solve(x, y - 1, maze, n, ans, path + 'L', vis);
        vis[x][y] = 0;
    }
    // Right
    if (y + 1 < n && !vis[x][y + 1] && maze[x][y + 1] == 1)
    {
        vis[x][y] = 1;
        solve(x, y + 1, maze, n, ans, path + 'R', vis);
        vis[x][y] = 0;
    }
    // Up
    if (x - 1 >= 0 && !vis[x - 1][y] && maze[x - 1][y] == 1)
    {
        vis[x][y] = 1;
        solve(x - 1, y, maze, n, ans, path + 'U', vis);
        vis[x][y] = 0;
    }
}
vector<string> findPath(vector<vector<int>> &maze, int n)
{
    vector<string> ans;
    if (maze[0][0] == 0)
        return ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    solve(0, 0, maze, n, ans, "", vis);
    return ans;
}
// Time Complexity -> O(4^(n²))
// Because from each cell we can try 4 directions.
// But pruning makes it much faster in practice.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> maze =
        {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {0, 1, 1, 1}};
    int n = maze.size();
    vector<string> paths = findPath(maze, n);
    for (auto &p : paths)
        cout << p << endl;
    return 0;
}