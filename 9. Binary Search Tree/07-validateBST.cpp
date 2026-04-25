// Validate BST
// goal: check whether a binary tree satisfies the BST properly:
//  all nodes in the left subtree are less than the node
//  all nodes in the right subtree are greater than the node
//  this rule must hold for every node in the tree

// idea ->
// validate a BST by maintaining a range (min, max) for each node
//  left child -> range becomes (min, node.data)
//  right child -> range becomes (node.data, max)
// if any node violates the range -> not a BST

// example -> valid BST
//         50
//        /  \
//      30    70
//     / \    / \
//    20 40  60 80
// this tree satisfies all BST rules -> valid BST

// example -> invalid BST
//     50
//    /  \
//  30    70
//       /
//     40
// here 40 is in the right subtree of 50 but is less than 50, so its not a BST

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

bool validate (Node *root, long minVal, long maxVal) {
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return validate(root->left, minVal, root->data) &&
           validate(root->right, root->data, maxVal);
}

bool isValidateBST (Node *root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}