// Serialize and deserialize bst
// convert a bst into a string (serialize) and reconstruct the same bst from that string (deserialize)

// idea ->
// instead of sorting NULL markers (like in a normal binary tree), we can:
//  use preorder traversal
//  rebuild the bst using value bounds
// this works because a bst always follows: left<root<right

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

// optimal approach
// serialize -> use preorder traversal and store values separated by spaces
// deserialize -> rebuild using (min, max) bounds - exactly like bst from preorder
class Solution {
public:
    // serialize using preorder
    void preorder (TreeNode *root, string &s) {
        if (root == NULL)
            return;
        s += to_string(root->val) + " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }
    string serialize (TreeNode *root) {
        string s = "";
        preorder(root, s);
        return s;
    }
    // helper to build tree
    TreeNode *build (vector<int> &arr, int &i, int minVal, int maxVal) {
        if (i >= arr.size())
            return NULL;
        int val = arr[i];
        if (val < minVal || val> maxVal)
            return NULL;
        TreeNode *root = new TreeNode(val);
        i++;
        root->left = build(arr, i, minVal, val);
        root->right = build(arr, i, val, maxVal);
        return root;
    }
    TreeNode *deserialize (string data) {
        if (data.empty())
            return NULL;
        vector<int> arr;
        stringstream ss(data);
        int x;
        while (ss >> x)
            arr.push_back(x);
        int i = 0;
        return build(arr, i, INT32_MIN, INT32_MAX);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}