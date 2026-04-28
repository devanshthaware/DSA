// BST iterator
// design an iterator for a bstthat returns elements in sorted order (asending)

// idea ->
// use inorder traversal (left -> root -> right) because:
//  inorder traversal of bst = sorted sequence
//  use a stack to simulate traversal step by step

// operations requeired ->
// next() -> retrun next smallest element
// hasNext() -> check if more elements exist

// example ->
//     7
//    / \
//   3   15
//      /  \
//     9   20
// iterator output: 3 -> 7 -> 9 -> 15 -> 20

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int val) {
        data = val;
        left = right = NULL;
    }
};

class BSTIterator {
private:
    stack<TreeNode *> st;
    void pushAll (TreeNode *node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode *root){
        pushAll(root);
    }
    int next () {
        TreeNode *node = st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }
    bool hasNext() {
        return !st.empty();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}