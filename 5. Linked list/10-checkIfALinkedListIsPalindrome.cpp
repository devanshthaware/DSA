// Check if a linked list is palindrome
// a palindrome linked list reads the same forward and backward
// example -> 1 → 2 → 3 → 2 → 1 → NULL    Palindrome
// 1 → 2 → 3 → 4 → NULL        Not Palindrome

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = nullptr;
    }
};

// optimal approach - O(n) time, O(1) space
// find the middle  of the linked list
// reverse the second half
// compare both halves
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *secondHalf = reverse(slow->next);
    Node *firstHalf = head;
    while (secondHalf != NULL)
    {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}