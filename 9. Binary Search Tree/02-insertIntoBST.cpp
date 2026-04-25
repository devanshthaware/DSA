// Insert into BST
// insertion in a binary search tree (BST) follows the same rule as searching:
//  left subtree -> value smaller than the node
//  right subtree -> values greater than the node

// insertion algorithm
// to insert a vlue key:
//  start from the root
//  if the tree is empty -> create a new node as root
//  if key < node.data -> go to the left child
//  if key > node.data -> go to the right child
//  repeat until you find a NULL position
//  insert the new node there

// example ->
// insert 65 into the BST:
// Before insertion:
//         50
//        /  \
//      30    70
//            /
//          60
// After insertion (65):
//         50
//        /  \
//      30    70
//            /
//          60
//            \
//             65

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

Node *insert (Node *root, int key) {
    if (root == NULL)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// iterative approach
Node *insertIterative (Node *root, int key) {
    Node *newNode = new Node(key);
    if (root == NULL)
        return newNode;
    Node *parent = NULL;
    Node *curr = root;
    while (curr != NULL) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else if (key > curr->data)
            curr = curr->right;
    }
    if (key < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}