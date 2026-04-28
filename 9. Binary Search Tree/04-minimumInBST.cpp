// Find minimum in binary search tree
// in a NST, the minimum value is always located at the leftmost node
// rule: keep moving to the leeft child until NULL is reached
// example ->
//         50
//        /  \
//      30    70
//      /
//    20
//   /
// 10   <- Minimum
// steps:
//  start at 50
//  move left -> 30
//  move left -> 20
//  move left -> 10
//  no more left -> minimum found

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
Node *findMin (Node *root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

// recursive approach
Node *findMinRecursive (Node *root) {
    if (root == NULL || root->left == NULL)
        return root;
    return findMinRecursive(root->left);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}