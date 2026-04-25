// Diameter of binary tree
// the diameter of a binary tree is the length of the longest path between any two nodes in the tree
// the path may or may not pass through the root
// diameter is usually measured in number of edges (most common interviews)
// example ->
//               1
//              / \
//             2   3
//            / \
//           4   5
// longest path: 4->2->1->3
// diameter = 3 edges

// at every node:
//  find left subtree height
//  find right subtree height
//  diameter through that node = left height + right height
//  we compute height and diameter together

// formula -> D(node) = max(h(left) + h(right), D(left), D(right))
// where:
//  h(left) = height of right subtree
//  h(right) = height o right subtree
//  D(node) = diameter at current node

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

// optimal approach
int diameterUtil (Node *root, int &height) {
    if (root == NULL) {
        height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int leftDiameter = diameterUtil(root->left, lh);
    int rightDiameter = diameterUtil(root->right, rh);
    height = 1 + max(lh, rh);
    int currDiameter = lh + rh;
    return max(currDiameter, max(leftDiameter, rightDiameter));
}
int diameter (Node *root) {
    int height = 0;
    return diameterUtil(root, height);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}