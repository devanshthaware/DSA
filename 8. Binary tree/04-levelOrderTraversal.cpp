// level order traversal
// level order traversal is a bfs technique where nodes are visited level by level from left to right
//  level by level traverse
// it uses a queue data structure

// example ->
//               1
//              / \
//             2   3
//            / \   \
//           4   5   6
// level order output: 1 2 3 4 5 6
// step by step traversal:
//  visit 1
//  visit 2, 3
//  visit 4, 5, 6

// algorithm ->
// create an empty queue
// push root into queue
// while queue is not empty:
//  remove front node
//  print node
//  push left child
//  push right child

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

void levelOrder (Node *root) {
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}