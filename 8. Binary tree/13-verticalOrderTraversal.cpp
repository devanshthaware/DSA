// Vertical order traversal
// vertical order traversal groups nodes based on their horizontal distance (HD) from the root
//  root has HD = 0
//  left child -> HD - 1
//  right child -> HD + 1
// Nodes with the same horizontal distance are printed in the same vertical line
// example ->
//         1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7
// horizontal distance assignment
//  HD -2 -> 4
//  HD -1 -> 2
//  HD 0 -> 1 5 6
//  HD +1 -> 3
//  HD +2 -> 7
// vertical order output ->
// [
//     [4],
//     [2],
//     [ 1, 5, 6 ],
//     [3],
//     [7]
// ]

// idea ->
//  queue -> for BFS (level order)
//  map -> to store nodes by hoizontal distance
//      queue stores: (Node, HD)
//      Map stores: HD -> lest of nodes

// algorithm ->
// create queue of pair (node, horizontal distance)
// push root with HD = 0
// while queue not empty:
//  pop node
//  store node value in map[HD]
//  push left child with HD - 1
//  push right child with HD + 1
// print map in sorted order of HD

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> verticalOrder (Node *root) {
    vector<vector<int>> result;
    if (!root)
        return result;
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        Node *node = front.first;
        int hd = front.second;
        mp[hd].push_back(node->data);
        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }
    for (auto it : mp) {
        result.push_back(it.second);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}