// count nodes in a BST
// find the total number of nodes present in the BST
// count the current node (1) plus nodes in the left subtree and right subtree

// formula -> N = 1 + N(left) + N(right)
// where:
// N = total number of nodes
// N(left) = nodes in left subtree
// N(right) = nodes in right subtree

// example ->
//     10
//    /  \
//   5    20
//  / \     \
// 3   7     25
// counting nodes: 3, 7, 5, 25, 20, 10 -> total = 6 nodes

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

int countNodes (Node *root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// iterative approach
int countNodeIterative (Node *root) {
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        count++;
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}