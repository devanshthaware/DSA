// Flatten a multilevel doubly linked list
// each node in the doubly linked list may have:
//      next pointer to the next node
//      prev pointer to the previous nodes
//      child pointer to the anather doubly linked list (a sublist)
// your taskk is to flatten the list, so that:
//  all child nodes are instead inline into the main list
//  order ispresented (DFS style flattering)
//  the final list is a single-level doubly linked list
// example -> 1<=>2<=>3<=>4<=>5
//                    |
//                    6<=>7<=>8
//                        |
//                        9<=>10
// output: 1<=>2<=>3<=>6<=>7<=>9<=>10<=>8<=>4<=>5

#include <bits/stdc++.h>
using namespace std;

// node structure
struct Node{
    int val;
    Node *prev;
    Node *next;
    Node *child;
    Node (int _val) {
        val = _val;
        prev = next = child = nullptr;
    }
};

// approach - iterative with stack - O(N)
// steps:
// traverse the list node by node
// if a node has a child
//      push its next to the stack (if exists)
//      connect child as next and set child = nullptr
// if next == nullptr and stack is not empty:
//      pop from stack and link it as the next node
// move to the next node and repeat
Node* flatten (Node* head) {
    if (!head)
        return nullptr;
    stack<Node *> st;
    Node *curr = head;
    while (curr) {
        // if current has a child
        if (curr->child){
            // if there's a next, push it on the stack
            if (curr -> next)
                st.push(curr->next);
            // splice child in place of next
            curr->next = curr->child;
            curr->next->prev = curr;
            curr->child = nullptr;
        }
        // if at the end & stack not empty
        if (!curr->next && !st.empty()){
            curr->next = st.top();
            st.top()->prev = curr;
            st.pop();
        }
        curr = curr->next;
    }
    return head;
}

// utility to print flatten list
void printList (Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // level 1
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    // level 2
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);
    n3->child = n6;
    n6->next = n7;
    n7->prev = n6;
    n7->next = n8;
    n8->prev = n7;
    // level 3
    Node *n9 = new Node(9);
    Node *n10 = new Node(10);
    n7->child = n9;
    n9->next = n10;
    n10->prev = n9;
    // flatten
    Node *head = flatten(n1);
    printList(head);
    return 0;
}