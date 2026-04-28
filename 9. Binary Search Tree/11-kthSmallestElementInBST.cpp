// Kth smallest element in a binary search tree
// in a bst, inorder traversal (left -> root -> right) gives elements in sorted ascending order
// so, the kth smallest element is simply the kth node visited during inorder traversal

// example ->
//         50
//        /  \
//      30    70
//     / \    / \
//    20 40  60 80
// inorder traversal: 20 30 40 50 60 70 80
// 1st smallest: 20
// 2nd smallest: 30
// 3rd smallest: 40
// 4th smallest: 50
// so if k = 3, answer = 40

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
    void inorder (Node *root, int k) {
        if (root == NULL)
            return;
        inorder(root->left, k);
        count++;
        if (count == k) {
            result = root->data;
            return;
        }
        inorder(root->right, k);
    }
    int kthSmallest (Node *root, int k) {
        inorder(root, k);
        return result;
    }
};

// iterative approach
int kthSmallestIterative (Node *root, int k) {
    stack<Node *> st;
    while (true) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        k--;
        if (k == 0)
            return root->data;
        root = root->right;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}