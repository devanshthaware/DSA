// Height of Binary Tree
// the height of binary tree is the number of nodes on the longest path from the root to a leaf node
// number of edges on the longest path from root to leaf

// example ->
//               1
//              / \
//             2   3
//            /
//           4
// height
//  longest path: 1 -> 2 -> 4
//  height = 3 nodes
//  or height = 2 edges
// height is usually counted in nodes

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

// formula / recurrence relation
// we compute height using recursion:
//  h(root) = 1 + max(h(left), h(right))
// base case: if the node is NULL, height = 0
int height (Node *root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// height using level order traversal
int height(Node *root) {
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        height++;
        while (size--) {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return height;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

