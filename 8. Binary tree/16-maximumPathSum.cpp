// Maximum path sum
// find the maximum path sum of any path in a binary tree
// a path:
//  can start and end at any node
//  must be continuous (parent-child connections)
//  can go left -> node -> right
// example ->
//     -10
//     /  \
//    9    20
//        /  \
//       15   7
// best path: 15 -> 20 -> 7
// sum = 42

// at each node, there are two choices:
//  case 1 (return to parent)
//      only one side allowed:  node + max(left, right)
//  case 2 (answer candidate)
//      take both sides: left + node + right

// formula ->
// ignore negative contributions:
// f(node) = node.val + max(0, f(left), f(right))
// and update global answer:
// maxSum == max(maxSum, left + node.val + right)

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

int solve (Node *root, int &maxSum) {
    if (!root)
        return 0;
    int left = max(0, solve(root->left, maxSum));
    int right = max(0, solve(root->right, maxSum));
    // case 2: update answer
    maxSum = max(maxSum, left + right + root->data);
    // case 1: return one side
    return root->data + max(left, right);
}

int maxPathSum (Node* root) {
    int maxSum = INT32_MIN;
    solve(root, maxSum);
    return maxSum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}