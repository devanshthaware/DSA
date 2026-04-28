// Construct BST from postorder traversal
// given the postorder traversal of a bstt, construct the original bst
// postorder order: left -> right -> root
// so the last element in postorder is always the root

// rule ->
// every node must satisfy:
// left < root < right
// we use value bounds (min, max) to eensure nodes are placed correctly

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

// optimal - using bounds
// start from the end of postorder
// create root
// build right subtree first, then left
// use (min, max) bounds to validate placement
// why right first -> because postorder is left -> right -> root, and we are reading it in reverse
class Solution {
public:
    int index;
    TreeNode *build (vector<int> &postorder, int minVal, int maxVal) {
        if (index < 0)
            return NULL;
        int val = postorder[index];
        if (val < minVal || val > maxVal)
            return NULL;
        TreeNode *root = new TreeNode(val);
        index--;
        // build right first
        root->right = build(postorder, val, maxVal);
        root->left = build(postorder, minVal, val);
        return root;
    }
    TreeNode *bstFromPostorder (vector<int> &postorder) {
        index = postorder.size() - 1;
        return build(postorder, INT32_MIN, INT32_MAX);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}