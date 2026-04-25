// Boundary traversal
// boundary traversal prints the nodes on the boundary of the binary tree in anti-clockwise direction
// the boundary consists of three parts:
//  left boundary (excluding leaf)
//  leaf nodes
//  right boundary (excluding leaf, printed in reverse)
// example ->
//         1
//       /   \
//      2     3
//     / \   / \
//    4   5 6   7
//       / \
//      8   9
// boundary traversal order -> 1 2 4 8 9 6 7 3

// breakdown:
//  root -> 1
//  left boundary -> 2
//  leaf nodes -> 4 8 9 6 7
//  right boundary -> 3 (reverse)

// algorithm ->
// print root
// traverse left boundary (excluding leaf nodes)
// traverse all leaf nodes
// traverse right boundary (excluding leaf nodes) in reverse

// helper functions needed
//  addLeftBoundary()
//  addLeaves()
//  addRightBoundary()

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

bool isLeaf (Node *node) {
    return (node->left == NULL && node->right == NULL);
}

void addLeftBoundary (Node* root, vector<int> &res) {
    Node *curr = root->left;
    while (curr) {
        if (!isLeaf(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves (Node* root, vector<int> &res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

void addRightBoundary (Node * root, vector<int> &res) {
    Node *curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal (Node* root) {
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}