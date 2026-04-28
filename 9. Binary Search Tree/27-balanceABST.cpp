// Balance a BST
// given an unbalanced bst, convert it into a balanced bst (height difference between left and right subtrees <= 1)

// balance condition
// a bst is balancced when:
// |height(left) - height(right)| <= 1

// approach
// inorder -> sorted array -> build balanced bst
// steps:
// perform inorder traversal -> get sorted array
// build bst using middle element as root
// recursively build left and right subtree

// example ->
// unbalanced bst
// 1
//  \
//   2
//    \
//     3
//      \
//       4
// balanced bst
//      2
//     / \
//    1   3
//         \
//          4

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

void inorder (TreeNode *root, vector<int> &arr) {
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

TreeNode *buildBalanced (vector<int> &arr, int left, int right) {
    if (left > right)
        return NULL;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = buildBalanced(arr, left, mid - 1);
    root->right = buildBalanced(arr, mid + 1, right);
    return root;
}

TreeNode *balanceBST (TreeNode *root) {
    vector<int> arr;
    inorder(root, arr);
    return buildBalanced(arr, 0, arr.size() - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}