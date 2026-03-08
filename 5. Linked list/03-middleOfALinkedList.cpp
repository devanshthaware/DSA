// Middle of a linked list
// given the head of a singly linked list, find and return the middle node
// if the number number of nodes is even, return the second middle node
// example -> input: 1->2->3->4->5    output: 3
//            input: 1->2->3->4->5->6    output: 4

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

// approach 1 - fast and slow pointer (two pointer)
// tortoise here algorithm
// use two pointers:
//      slow moves one step at a time
//      fast movess two step at a time
// when fast reaches end, slow is at middle
Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 step
    }
    return slow; // middle node
}

// approach 2- counting nodes
// traverse list and count nodes
// traverse again to count / 2
Node *findMiddleAlternate(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < count / 2; i++)
        temp = temp->next;
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node *head = new Node{1};
    head->next = new Node{2};
    head->next->next = new Node{3};
    head->next->next->next = new Node{4};
    head->next->next->next->next = new Node{5};

    Node *middle = findMiddle(head);

    cout << "Middle node: " << middle->data << endl;
    return 0;
}