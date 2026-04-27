// Ceil in BST
// the ceil of a gven value key in a bst is the smallest value that is greater than or equal to the key

// idea ->
// while traversing the BST:
//  if root->data == key -> ceil found
//  if key > root->data -> move rightt
//  if key < root->data -> store current node as possible ceil, move left

// example ->
//         20
//        /  \
//      10    30
//     / \    / \
//    5  15  25  35
// find ceil of 17
// steps:
//  17 < 20 -> store 20
//  17 > 10 -> move right
//  17 > 15 -> move right
//  no more nodes -> ceil = 20

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

int ceilBST (Node *root, int key) {
    int ceil = -1;
    while (root != NULL) {
        if (root->data == key)
            return root->data;
        if (key > root->data)
            root = root->right;
        else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

// recursive approach
int ceilBST (Node *root, int key) {
    if (root == NULL)
        return -1;
    if (root->data == key)
        return root->data;
    if (key > root->data)
        return ceilBST(root->right, key);
    int val = ceilBST(root->left, key);
    if (val >= key && val != -1)
        return val;
    else
        return root->data;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}