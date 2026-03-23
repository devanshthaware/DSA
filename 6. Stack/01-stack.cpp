// A Stack in C++ is a LIFO (Last In, First Out) data structure.
// The last element inserted is the first one removed.
// Example in real life:
// Stack of plates — you add/remove plates from the top.

#include <bits/stdc++.h>
// #include <stack>
using namespace std;

// Stack Implementation Using Array
class Stack
{
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }
};

// Stack Implementation Using Linked List
// struct Node
// {
//     int data;
//     Node *next;
// };

// class Stack
// {
//     Node *top;

// public:
//     Stack()
//     {
//         top = NULL;
//     }

//     void push(int x)
//     {
//         Node *temp = new Node;
//         temp->data = x;
//         temp->next = top;
//         top = temp;
//     }

//     void pop()
//     {
//         if (top == NULL)
//         {
//             cout << "Stack Underflow\n";
//             return;
//         }
//         Node *temp = top;
//         top = top->next;
//         delete temp;
//     }

//     int peek()
//     {
//         if (top == NULL)
//             return -1;
//         return top->data;
//     }
// };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Stack Using C++ STL
    // C++ provides a built-in stack container in the <stack> header
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element: " << st.top() << endl;
    st.pop();
    cout << "After pop, top: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;
    if (st.empty())
        cout << "Stack is empty";
    else
        cout << "Stack is not empty";
    return 0;
}