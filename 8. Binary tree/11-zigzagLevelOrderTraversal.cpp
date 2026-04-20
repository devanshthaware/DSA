// Zigzag level order traversal
// zigzag traversal is a variation of level order traversal where:
//  first level -> left to right
//  second level -> right to left
//  third level -> left to right
// continue alternating
// level 1: left -> right
// level 2: right -> left
// level 3: left -> right
// also called
//  spiral traversal
//  zigzag traversal

// example ->
//           1
//          / \
//         2   3
//        / \   \
//       4   5   6
// zigzag output:
// [
//     [1],
//     [ 3, 2 ],
//     [ 4, 5, 6 ]
// ]
// traversal direction:
//  level 1 -> 1
//  level 2 -> 3 2
//  level 3 -> 4 5 6

// idea ->
// use:
// queue -> for level order traversal
// flag/boolean -> to switch direction
//  leftToRight = true / false
// if:
//  true -> insert normally
//  false -> insert in reverse order

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

vector<vector<int>> zigzagLevelOrder (Node *root) {
    vector<vector<int>> result;
    if (!root)
        return result;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++) {
            Node *curr = q.front();
            q.pop();
            int index;
            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;
            level[index] = curr->data;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        leftToRight = !leftToRight;
        result.push_back(level);
    }
    return result;
}

// alternative approach using two stacks
// stack1 -> left to right
// stack2 -> right to left
void zigzagTraversal (Node *root) {
    if (!root)
        return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node *curr = s1.top();
            s1.pop();
            cout << curr->data << " ";
            if (curr->left)
                s2.push(curr->left);
            if (curr->right)
                s2.push(curr->right);
        }
        while (!s2.empty()) {
            Node *curr = s2.top();
            s2.pop();
            cout << curr->data << " ";
            if (curr->right)
                s1.push(curr->right);
            if (curr->left)
                s1.push(curr->left);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}