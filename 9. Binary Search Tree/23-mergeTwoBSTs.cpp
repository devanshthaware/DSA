// Merge two BSTs
// given two bsts, merge them and return all elements in sorted order

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int data) {
        val = data;
        left = right = NULL;
    }
};

// approach 1 - inorder + merge two sorted arrays
// do inorder traversal of both BSTs -> get two sorted arrays
// merge arrays like merge step of merge sort
// step by step:
//  BST 1 inorder -> [1, 3, 5]
//  BST 2 inorder -> [2, 4, 6]
//  merged result -> [1, 2, 3, 4, 5, 6]
void inorder (TreeNode *root, vector<int> &arr) {
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
vector<int> mergeArrays (vector<int> &a, vector<int> &b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            result.push_back(a[i++]);
        else
            result.push_back(b[j++]);
    }
    while (i < a.size())
        result.push_back(a[i++]);
    while (j < b.size())
        result.push_back(b[j++]);
    return result;
}
vector<int> mergeTwoBSTs (TreeNode *root1, TreeNode *root2) {
    vector<int> a, b;
    inorder(root1, a);
    inorder(root2, b);
    return mergeArrays(a, b);
}

// approach 2 - two iterators
void pushLeft (TreeNode *node, stack<TreeNode *> &st) {
    while (node != NULL) {
        st.push(node);
        node = node->left;
    }
}
vector<int> mergeTwoBSTs (TreeNode *root1, TreeNode *root2) {
    stack<TreeNode *> s1, s2;
    vector<int> result;
    pushLeft(root1, s1);
    pushLeft(root2, s2);
    while (!s1.empty() || !s2.empty()) {
        stack<TreeNode *> &st =
            s2.empty() ||
                    (!s1.empty() && s1.top()->val <= s2.top()->val)
                ? s1
                : s2;
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);
        pushLeft(node->right, st);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}