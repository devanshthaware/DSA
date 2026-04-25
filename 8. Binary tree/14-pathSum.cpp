// Path sum
// path sum checks whether there exists a root-to-leaf path such that the sum of node value equals a target sum
// root -> ... -> leaf
// sum of nodes = target

// example ->
//         5
//        / \
//       4   8
//      /   / \
//     11  13  4
//    /  \       \
//   7    2       1
// target sum: 22
// valid path: 5 -> 4 -> 11 -> 2
//  sum = 22
// result: true

// idea ->
//  subtract node value from target
//  move to left and right child
//  if leaf node reached and remaining sum is 0, return true

// recursive formula ->
// keep reducing the remaining sum along the path
// s(remaining) = s(target) - node.value
// when: Leaf node AND remaining sum = 0
// return: true

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

bool hasPathSum (Node* root, int targetSum) {
    if (root == NULL)
        return false;
    // check leaf node
    if (root->left == NULL && root->right == NULL)
        return targetSum == root->data;
    int remaining = targetSum - root->data;
    return hasPathSum(root->left, remaining) ||
           hasPathSum(root->right, remaining);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}