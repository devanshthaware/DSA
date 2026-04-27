// Inorder Successor in BST
// the inorder successor of a node is the next node inorder traversal (left->root->right), i.e., the smallest value greater than the given node

// cases ->
// case 1: node has a right subtree
// successor = minimum value in the right subtree
//     50
//    /  \
//  30    70
//       /
//      60
// find successor of 50
// right subtree exists -> go rightt -> find minimum successor = 50

// case 2: Node has NO right subtree
// successor = lowest ancestor for which node lies in its left subtree
//     50
//    /  \
//  30    70
//    \
//     40
// find successor of 40
// move up until node is left child successorr = 50

// algorithm ->
// start from root
// if key < root->data
//  store root as potential successor
//  move left
// else
//  move right
// continue until node is found

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

// without parent pointer
Node *inorderSuccessor (Node *root, Node *p) {
    Node *successor = NULL;
    while (root != NULL) {
        if (p->data < root->data) {
            successor = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return successor;
}

// when Node has right child
Node *findMin (Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node *inorderSuccessorRC (Node *node) {
    if (node->right != NULL)
        return findMin(node->right);
    return NULL;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}