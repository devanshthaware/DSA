// Rotate a linked list
// Rotating a linked list means shifting nodes to the right (or left) by k positions
// The most common problem is rotate right by k positions
// Example:
// Input:
// 1 -> 2 -> 3 -> 4 -> 5
// k = 2
// Result:
// 4 -> 5 -> 1 -> 2 -> 3
// Because the last 2 nodes move to the front

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// approach
// Find the length of the linked list
// Connect tail -> head to form a circular list
// Find the new tail
// Break the circle
Node *rotateRight(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    Node *temp = head;
    int length = 1;
    // find length and last node
    while (temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }
    // connect tail to head
    temp->next = head;
    k = k % length;
    int steps = length - k;
    Node *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;
    Node *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
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
    head = rotateRight(head, 2);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}