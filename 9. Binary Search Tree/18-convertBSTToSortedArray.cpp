// convert bst to sorted array
// use inorder traversal (left -> root -> right)
// because inorder traversal of a bst always produces sorted order, the visited nodes directly from the sorted array

// algorithm ->
// create an empty array/vector
// perform inorder traversal of the BST
// store each visited node value into the array
// the array will be sorted in ascending order

// example ->
//         50
//        /  \
//      30    70
//     / \    / \
//    20 40  60 80
// inorder traversal output: [20, 30, 40, 50, 60, 70, 80]
// this is the sorted array

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

void inorder (Node *root, vector<int> &result) {
    if (root == NULL)
        return;
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}
vector<int> bstToSortedArray (Node *root) {
    vector<int> result;
    inorder(root, result);
    return result;
}

// iterative approach
vector<int> bstToSortedArrayIterative (Node *root) {
    vector<int> result;
    stack<Node *> st;
    while (root != NULL || !st.empty()) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        result.push_back(root->data);
        root = root->right;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}