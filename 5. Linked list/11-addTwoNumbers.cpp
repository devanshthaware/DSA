// Add two numbers
// Each node contains one digit, and digits are stored in reverse order
// example -> List 1: 2 -> 4 -> 3
// List 2 : 5 -> 6 -> 4
// These represent numbers :
//     342 + 465 = 807
//     Result linked list :
//     7 -> 0 -> 8

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

// approach - O(max(n, m))
// digit-by-digit addition
// Steps:
// Traverse both lists simultaneously
// Add digits + carry
// Create a new node with (sum % 10)
// Update carry (sum / 10)
// Move to next nodes
Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node{0};
    Node *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        temp->next = new Node{sum % 10};
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}