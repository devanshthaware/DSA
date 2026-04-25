// Postorder Traversal
// postorder traversal is a depth first search (dfs) technique where nodes are visited in this order:
//  left -> right -> root
// so the sequence is:
//  traverse left subtree
//  traverse right subtree
//  visit root

// example ->
//               1
//              / \
//             2   3
//            / \
//           4   5
// postorder traversal output: 4 5 2 3 1
// step by step:
//  go left -> 4
//  go right -> 5
//  visit 2
//  visit 3
//  visit 1

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
void postorder (Node* root) {
    if (root == NULL)
        return;
    postorder(root->left); // traverse left
    postorder(root->right); // traverse right
    cout << root->data << " "; // visit root
}

// iterative (using two stack)
// push root to stack1
// pop from stack1 -> push to stack2
// push left and right children to stack1
// print stack2
void postorderIterative (Node *root) {
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// iterative (using one stack)
void postorderOneStack (Node *root) {
    stack<Node *> st;
    Node *curr = root;
    Node *lastVisited = NULL;
    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node *peekNode = st.top();
            if (peekNode->right != NULL && lastVisited != peekNode->right){
                curr = peekNode->right;
            }
            else {
                cout << peekNode->data << " ";
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}