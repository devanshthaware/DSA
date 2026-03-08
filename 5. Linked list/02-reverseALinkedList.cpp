// Reverse a Linked list
// goal ->
// transform this: head -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// into this: head -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// approach 1 - iterative method (time: O(n), space: O(1))
// we reverse the direction of pointers using three pointers:
//      prev -> previous node (initially NULL)
//      curr -> current node(starts at head)
//      next -> to store curr -> next (temporary)
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next; // store next
        curr->next = prev; // reverse
        prev = curr;       // move prev forward
        curr = next;       // move curr forward
    }
    return prev; // new head
}

// approach 2 - recursive (time: O(n), space: O(n)(stack))
// reverse the rest of the list, then fix the first node
Node *reverseRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// traversal
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *head = new Node{1};
    head->next = new Node{2};
    head->next->next = new Node{3};
    head->next->next->next = new Node{4};
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}