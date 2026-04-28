// find pair with given sum in bst
// given a bst and a target sum k, determine whether there exists a pair of nodes such that: a + b = k

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

// two bst iterator
// iterator 1 -> inorder traversal (smallest values)
// iterator 2 -> reverse inorder traversal (largest values)
// words like two pointers on a sorrted array
// if sum < k -> move left iterator
// if sun > k -> move right iterator
// if sum == k -> pair found
class BSTIterator {
private:
    stack<TreeNode *> st;
    bool reverse;
    void pushAll(TreeNode *node) {
        while (node != NULL) {
            st.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
public:
    BSTIterator (TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next() {
        TreeNode *node = st.top();
        st.pop();
        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);
        return node->val;
    }
    bool hasNext () {
        return !st.empty();
    }
};

bool findPairWithSum (TreeNode *root, int k) {
    if (!root)
        return false;
    BSTIterator left(root, false); // smallest
    BSTIterator right(root, true);  // largest
    int i = left.next();
    int j = right.next();
    while (i < j) {
        int sum = i + j;
        if (sum == k)
            return true;
        else if (sum < k)
            i = left.next();
        else
            j = right.next();
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}