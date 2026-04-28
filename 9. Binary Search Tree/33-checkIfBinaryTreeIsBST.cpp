// Check if binary tree is a BST
// determine whether a given binary tree satisfies the bst property

// core bst rule
// a tree is a bst if every node satisfies:
// min < node < max
// all values in the left subtree are smaller
// all values in the right subtree are greater
// this rule must hold recursively for every node

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

// approach 1 optimal - using min/max range
// pass a vaalid range (min, max) to each node and verify the value lies within it
bool validate (TreeNode *root, long minVal, long maxVal) {
    if (root == NULL)
        return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return validate(root->left, minVal, root->val) &&
           validate(root->right, root->val, maxVal);
}
bool isValidBST (TreeNode *root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

// approach 2 - inorder traversal
// inorder traversal of bst must be strictly increasing
// keep track of previous node
class Solution {
public:
    TreeNode *prevNode = NULL;
    bool inorder (TreeNode *root) {
        if (root == NULL)
            return true;
        if (!inorder(root->left))
            return false;
        if (prevNode && root->val <= prevNode->val)
            return false;
        prevNode = root;
        return inorder(root->right);
    }
    bool isValidBSTInorder (TreeNode *root) {
        prevNode = NULL;
        return inorder(root);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
