// Word search
// given a 2D board and a word, return true if the word exists in the grid.
// rules:
//      letters must be adjacent (up, down, left, right)
//      same cell cannot be used twice
//      word must be formed sequentially
// example --> Board:
//                  [
//                      [ 'A', 'B', 'C', 'E' ],
//                      [ 'S', 'F', 'C', 'S' ],
//                      [ 'A', 'D', 'E', 'E' ]
//                  ]
//     word = "ABCCED" → true, word = "SEE" → true, word = "ABCB" → false

#include <bits/stdc++.h>
using namespace std;

// brute force (DFS) - O(4^(m * n))
// generate all possible paths from every cell
// check if any path forms the word
// no visited control -> may revisit same cell -> incorrect or extremely slow
bool dfsBrute(vector<vector<char>> &board, string &word,
         int i, int j, int index)
{
    if (index == word.length())
        return true;
    if (i < 0 || j < 0 ||
        i >= board.size() || j >= board[0].size() ||
        board[i][j] != word[index])
        return false;
    return dfsBrute(board, word, i + 1, j, index + 1) ||
           dfsBrute(board, word, i - 1, j, index + 1) ||
           dfsBrute(board, word, i, j + 1, index + 1) ||
           dfsBrute(board, word, i, j - 1, index + 1);
}

// optimal approach (backtracing DFS) - O(m * n * 4^L) (L->length of word)
// start DFS from every cell
// if character matches -> explore 4 directions
// mark cell as visited
// backtrack (restore cell)
bool dfs(vector<vector<char>> &board, string &word,
         int i, int j, int index)
{
    if (index == word.length())
        return true;
    if (i < 0 || j < 0 ||
        i >= board.size() || j >= board[0].size() ||
        board[i][j] != word[index])
        return false;
    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    bool found = dfs(board, word, i + 1, j, index + 1) ||
                 dfs(board, word, i - 1, j, index + 1) ||
                 dfs(board, word, i, j + 1, index + 1) ||
                 dfs(board, word, i, j - 1, index + 1);

    board[i][j] = temp; // backtrack
    return found;
}
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}