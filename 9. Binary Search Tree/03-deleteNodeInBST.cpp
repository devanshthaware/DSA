// Delet node in BST
// deletion in a BST has 3 importannt cases

// case 1 -> Node is a leaf (No children)
// simply remove the node
//     50
//    /
//  30   <- delete
// Result:
//     50

// case 2 -> Node has one child
// replace the node with its child
//     50
//    /
//  30
//    \
//     40   <- delete 30
// Result:
//     50
//    /
//  40

// case 3 -> Node has two children
// replace the node with its inorder successor -> the smallest value in the right subtree
// steps:
//  find inorder successor
//  copy its value to the node
//  delete the successor node
//         50
//        /  \
//      30    70
//            / \
//          60   80
// Delete 70
// Inorder successor = 80
// Result:
//         50
//        /  \
//      30    80
//            /
//          60

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

Node *findMin (Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *deleteNode (Node *root, int key) {
    if (root == NULL)
        return root;
    // search the node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // case 2: one child
        else if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // case 3: two children
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}