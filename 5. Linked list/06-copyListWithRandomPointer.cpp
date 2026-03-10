// Copy list with random pointer
// you are given a linked list, where each node has:
//      next -> pointer to the next node
//      random -> pointer to any node in the list (or NULL)
// return a deep copy of this list
// that means:
//      create entirely new nodes
//      preserve the next and random connections
// Example:
// Node Structure
// [ value | next | random ]
// Example list:
// 1 → 2 → 3 → 4 → NULL
// ↓   ↓   ↓   ↓
// 3   1   4  NULL
// Here random pointers are arbitrary.
// Goal: Create a deep copy of the entire list

#include <bits/stdc++.h>
using namespace std;

// node structure
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// optimal approach - O(n)
// clone nodes next to originals:
//      insert clone nodes right after each original:
//      a -> b -> c
//      becomes
//      a->a'->b->b'->c->c'
// assign random pointers to clonedd nodes:
//      if original node's random is pointing to x, then its clone's random is x->next
// detach the clone list from the original list
Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;
    // step 1: clone nodes
    Node *curr = head;
    while (curr) {
        Node *clone = new Node(curr->val);
        clone->next = curr->next;
        curr->next = clone;
        curr = clone->next;
    }
    // step 2: assign random pointers
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    // step 3: detach the clone list
    Node *dummy = new Node(0);
    Node *copyCurr = dummy;
    curr = head;
    while (curr) {
        copyCurr->next = curr->next;
        curr->next = curr->next->next;
        curr = curr->next;
        copyCurr = copyCurr->next;
    }
    return dummy->next;
}

// approach 2 - with map - O(n), O(n) space
// traverse the original list, create a copy for each node
//      store mapping from original->copy
// traverse again and update
//      copy->next = map[original->next]
//      copy->random = map[original->random]
// return the head of the copied list
Node* copyRandomListWithMap (Node* head){
    if (!head)
        return nullptr;
    unordered_map<Node *, Node *> mp;
    // step 1: create clone nodes and store mapping
    Node *curr = head;
    while (curr) {
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }
    // step 2: assign next and random using map
    curr = head;
    while (curr) {
        mp[curr]->next = mp[curr->next]; // link next
        mp[curr]->random = mp[curr->random]; // link random
        curr = curr->next;
    }
    return mp[head];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}