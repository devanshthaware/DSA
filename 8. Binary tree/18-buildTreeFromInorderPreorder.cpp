// Build tree from inorder + preorder
// preorder -> root comes first
// inorder -> left | root | right

// so the algorithm is ->
// take root from preorder
// find root index in inorder
// left side -> left subtree
// right side -> right subtree
// repeat recursively

// example ->
// preorder = [3, 9, 20, 15, 7]
// inorder = [9, 3, 15, 20, 7]

// step 1 -> root = 3 (first element of preorder)
// split inorder:
//      left -> [9]
//      right -> [15, 20, 7]
// final tree
//     3
//    / \
//   9   20
//      /  \
//     15   7

// algorithm ->
// store inorder index in hashmap
// take root from preorder
// find position in inorder
// recursively build:
//  left subtree
//  right subtree

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

Node *buildTreeHelper(
    vector<int> &preorder,
    int &preIndex,
    int inStart,
    int inEnd,
    unordered_map<int, int> &mp
) {
    if (inStart > inEnd)
        return NULL;
    int rootValue = preorder[preIndex++];
    Node *root = new Node(rootValue);
    int position = mp[rootValue];
    root->left = buildTreeHelper(
        preorder,
        preIndex,
        inStart,
        position - 1,
        mp);
    root->right = buildTreeHelper(
        preorder,
        preIndex,
        position + 1,
        inEnd,
        mp);
    return root;
}

Node *buildTree(
    vector<int> &preorder,
    vector<int> &inorder
) {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }
    int preIndex = 0;
    return buildTreeHelper(
        preorder,
        preIndex,
        0,
        inorder.size() - 1,
        mp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}