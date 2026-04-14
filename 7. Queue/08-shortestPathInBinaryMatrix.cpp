// shortest path in binary matrix
// given an n * n binary matrix:
//  0 -> open cell
//  1 -> blocked cell
// find the shortest path form:
//  top-left -> bottom-right
//  (0, 0) -> (n - 1, n - 1)
// movement is allowed in 8 directions:
//  up, down, left, right, and 4 diagonals
// return
//  length of shortest path
//  -1 if no path exists
// example ->
//  grid:
//      0 1
//      1 0
// output: 2
// path: (0, 0) -> (1, 1)

// idea -> bfs on grid
// why bfs? -> bfs always find the shortest path in an unweighted graph
// each move costs: 1 step

// algorithm ->
// if start or end is blocked -> return -1
// push (0, 0) into queue
// while queue not empty:
//  pop cell
//  if destination reched -> return distance
//  explore 8 directions
// if queue empty -> return -1

// direction movement:
//  (-1, -1) (-1, 0) (-1, 1)
//  (0, -1)   cell   (0, 1)
//  (1, -1)  (1, 0)  (1, 1)

#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix (vector<vector<int>> &grid) {
    int n = grid.size();
    // step 1: check start/end
    if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    // mark visited
    grid[0][0] = 1;
    int pathLenght = 1;
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    // bfs
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto cell = q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second;
            // destination reached
            if (r == n - 1 && c == n - 1)
                return pathLenght;
            for (auto dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 &&
                    nc >= 0 &&
                    nr < n &&
                    nc < n &&
                    grid[nr][nc] == 0
                ) {
                    q.push({nr, nc});
                    grid[nr][nc] = 1; // mark visited
                }
            }
        }
        pathLenght++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}};
    cout << shortestPathBinaryMatrix(grid);
    return 0;
}