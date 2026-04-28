// Largest bst in binary tree
// given a binary tree (not necessarily a bst), find the size (number o nodes) of the largest subtree that is a valid bst

// bst validity rule
// a subtree is a bst if:
// max(left) < root < min(right)
// check this condition at every node

// idea ->
// we process nodes in: left->right->root
// for each node, we return:
//  isBST -> whether subtree is BST
//  size -> size of subtree
//  min -> minimum value in subtree
//  max -> maximum value in subtree

// example ->
//         50
//        /  \
//      30    60
//     / \    / \
//   5   20  45  70
//               / \
//              65  80
// largest BST subtree:
//     60
//    /  \
//  45    70
//        / \
//      65  80
// answer: size = 5

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

class NodeValue {
public:
    int minNode, maxNode, maxSize;
    NodeValue (int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue largestBSTSubtreeHelper(TreeNode *root){
        // empty tree
        if (root == NULL)
            return NodeValue(INT32_MAX, INT32_MIN, 0);
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        // check bst condition
        if (left.maxNode < root->val && root->val < right.minNode) {
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.minNode),
                left.maxSize + right.maxSize + 1);
        }
        // not a bst
        return NodeValue(
            INT32_MIN,
            INT32_MAX,
            max(left.maxSize, right.maxSize));
    }
    int largestBSTSubtree (TreeNode *root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}