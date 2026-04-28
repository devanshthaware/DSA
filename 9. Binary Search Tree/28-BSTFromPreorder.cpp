// Contruct bst from preorder traversal
// given the preorder traversal of a bst, construct the original bst
// preorder order: root -> left -> right

// rule: left < root < right
// while building the tree, we maintain a valid value range (min, max) for each node

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

// optimal approach (using bounds)
// read preorder values one by one
// only create node if value fits within (min, max)
// recursively build left and right subtrees
class Solution {
public:
    int index = 0;
    TreeNode *build (vector<int> &preorder, int minVal, int maxVal) {
        if (index >= preorder.size())
            return NULL;
        int val = preorder[index];
        if (val < minVal || val > maxVal)
            return NULL;
        TreeNode *root = new TreeNode(val);
        index++;
        root->left = build(preorder, minVal, val);
        root->right = build(preorder, val, maxVal);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return build(preorder, INT32_MIN, INT32_MAX);
    }
};

// insert method approach
TreeNode *insert(TreeNode *root, int val) {
    if (root == NULL)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
TreeNode *bstFromPreorderInsert (vector<int> &preorder) {
    TreeNode *root = NULL;
    for (int val : preorder)
        root = insert(root, val);
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}