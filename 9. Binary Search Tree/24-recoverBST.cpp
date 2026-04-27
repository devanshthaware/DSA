// Recover BST
// two nodes in bst are swapped by mistake
// recover the tree without cchanging its structure

// in a correct bst, inorder traversal is sorted

// types of swaps
// case1 -> non-adjacent swap
// original: 123456
// swapped: 153426
// case2 -> adjacent swap
// original: 1234
// swapped: 1324

// variables used
// prev -> previous node in inorder
// first -> first wrong node
// middle -> node after first violation
// last -> second wrong node (if exists)

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

class Solution {
private:
    TreeNode *first = NULL;
    TreeNode *middle = NULL;
    TreeNode *last = NULL;
    TreeNode *prev = NULL;
    void inorder (TreeNode* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        // violation
        if (prev && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree (TreeNode *root) {
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}