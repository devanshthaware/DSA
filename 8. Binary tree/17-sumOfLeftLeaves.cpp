// Sum of left leaves
// a left leaf is a node that:
//  is the LEFT child of its parent
//  has NO left and NO right child
// so we sum only those nodes

// example ->
//     3
//    / \
//   9   20
//      /  \
//     15   7
// left leaves -> 9 and 15
// 9 + 15 = 24

// idea ->
// at each node:
//  check:
//  is left child a leaf?
//  yes -> add its value
//  no -> continue recursion
// traversal used:
//  DFS (preorder or Postorder)

// algorithm ->
// if node is NULL -> return 0
// if left child exists AND is leaf:
//  add left child value
// recurse left subtree
// recurse right subtree
// return total sum

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

bool isLeaf (Node *node) {
    return node &&
           node->left == NULL &&
           node->right == NULL;
}

int sumOfLeftLeaves (Node *root) {
    if (!root)
        return 0;
    int sum = 0;
    // check left leaf
    if (isLeaf(root->left)) {
        sum += root->left->data;
    }
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

// iterative approach
int sumOfLeftLeavesIterative (Node *root) {
    if (!root)
        return 0;
    stack<Node *> st;
    st.push(root);
    int sum = 0;
    while (!st.empty()) {
        Node *node = st.top();
        st.pop();
        if (node->left) {
            if (node->left->left == NULL &&
                node->left->right == NULL)
                sum += node->left->data;
            st.push(node->left);
        }
        if (node->right) {
            st.push(node->right);
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}