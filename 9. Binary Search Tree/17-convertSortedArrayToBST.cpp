// Convert sorted array to BST
// convert a sorted array into a height-balanced BST
// always choose the middle element of the array as the root
// this keeps the tree balanced (minimum height)

// algorithm (divide and conquer) ->
// find the middle element of the array -> make it the root
// recursively build the left subtree from the left half
// recursively build the right subtree from the right half

// example ->
// sorted array: [10, 20, 30, 40, 50, 60, 70]
// step by step tree:
// middle = 40
// left half -> [10, 20, 30]
// right half -> [50, 60, 70]
// final BTS:
//         40
//        /  \
//      20    60
//     / \    / \
//   10  30  50  70
// this tree is height balanced

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

Node *sortedArrayToBST (vector<int> &arr, int start, int end) {
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

Node *buildBST (vector<int> &arr) {
    return sortedArrayToBST(arr, 0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}