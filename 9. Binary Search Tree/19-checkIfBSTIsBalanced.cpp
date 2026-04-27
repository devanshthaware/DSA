// Check if a bst is balanced
// for every node, the difference between the heights of the left and right subtrees is not more than 1

// balanced conditionn ->
// |h(left) - h(right)| <= 1
// if this condition is true for all nodes -> tree is balanced
// if it fails at any node -> tree is not balanced

// example -> balanced tree
//     10
//    /  \
//   5    20
//  / \
// 3   7
// height diffrence at every node <= 1 -> balanced

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

// optimal approach
// instead of checking height multiple times, we check balance while computing height
int checkHeight (Node *root) {
    if (root == NULL)
        return 0;
    int left = checkHeight(root->left);
    if (left == -1)
        return -1;
    int right = checkHeight(root->right);
    if (right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return 1 + max(left, right);
}
bool isBalanced(Node *root) {
    return checkHeight(root) != 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}