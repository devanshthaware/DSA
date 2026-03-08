// Detect and remove cycle in linked list
// detect if a linked list contains a cycle/loop (a node points back to a previous one)
// then, remove that cycle (i.e., break the loop and make it a linear list)

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

// part 1 -> detect cycle (floyd's cycle detection - tortoise and hare)
// use two pointers:
//      slow -> moves one step
//      fast -> moves two step
// if slow == fast -> cycle detected
bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true; // cycle found
    }
    return false;
}

// part 2 -> remove cycle
// detect cycle get meeting point of slow & fast
// move one pointer to head, keep other at meeting point
// move both one step at a time -> their next will meet at cycle start
// traverse till temp->neext == start, then set temp->next = NULL
void removeCycle(Node *head)
{
    Node *slow = head, *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp = slow;
    while (temp->next != slow)
        temp = temp->next;
    temp->next = NULL;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}