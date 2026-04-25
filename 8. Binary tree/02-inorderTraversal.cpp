// Inorder traversal
// inorder traversal is a depth first search (DFS) technique where nodes are visited in this order:
// left -> root -> right
// so the sequence is:
//  traverse left subtree
//  visit root
//  traverse right subtree

// example ->
//               1
//              / \
//             2   3
//            / \
//           4   5
// inorder traversal output: 4 2 5 1 3
// step by step:
//  go left -> 4
//  visit 2
//  go right -> 5
//  visit 1
//  visit 3

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

// recursive
void inorder (Node *root) {
    if (root == NULL)
        return;
    inorder(root->left); // traverse left
    cout << root->data << " "; // visit root
    inorder(root->right); // traverse right
}

// iterative
// go to extreme left
// push nodes into stack
// pop node
// print node
// move to right subtree
void inorderIterative (Node* root) {
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}