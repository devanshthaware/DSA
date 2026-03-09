// Reverse a linked list II
// You are given a linked list and two positions left and right
// Reverse the nodes from position left to right only, keeping the rest unchanged
// example -> Input: 1 -> 2 -> 3 -> 4 -> 5
// left = 2, right = 4
// Reverse only part:
// Output: 1 -> 4 -> 3 -> 2 -> 5

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// approach - O(n)
// Traverse to the node before left
// Reverse nodes between left and right
// Reconnect the reversed sublist with the remaining list
// We usually use a dummy node to simplify edge cases
Node *reverseBetween(Node *head, int left, int right)
{
    if (!head || left == right)
        return head;
    Node *dummy = new Node{0, head};
    Node *prev = dummy;
    // move prev to node before 'left'
    for (int i = 1; i < left; i++)
        prev = prev->next;
    Node *curr = prev->next;
    for (int i = 0; i < right - left; i++)
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }
    return dummy->next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}