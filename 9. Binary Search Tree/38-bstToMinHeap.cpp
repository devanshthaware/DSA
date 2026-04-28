// Convert bst to min heap
// convert a bst into a minn heap while keeping the same tree

// bst property -> left < root < right
// min heap property -> parent <= children

// idea ->
// perform inorder traversal -> store values in sorted array
// perform preorder taversal -> assign values from array
// why this works:
//  inorder of bst -> sorted values
//  preorder assignment ensures parent is filled before children
//  that guarantees min heap property

// example ->
//     4
//    / \
//   2   6
//  / \ / \
// 1  3 5  7
// inorder sorted: [1 2 3 4 5 6 7]
// after conversion (Min heap)
//     1
//    / \
//   2   5
//  / \ / \
// 3  4 6  7

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

void preorderFill (TreeNode *root, vector<int> &arr, int &index) {
    if (root == NULL)
        return;
    root->val = arr[index++];
    preorderFill(root->left, arr, index);
    preorderFill(root->right, arr, index);
}

void convertBSTtoMinHeap (TreeNode *root) {
    vector<int> arr;
    // step 1: store sorted values
    inorder(root, arr);
    int index = 0;
    // step 2: fill values in preorder
    preorderFill(root, arr, index);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}