// Find height of BST
// the height of a tree is the number of edges in the longest path from the root to a leaf node

// example ->
//     10
//    /  \
//   5    20
//  / \
// 3   7
// longest path: 10 -> 5 -> 3
// height (in edges) = 2
// height (in nodes) = 3

// formula -> height = 1 + max(height(left), height(right))
// base case:
// if root == NULL -> height = -1 (for edges)
// if root == NULL -> height = 0 (for edges)

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

// height in edges
int height (Node *root) {
    if (root == NULL)
        return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// height in nodes
int heightNodes (Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// iterative approach
int heightIterative (Node *root) {
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        height++;
    }
    return height;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}