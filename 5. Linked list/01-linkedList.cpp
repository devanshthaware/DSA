// Linked list
// linked list is a linear data structure where elements (nodes) are stored in non-contiguous memory
// each node holds -> data (value) + pointer to next node
// unlike arrays, linked lists:
// dont have fixed size
// allow fast insertion/deletion (no shifting)
// singly linked list -> 10 -> 20 -> 30 ->null
//              node -> node -> node -> NULL
//          each node store: data + next pointer
// doubly linked list ->
//              null|10|0 <=> 0|20|0 <=> 0|30|null
//              NULL ← node <=> node <=> node → NULL
//          each node stores: prev pointer + data + next pointer

#include <bits/stdc++.h>
// #include <list> // --> STL std::list
using namespace std;

// basic node structure ->
// singly list node:
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
// doubly linked list node:
struct DNode
{
    int data;
    DNode *prev;
    DNode *next;
};

// Insert at Beginning
void insertFront(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at End
void insertEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// delete a node with a given value
void deleteNode(Node *&head, int key)
{
    Node *temp = head;
    Node *prev = nullptr;
    if (temp != nullptr && temp->data == key)
    {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
        return;
    prev->next = temp->next;
    delete temp;
}

// delete front
void deleteFront (Node*& head) {
    if (!head)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

// delete end
void deleteEnd(Node *&head)
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node *temp = head;
    while (temp->next->next)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
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

// search
bool search (Node* head, int key){
    while (head){
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *head = nullptr;
    insertFront(head, 30);
    insertFront(head, 20);
    insertEnd(head, 40);
    insertEnd(head, 50);
    printList(head);
    deleteNode(head, 40);
    printList(head);
    cout << "Search 30: " << (search(head, 30) ? "Found" : "Not Found") << "\n";

    // STL linked list in C++
    // C++ STL provide std::list which is a doubly linked list
    list<int> myList;
    myList.push_back(10); // insert at end
    myList.push_front(5); // insert at front
    myList.pop_back(); // remove from end
    myList.pop_front(); // remove from front
    for (int val : myList)
        cout << val << " ";
    return 0;
}
