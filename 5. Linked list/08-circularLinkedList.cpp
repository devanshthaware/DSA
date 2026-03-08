// Circular linked list
// what is circular linked list ->
// a circular linked list is a variation of alinked list where:
//      the last node points back to the first node (instead of NULL)
//      it can be singly or doubly linked
// example: [10]->[20]->[30]->
//                  |        |
//                  <--------
// why use circular linked list -> efficient in cyclic scheduling (e.g. round robin)
// useful in buffer memory, multiplayer game turns, etc.
// better for looped navigation

#include <bits/stdc++.h>
using namespace std;

// Node structure
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

// operations on circular linked list
// insert at tail
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// insert at head
void insertAtHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// delete node by value
void deleteNode(Node *&head, int val)
{
    if (!head)
        return;
    Node *curr = head;
    Node *prev = nullptr;
    // if head is the only node
    if (head->data == val && head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }
    // deleting head node
    if (head->data == val)
    {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    // deleting non-head node
    do
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == val)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
    } while (curr != head);
}

// traversal
void printCircularList(Node *head)
{
    if (!head)
        return;
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}