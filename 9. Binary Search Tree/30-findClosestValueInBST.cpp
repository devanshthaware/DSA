// Find closest value in bst
// give a bst and a target value, find the node value that is closest to the target

// idea ->
// keep updating the closest value based on the minimum absolute difference: min|node - target|
// because its a bst, we move:
//  if target < node -> go LEFT
//  if target > node -> go RIGHT

// example ->
//     8
//    / \
//   5   10
//  / \    \
// 2   6    14
// target: 7
// check path: 8 -> 5 -> 6
// closest value: 6

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int data) {
        val = data;
        left = right = NULL;
    }
};

// iterative approach
int closestValue (TreeNode *root, double target) {
    int closest = root->val;
    while (root != NULL) {
        if (abs(root->val - target) < abs(closest - target))
            closest = root->val;
        if (target < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return closest;
}

// recursive approach
int closestValue (TreeNode *root, double target) {
    if (root == NULL)
        return INT32_MAX;
    int closest = root->val;
    if (target < root->val && root->left) {
        int left = closestValue(root->left, target);
        if (abs(left - target) < abs(closest - target))
            closest = left;
    }
    else if (target > root->val && root->right) {
        int right = closestValue(root->right, target);
        if (abs(right - target) < abs(closest - target))
            closest = right;
    }
    return closest;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}