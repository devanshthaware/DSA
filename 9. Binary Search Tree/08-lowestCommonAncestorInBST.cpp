// Lowest common ancestor
// the lowest common ancestor (LCA) of two nodes p and q is the lowest node in the tree that has both p and q as descendants

// if both values < root -> go left
// if both values > root -> go right
// otherwise -> current node is the lca
// this makes lca in bstsimpler than in a normal binary tree

// example ->
//         20
//        /  \
//      10    30
//     / \    / \
//    5  15  25  35
// find lca of 5 and 15
// steps:
// 5 < 20 and 15 < 20 -> go left
// now at 10
// 5 < 10 and 15 > 10 -> split occurs
// lca = 10

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

// iterative approach
Node *LCA(Node *root, int p, int q) {
    while (root != NULL) {
        if (p < root->data && q < root->data)
            root = root->left;
        else if (p > root->data && q > root->data)
            root = root->right;
        else
            return root; // this is lca
    }
    return NULL;
}

// recursive approach
Node *LCARecursive (Node *root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (p < root->data && q < root->data)
        return LCARecursive(root->left, p, q);
    if (p > root->data && q > root->data)
        return LCARecursive(root->right, p, q);
    return root; // split point
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}