// Inorder traversal of BST
// left -> root -> right
// important property of BST:
//  inorder traversal of a bst always gives values in sorted (ascending) order

// example ->
//         50
//        /  \
//      30    70
//     / \    / \
//    20 40  60 80
// inorder traversal steps:
// go left from 50 -> 30
// go left from 30 -> 20 -> print 20
// back to 30 -> print 30
// go right -> 40 -> print 40
// back to 50 -> print 50
// go ight -> 70 -> left -> 60 -> print 60
// back to 70 -> print 70
// go right -> 80 -> print 80
// output: 20 30 40 50 60 70 80

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

void inorder (Node *root) {
    if (root == NULL)
        return;
    inorder(root->left); // left
    cout << root->data << " "; // root
    inorder(root->right); // right
}

// iterative approach
void inorderIterative (Node *root) {
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