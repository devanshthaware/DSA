// Merge two sorted lists
// you are given two sorted singly linked list
// your task is to merge them into one sorteed linked list
// example -> list A: 1->3->5
//            list B: 2->4->6
// merged: 1->2->3->4->5->6

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = nullptr;
    }
};

// approach - O(n + m)
// two pointer technique with dummy node:
// create a dummy node to build the result list
// use two pointers a and b for the  two lists
// at each steep, compare a->data and b->data:
//      add smaller node to the merged list
//      move that pointer forward
// once one list ends, attach the remaining part of the other list
// return the merged list starting from dummy->next
Node* mergeSortedLists (Node* a, Node* b) {
    Node dummy(-1);
    Node *tail = &dummy;
    while (a && b) {
        if (a->data <= b->data){
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != nullptr) ? a : b;
    return dummy.next;
}

// utility to  print list
void printList (Node* head){
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
    Node *a = new Node(1); // list A:1->3->5
    a->next = new Node(3);
    a->next->next = new Node(5);
    Node *b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);
    Node *merged = mergeSortedLists(a, b);
    printList(merged);
    return 0;
}