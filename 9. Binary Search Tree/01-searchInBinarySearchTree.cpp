// Search in binary search tree
// searching in a binary search tree (BST) is efficient because it follows a specific rule:
//  all values in the left subtree are smaller than the root
//  all values in the right subtree are greater than the root

// searching algorithm ->
// given a value key:
//  start at the root
//  if key == root.value -> found
//  if key < root.value -> search in the left subtree
//  if key > root.value -> search in the right subtree
//  repeat until found or node becomes NULL

// example ->
// suppose we search for 50:
//     40
//    /  \
//  20    60
//        / \
//      50   70
// steps:
//  50 > 40 -> go right
//  50 < 60 -> go left
//  50 == 50 -> found

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

Node *search (Node *root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}