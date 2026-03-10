// Reverse Nodes in K Groups
// Given a linked list, reverse the nodes in groups of size k.
// If the number of nodes is not a multiple of k, the remaining nodes stay unchanged.
// You must only change pointers, not values.
// Example
// Input:
// 1 -> 2 -> 3 -> 4 -> 5
// k = 2
// Output:
// 2 -> 1 -> 4 -> 3 -> 5
// Another example:
// Input
// 1 -> 2 -> 3 -> 4 -> 5
// k = 3
// Output
// 3 -> 2 -> 1 -> 4 -> 5

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// approach
// Count k nodes.
// Reverse those k nodes.
// Recursively solve for the rest of the list.
// Connect the reversed group with the next part.
Node *reverseKGroup(Node *head, int k)
{
    Node *temp = head;
    int count = 0;
    // check if k nodes exist
    while (temp && count < k)
    {
        temp = temp->next;
        count++;
    }
    if (count < k)
        return head;
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    count = 0;
    // reverse k nodes
    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
        head->next = reverseKGroup(next, k);
    return prev;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    head->next->next->next->next = new Node{5, NULL};
    int k = 2;
    head = reverseKGroup(head, k);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}