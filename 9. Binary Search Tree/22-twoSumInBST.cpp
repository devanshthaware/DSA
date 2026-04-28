// Two sum in bst
// given a bst and a target value k, determine if there exist two nodes such that: a + b = k

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

// approach 1 - using hash set
// traverse the tree and store visited values in a set
// for each node, check if k - node->data already exists
bool findTarget (TreeNode *root, int k, unordered_set<int> &seen) {
    if (root == NULL)
        return false;
    if (seen.count(k - root->val))
        return true;
    seen.insert(root->val);
    return findTarget(root->left, k, seen) ||
           findTarget(root->right, k, seen);
}
bool twoSumBST (TreeNode* root, int k) {
    unordered_set<int> seen;
    return findTarget(root, k, seen);
}

// approach 2 - innorder + two pointer
// convert BST -> sorted array using inorder
// use two pointer (left, right)
// move pointers based on sum
void inorder (TreeNode *root, vector<int> &arr) {
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
bool twoSumBSTInorder (TreeNode *root, int k) {
    vector<int> arr;
    inorder(root, arr);
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k)
            return true;
        else if (sum < k)
            left++;
        else
            right--;
    }
    return false;
}

// approach 3 - two bst iterator
class BSTIterator {
private:
    stack<TreeNode *> st;
    bool reverse;
    void pushAll (TreeNode *node) {
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

    int next () {
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

bool findTarget (TreeNode *root, int k) {
    if (root == NULL)
        return false;
    BSTIterator left(root, false); // smallest
    BSTIterator right(root, true); // largest
    int i = left.next();
    int j = right.next();
    while (i < j) {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = left.next();
        else
            j = right.next();
    }
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}