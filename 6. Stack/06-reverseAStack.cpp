// Reverse a stack
// reverse a stack without using extra data structure
// only recursion allowed

#include <bits/stdc++.h>
using namespace std;

// burte force -> (only for understanding)
// use an extra stack
// pop from original -> push into new stack
// example -> stack: 1 2 3 (top = 3)
// pop -> 3 -> push to new
// pop -> 2 -> push
// pop -> 1 -> push
// new stack: 3 2 1 (top = 1) -> reversed
// complexity -> time: O(n), space: O(n)
void reverseStack(stack<int> &st)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st = temp;
}

// better approach -> (only for understanding)
// use vector/array as a helper
// store elements in array
// push back into stack
// complexity -> time: O(n), space: O(n)
void reverseStackBetter (stack<int> &st) {
    vector<int> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    for (int x : v) {
        st.push(x);
    }
}

// optimal approach -> (important)
// remove top
// reverse remaining stack
// insert removed element at bottom
// simulate bottom insertion using recursion
// complexity -> time: O(n^2), space: O(n)
// insert at bottom
void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}
// Reverse stack
void reverseStackOpti(stack<int> &st)
{
    if (st.empty())
        return;
    int x = st.top();
    st.pop();
    reverseStackOpti(st);
    insertAtBottom(st, x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    reverseStackOpti(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}