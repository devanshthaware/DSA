// Maximum depth of binary tree
// the maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node
// maximum depth = height of binary tree
// example ->
//               1
//              / \
//             2   3
//            /
//           4
// longest path: 1->2->4
// maximum depth = 3

// formula ->
// calculate depth using recursion:
//  d(root) = 1 + max(d(left), d(right))
// base case: if node is NULL, depth = 0

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

// recursive approach
int maxDepth (Node *root) {
    if (root = NULL)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

// iterative approach
// count number of levels
// each level increases depth by 1
int maxDepth (Node *root) {
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty()) {
        int size = q.size();
        depth++;
        while (size--) {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return depth;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}