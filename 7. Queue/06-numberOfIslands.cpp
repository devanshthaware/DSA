// Number of islands
// you are given a 2d grid of '1' (land) and '0' (water)
// count the number of islands
// an island is formed by connecting adjacent lands:
//  horizontally
//  vertically
//  not diagonally
// example -> grid:
//      1 1 0 0 0
//      1 1 0 0 0
//      0 0 1 0 0
//      0 0 0 1 1
//  output: 3
//  because there are 3 separate islands

// idea ->
// treat each land cell '1' as a node in a graph
// algorithm ->
//  traverse every cell
//  if cell is '1':
//      increament island count
//      run dfs/bfs to mark eentire island visited

#include <bits/stdc++.h>
using namespace std;

int numIsLands(vector<vector<char>> &grid) {
    if (grid.empty())
        return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
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
                            grid[r][c] == '1'
                        ) {
                            q.push({r, c});
                            grid[r][c] = '0';
                        }
                    }
                }
            }
        }
    }
    return count;
}

// dry run
// start scanning grid
// found '1' -> island 1
// dfs marks entire connected land
// continue scanning
// found next '1' -> island 2
// dfs marks it
// repeat

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}