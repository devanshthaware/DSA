// M-Coloring Problem (Graph Coloring)
// The M-Coloring problem is a classic backtracking problem in graph theory.
// Goal-> Color all vertices of a graph using at most M colors such that no two adjacent vertices have the same color
// Each node gets a color, but adjacent nodes cannot share the same color.
// Example:
//  Vertices = 4
//  Colors = 3
// Valid coloring:
//  1 -> Red
//  2 -> Green
//  3 -> Blue
//  4 -> Red

// Problem Statement ->
//  Given:
//      V vertices
//      adjacency matrix graph[V][V]
//      integer m colors
// Determine if the graph can be colored using at most m colors.

#include <bits/stdc++.h>
using namespace std;

// Use Backtracking.
//  For each vertex:
//  Try all m colors
//  Check if coloring is safe
//  If safe -> assign color
//  Recurse for next vertex
//  If not possible -> backtrack
// Safety Check
//  Color is safe if no adjacent vertex has same color.
//      if(graph[node][i] == 1 AND color[i] == chosenColor)
//          not safe
bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] && color[i] == col)
            return false;
    }
    return true;
}
bool solve(int node, int color[], int m, int n, bool graph[101][101])
{
    if (node == n)
        return true;
    for (int col = 1; col <= m; col++)
    {
        if (isSafe(node, color, graph, n, col))
        {
            color[node] = col;
            if (solve(node + 1, color, m, n, graph))
                return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    int color[n];
    memset(color, 0, sizeof(color));
    return solve(0, color, m, n, graph);
}
// time complexity -> O(m^n)
// Where:
//      m = number of colors
//      n = number of vertices
// Because each vertex can take m choices.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool graph[101][101] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    int m = 3;
    int n = 4;
    if (graphColoring(graph, m, n))
        cout << "Coloring possible";
    else
        cout << "Not possible";
    return 0;
}