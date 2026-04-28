// Convert bst to greater tree
// modify a binary search tree so that each node's value becomes the sum of all values greater than or equal to it

// idea ->
// use reverse inorder traversal
// right -> root -> left
// because in bst, this visits nodes from largest to smallest, allowing us to keep a running sum

// example ->
// original bst
//     4
//    / \
//   1   6
//      / \
//     5   7
// after conversion (greater tree)
//     22
//    /  \
//   23   13
//       /  \
//      18   7
// explanation (descending order):
// 7 -> 7
// 6 -> 6 + 7 = 13
// 5 -> 5 + 6 + 7 = 18
// 4 -> 4 + 5 + 6 + 7 = 22
// 1 -> 1 + 4 + 5 + 6 + 7 = 23

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

class Solution {
private:
    int sum = 0;
    void reverseInOrder (TreeNode *root) {
        if (root == NULL)
            return;
        reverseInOrder(root->right);
        sum += root->val;
        root->val = sum;
        reverseInOrder(root->left);
    }
public:
    TreeNode *convertBST(TreeNode *root) {
        reverseInOrder(root);
        return root;
    }
};

// iterative approach
TreeNode *convertBSTIterative (TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *curr = root;
    int sum = 0;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->right;
        }
        curr = st.top();
        st.pop();
        sum += curr->val;
        curr->val = sum;
        curr = curr->left;
    }
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}