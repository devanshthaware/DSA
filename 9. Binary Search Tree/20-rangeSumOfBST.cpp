// Range sum of BST
// given a BST and two values low and high, find the sum of all node values that lie within the range [low, high] (inclusive)

// idea ->
// if node->data < low -> skip left subtree, go right
// if node->data > high -> skip right subtree, go left
// if value is in range -> add it to the sum
// this optimization makes the solution efficient

// example ->
//     10
//    /  \
//   5    15
//  / \     \
// 3   7     18
// range: low = 7, high = 15
// nodes in range: 7, 10, 15
// sum = 32

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
int rangeSumBST (Node *root, int low, int high) {
    if (root == NULL)
        return 0;
    if (root->data < low)
        return rangeSumBST(root->right, low, high);
    if (root->data > high)
        return rangeSumBST(root->left, low, high);
    return root->data +
           rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
}

// inorder version (less optimized)
int rangeSumBSTInorder (Node *root, int low, int high) {
    if (root == NULL)
        return 0;
    int sum = 0;
    sum += rangeSumBSTInorder(root->left, low, high);
    if (root->data >= low && root->data <= high)
        sum += root->data;
    sum += rangeSumBSTInorder(root->right, low, high);
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}