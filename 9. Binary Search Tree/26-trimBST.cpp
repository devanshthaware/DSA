// Trim BST
// given a bst and a range [low, high], remove all nodes whose values are outside the range, while keeping the bst property intact

// condition to keep a node
// keep nodes that satisfy: low <= node <= high

// logic ->
// because its a bst, we can skip entire subtrees:
// if node < low -> discard left subtree, go right
// if node > high -> discard right subtree, go left
// else -> keep node and trim both sides

// example ->
// original bst
//     3
//    / \
//   0   4
//    \
//     2
//    /
//   1
// low = 1, high = 3
// trimmed bst
//     3
//    /
//   2
//  /
// 1
// nodes 0 and 4 are removed

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

TreeNode *trimBST (TreeNode *root, int low, int high) {
    if (root == NULL)
        return NULL;
    // Node too small
    if (root->val < low)
        return trimBST(root->right, low, high);
    // Node too large
    if (root->val > high)
        return trimBST(root->left, low, high);
    // Node in range
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}