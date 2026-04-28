// Find maximum in bst
// in a BST, the maximum value is always located at the rightmost node
// rule: keep moving to the right child until NULL is reached

// example ->
//     50
//    /  \
//  30    70
//          \
//           90
//             \
//             100   <- Maximum
// steps:
//  starts at 50
//  move right -> 70
//  move right -> 90
//  move right -> 100
//  no more right -> maximum found

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
Node *findMax (Node *root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

// recursive approach
Node *findMaxRecursive (Node *root) {
    if (root == NULL || root->right == NULL)
        return root;
    return findMaxRecursive(root->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}