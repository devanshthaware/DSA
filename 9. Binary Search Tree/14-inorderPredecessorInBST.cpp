// Inorder predecessor in bst
// the inorder predecessor of a node is the previous node in inorder traversal (left->root->right), i.e., the largest value smaller than the given node

// cases ->
// case 1 -> Node has a left subtree
// predecessor = maximum value in the left subtree
//     50
//    /  \
//  30    70
//    \
//     40
// find predecessor of 50
// left subtree exists -> go left -> find maximum predecessor = 40

// case 2 -> node has no left subtree
// predecessor = lowest ancestor for which node lies in its right subtree
//         50
//        /  \
//      30    70
//     /
//    20
// find predecessor of 20
// move up until node is right child
// predecessor = NULL (no smaller value)

// algorithm ->
// start from root
// if key > root->data
//  store root as potential predecessor
//  move right
// else
//  move left
// continue until traversal ends

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
Node *inorderPredeceessor (Node *root, Node *p) {
    Node *predecessor = NULL;
    while (root != NULL) {
        if (p->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return predecessor;
}

// when node has left child
Node *findMax (Node *root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node *inorderPredeceessorLC (Node *node) {
    if (node->left != NULL)
        return findMax(node->left);
    return NULL;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}