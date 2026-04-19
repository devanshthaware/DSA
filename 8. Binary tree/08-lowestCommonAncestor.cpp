// Lowest common ancestor in binary tree
// the LCA of two nodes p and q in a binary tree is:
//  the lowest node in the tree has both p and q as descendants (a node can be a descendant of itself)
// example ->
//               3
//              / \
//             5   1
//            / \ / \
//           6  2 0  8
//             / \
//            7   4

// cases
// 5 and 1 -> 3
// 6 and 4 -> 5
// 7 and 8 -> 3
// 5 and 4 -> 5

// idea ->
// recursion ->
// if root is NULL -> return NULL
// if root equals p or q -> return root
// search left subtree
// search right subtree
// if both sides return non-null -> current node is LCA

// recursive algorithm
// if left != NULL AND right != NULL
//      return root <- LCA
// else
//      return non-null child

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

Node* LowestCommonAncestor (Node* root, Node* p, Node* q) {
    if (root == NULL || root == p || root == q)
        return root;
    Node *left = LowestCommonAncestor(root->left, p, q);
    Node *right = LowestCommonAncestor(root->right, p, q);
    if (left && right)
        return root;
    return left ? left : right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}