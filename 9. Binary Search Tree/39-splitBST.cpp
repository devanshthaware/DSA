// Split bst
// given a bst and a value target, split the tree into two BSTs:
//  tree 1: all nodes with values <= target
//  tree 2: all nodes with values > target
// both resulting trees must still be valid BSTs

// split condition
// we divide nodes based on:
// node <= target | node > target

// idea ->
// at each node:
// if node <= target:
//  split right subtree
//  attach left part back to node->right
//  node goes to left tree
// if node > target:
//  split left subtree
//  attach right part back to node->left
//  node goes to right tree
// we return two roots

// example ->
// original bst
//     4
//    / \
//   2   6
//  / \ / \
// 1  3 5  7
// target = 2
// result ->
// tree 1 (<=2)
//   2
//  /
// 1
// tree 2 (>2)
//     4
//    / \
//   3   6
//      / \
//     5   7

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int data) {
        val = data;
        left = right = NULL;
    }
};

pair<TreeNode *, TreeNode *> splitBST (TreeNode *root, int target) {
    if (root == NULL)
        return {NULL, NULL};
    // Node belongs to left tree
    if (root->val <= target) {
        auto rightSplit = splitBST(root->right, target);
        root->right = rightSplit.first;
        return {root, rightSplit.second};
    }
    // node belongs to right tree
    else {
        auto leftSplit = splitBST(root->left, target);
        root->left = leftSplit.second;
        return {leftSplit.first, root};
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}