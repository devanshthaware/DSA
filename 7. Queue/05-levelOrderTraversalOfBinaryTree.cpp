// level order traversal of binary tree
// level order traversal means visiting nodes level by level from right to right
// it uses queue and is also called Breadth-First Search (BFS) in trees
// example ->
//     1
//    / \
//   2   3
//  / \   \
// 4   5   6
// output: 1 2 3 4 5 6
// traverse order:
//  level 0 -> 1
//  level 1 -> 2 3
//  level 2 -> 4 5 6

// idea ->
// push root into queue
// while queue not empty:
//  remove node
//  print node
//  push left child
//  push right child

// algorithm ->
// if root is NULL:
//  return
// create queue
// push root into queue
// while queue not empty:
//  node = queue.front()
//  queue.pop()
//  print node
//  if left exists:
//      push left
//  if right exists:
//      push right

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node (int val) {
        data = val;
        left = right = NULL;
    }
};
void levelOrderTraversal (Node* root) {
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    levelOrderTraversal(root);
    return 0;
}