// Convert BST to doubly linked list
// nodes are in sorted order
// use inorder traversal
// left pointer -> previous
// right pointer -> previous
// often required to be in-place

// core ordering property
// because inorder traversal of a bsst produces sorted order
// left -> root -> right
// we link nodes dduring traversal to form the doubly linked list

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
public:
    TreeNode *prev = NULL;
    TreeNode *head = NULL;
    void inorder (TreeNode *root) {
        if (root == NULL)
            return;
        inorder(root->left);
        // first node becomes head
        if (prev == NULL)
            head = root;
        else {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        inorder(root->right);
    }
    TreeNode *bstToDLL (TreeNode *root) {
        inorder(root);
        return head;
    }
    // circular dll
    // some problem requires:
    //  head.left = tail
    //  tail.right = head
    TreeNode *bstToCircularDLL (TreeNode *root) {
        inorder(root);
        // make circular
        head->left = prev;
        prev->right = head;
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}