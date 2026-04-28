// Floor in BST
// the floor of a given value key in a BST is the largest value that is less than or equal to the key

// idea ->
// while traversing the BST:
//  if root->data == key -> floor found
//  if key < root->data -> move left
//  if key > root->data -> store current node as possible floor, move right

// example ->
//         20
//        /  \
//      10    30
//     / \    / \
//    5  15  25  35
// find floor of 17
// steps:
//  17 < 20 -> go left
//  17 > 10 -> store 10
//  17 > 15 -> store 15
//  no more nodes -> floor = 15

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

// iterative approach
int floorBST (Node *root, int key) {
    int floor = -1;
    while (root != NULL) {
        if (root->data == key)
            return root->data;
        if (key < root->data)
            root = root->left;
        else {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

// recursive approach
int floorBSTRecursive (Node *root, int key) {
    if (root == NULL)
        return -1;
    if (root->data == key)
        return root->data;
    if (key < root->data)
        return floorBSTRecursive(root->left, key);
    int val = floorBSTRecursive(root->right, key);
    if (val <= key && val != -1)
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