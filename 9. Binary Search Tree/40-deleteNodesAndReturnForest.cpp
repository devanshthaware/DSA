// Delete nodes and return forest
// given a binnary tree and a list to_delete, delete those nodes and return the remaining tree (forest)
// when node is deleted:
//  its children become new roots (if they are not deleted)

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

// 1. Convert to_delete into a set
// 2. Traverse tree using postorder
// 3. If node must be deleted:
//        return NULL
// 4. If parent was deleted:
//        current node becomes new root
// 5. Collect roots in vector

class Solution
{
public:
    TreeNode *helper(TreeNode *root,
                     unordered_set<int> &del,
                     vector<TreeNode *> &forest,
                     bool isRoot)
    {

        if (root == NULL)
            return NULL;

        bool deleted = del.count(root->val);

        // If this node is a root and not deleted
        if (isRoot && !deleted)
            forest.push_back(root);

        root->left = helper(
            root->left,
            del,
            forest,
            deleted);

        root->right = helper(
            root->right,
            del,
            forest,
            deleted);

        // Delete node
        return deleted ? NULL : root;
    }

    vector<TreeNode *> delNodes(
        TreeNode *root,
        vector<int> &to_delete)
    {

        unordered_set<int> del(
            to_delete.begin(),
            to_delete.end());

        vector<TreeNode *> forest;

        helper(root, del, forest, true);

        return forest;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}