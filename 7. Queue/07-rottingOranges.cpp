// Rotting oranges
// given a grid where:
//  0 -> empty cell
//  1 -> fresh orange
//  2 -> rotten orange
// every minute, any fresh orange adjacent (up, down, left, right) to a orange becomes rotten
// return the minimum time required to rot all oranges
// if impossible, return -1
// example -> grid:
//                  2 1 1
//                  1 1 0
//                  0 1 1
// output: 4

// idea -> (multi-source BFS)
// this is not normal BFS - its multi-source bfs
// why? -> all rotten oranges (2) start spreading infection at the same time

// algorithm ->
//  push all rotten oranges into queue
//  count fresh oranges
//  while queue not empty:
//      process level (1 minutes)
//      spread rot to adjacent fresh oranges
//  if fresh == 0 -> return time
//  else -> return -1

// each level of bfs = 1 minute

#include <bits/stdc++.h>
using namespace std;

int orangesRotting (vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    // step 1: initialize
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                fresh++;
        }
    }
    // if no fresh oranges
    if (fresh == 0)
        return 0;
    int minutes = 0;
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    // step 2: bfs
    while (!q.empty()) {
        int size = q.size();
        bool rottenThisRound = false;
        for (int i = 0; i < size; i++) {
            auto cell = q.front();
            q.pop();
            for (auto dir : directions) {
                int r = cell.first + dir[0];
                int c = cell.second + dir[1];
                if (
                    r >= 0 &&
                    c >= 0 &&
                    r < rows &&
                    c < cols &&
                    grid[r][c] == 1
                ) {
                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                    rottenThisRound = true;
                }
            }
        }
        if (rottenThisRound)
            minutes++;
    }
    // step 3: check result
    return (fresh == 0) ? minutes : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};
    cout << orangesRotting(grid);
    return 0;
}