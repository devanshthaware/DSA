// Kth largest element in a BST
// in a bst, reverse inorder traversal gives elements in descending order
// traversal order: right -> root -> left
// so, the kth largest element is the kth node visited in reverse inorder

// example ->
//         50
//        /  \
//      30    70
//     / \    / \
//    20 40  60 80
// reverse inorder traversal: 80 70 60 50 40 30 20
// 1st largest: 80
// 2nd largest: 70
// 3rd largest: 60
// 4th largest: 50
// so if k = 3, answer = 60

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

class Solution {
public:
    int count = 0;
    int result = -1;
    void reverseInorder (Node *root, int k) {
        if (root == NULL)
            return;
        reverseInorder(root->right, k);
        count++;
        if (count == k) {
            result = root->data;
            return;
        }
        reverseInorder(root->left, k);
    }
    int kthLargest (Node *root, int k) {
        reverseInorder(root, k);
        return result;
    }
};

// iterative approach
int kthLargest (Node *root, int k) {
    stack<Node *> st;
    while (true) {
        while (root != NULL) {
            st.push(root);
            root = root->right;
        }
        root = st.top();
        st.pop();
        k--;
        if (k == 0)
            return root->data;
        root = root->left;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}