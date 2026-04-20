// Root to leaf paths
// a root to leaf path is a path that starts from the root node and ends at a leaf node
// a leaf node is a node with:
//  no left child AND no right child

// example ->
//     1
//    / \
//   2   3
//    \
//     5
// root to leaf paths
// 1->2->5
// 1->3
// output:
// [
//     "1->2->5",
//     "1->3"
// ]

// idea ->
// use dfs with recursion
// add current node to path
// if leaf node -> store path
// recurse left
// recurse right
// backtrack

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

void dfs (Node *root, vector<int> &path, vector<vector<int>> &result) {
    if (!root)
        return;
    // add current node
    path.push_back(root->data);
    // if leaf node
    if (root->left == NULL &&
        root->right == NULL) {
        result.push_back(path);
    }
    else {
        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }
    // backtrack
    path.pop_back();
}

vector<vector<int>> rootToLeafPaths (Node *root) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(root, path, result);
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}