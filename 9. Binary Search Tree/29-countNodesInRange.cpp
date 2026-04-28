// Count nodes in range (bst)
// given a bst and a range [low, high], count how many nodes lie within that range

// condtion for counting
// we count nodes that satisfy: low <= node <= high

// because its a bst, we can skip unnecessary subtrees:
// if node < low -> ignore left subtree
// if node > high -> ignore right subtree
// else -> count node and check both sides

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

int countNodeInRange (TreeNode *root, int low, int high) {
    if (root == NULL)
        return 0;
    // Node too small
    if (root->val < low)
        return countNodeInRange(root->right, low, high);
    // Node too large
    if (root->val > high)
        return countNodeInRange(root->left, low, high);
    // Node in range
    return 1 +
           countNodeInRange(root->left, low, high) + countNodeInRange(root->right, low, high);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}