// Identical tree
// two binary tree are identical if :
//  they have the same structure
//  they have the same node values

// same structure + same values = identical trees

// example -> identical trees
// Tree 1:            Tree 2:
//     1                  1
//    / \                / \
//   2   3              2   3
// result identical

// logic ->
// two trees are identical if:
//  both nodes are NULL -> true
//  one node is NULL -> false
//  values are equal
//  left subtrees are identical
//  right subtrees are identical


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
// recursive condition
// check three conditions together:
// same value
// AND
// left subtree identical
// AND
// right subtree identical
bool isIdentical (Node *root1, Node *root2) {
    // bboth trees empty
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    // check value and subtree
    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// iterative approach (using queue)
// use level order traversal to compare nodes
bool isIdenticalIterative (Node *root1, Node *root2) {
    queue<Node *> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        Node *n1 = q1.front();
        Node *n2 = q2.front();
        q1.pop();
        q2.pop();
        if (!n1 && !n2)
            continue;
        if (!n1 || !n2)
            return false;
        if (n1->data != n2->data)
            return false;
        q1.push(n1->left);
        q1.push(n1->right);
        q2.push(n2->left);
        q2.push(n2->right);
    }
    return q1.empty() && q2.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}