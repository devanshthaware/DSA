// Check if binary tree is balanced
// a binary tree is balanced if the height difference between the left and right subtree of every node is not more than 1

// balanced condition
// |h(left) - h(right)| <= 1
// if the condition is true for all nodes, the tree is balanced

// example -> balanced tree
//               1
//              / \
//             2   3
//            / \
//           4   5

// height difference at every node:
//      <= 1
// result: balanced

// example -> Unbalanced tree
//               1
//              /
//             2
//            /
//           3
// height difference:
//  left height = 2
//  right height = 0
//  difference = 2
// result: Not balanced

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

// optimal approach - O(N) [N = number of nodes]
// instead of calculating height repeatedly, we:
//  compute height
//  check balance simultaneously
//  return -1 if unnbalanced
// this makes it O(N)
int checkHeight (Node* root) {
    if (root == NULL)
        return 0;
    int left = checkHeight(root->left);
    if (left == -1)
        return -1;
    int right = checkHeight(root->right);
    if (right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return 1 + max(left, right);
}
bool isBalanced(Node *root) {
    return checkHeight(root) != -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}