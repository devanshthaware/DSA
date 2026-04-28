// Construct bst from level order traversal
// given the level order traversal of a binary search tree, construct the original BST
// level order: root -> level by level (left to right)

// every node must satisfy:
// left < root < right
// maintain a valid range (min, max) for each node while building the tree

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

// queue + range method
// store in queue:
//  node pointer
//  minimum allowed value
//  maximum allowed value
// then for each next value in level order:
//  if value fits in (min, max)
//      create node
//      push its left and right ranges
class NodeInfo {
public:
    TreeNode *node;
    int minVal;
    int maxVal;
    NodeInfo (TreeNode *n, int minV, int maxV) {
        node = n;
        minVal = minV;
        maxVal = maxV;
    }
};

TreeNode *bstFromLevelOrder (vector<int> &level) {
    if (level.size() == 0)
        return NULL;
    queue<NodeInfo> q;
    TreeNode *root = new TreeNode(level[0]);
    q.push(NodeInfo(root, INT32_MIN, INT32_MAX));
    int i = 1;
    while (i < level.size()) {
        NodeInfo temp = q.front();
        q.pop();
        // left child
        if (i < level.size() && level[i] > temp.minVal && level[i] < temp.node->val) {
            temp.node->left = new TreeNode(level[i++]);
            q.push(NodeInfo(temp.node->left, temp.minVal, temp.node->val));
        }
        // right child
        if (i < level.size() && level[i] > temp.node->val && level[i] < temp.maxVal) {
            temp.node->right = new TreeNode(level[i++]);
            q.push(NodeInfo(temp.node->right, temp.node->val, temp.maxVal));
        }
    }
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}