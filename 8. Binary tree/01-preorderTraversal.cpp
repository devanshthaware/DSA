// Preorder Traversal
// preorder traversal is a depth first search (dfs) technique where nodes are visited in this order:
// root -> left -> right
// so the sequence is:
//  visit root
//  traverse left subtree
//  traverse right subtree

// example ->
//               1
//              / \
//             2   3
//            / \
//           4   5
// preorder traversal output: 1 2 4 5 3
// step by step
//  visit 1 (root)
//  go left -> 2
//  go left -> 4
//  back -> 5
//  back -> 3

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

// recursive - O(n)
void preorder (Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " "; // visit root
    preorder(root->left); // traverse left
    preorder(root->right); // traverse right
}

// iterative
// push root into stack
// pop node
// print node
// push right child
// push left child
void preorderIterative (Node* root) {
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (!st.empty()) {
        Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}