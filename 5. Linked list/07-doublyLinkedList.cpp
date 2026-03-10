// Doubly linked list
// a doubly linked list (DLL) is a linked list in which each node contains:
//      a data field
//      a pointer to the next node
//      a pointer to the previous node
// structure: NULL<-[1]<=>[2]<=>[3]<=>[4]->NULL
// why use doubly linked list?
// traversal in both direction (forward & backward)
// easier deletion of nodes (don't need to track the previous node manually)
// useful in problem like:
//      browser history
//      undo/redo
//      LRU cache
//      music player game

#include <bits/stdc++.h>
using namespace std;

// node structure
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node (int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// basic operations on doubly linked list
// insert at head - O(1)
void insertAtHead (Node* &head, int val){
    Node *newNode = new Node(val);
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
}

// insert at tail - O(N)
void insertAtTail (Node*& head, int val) {
    if (!head) {
        insertAtHead(head, val);
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    Node *newNode = new Node(val);
    temp->next = newNode;
    newNode->prev = temp;
}

// delete a node by value - O(N)
void deleteNode (Node*& head, int val){
    Node *temp = head;
    while (temp && temp->data != val)
        temp = temp->next;
    if (!temp)
        return; // value not found
    if (temp->prev)
        temp->next->prev = temp->prev;
    delete temp;
}

// forward traversal
void printForward (Node* head) {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// backward traversal
void traverseBackward(Node *head)
{
    Node *temp = head;
    // Move to the last node
    while (temp->next != NULL)
        temp = temp->next;
    // Traverse backward
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}