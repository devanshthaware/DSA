// Implement stack using queue
// make Stack (LIFO) using Queue (FIFO)
// approach ->
// Use one queue
// Make push operation costly
// logic
// When pushing:
//  1. Push element into queue
//  2. Rotate previous elements behind it
// So newest element comes to front -> acts like stack top

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
    queue<int> q;

public:
    // Push (costly)
    void push(int x)
    {
        int size = q.size();

        q.push(x);

        // rotate old elements
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop
    void pop()
    {
        if (q.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    // Top
    int top()
    {
        if (q.empty())
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front();
    }

    // Empty
    bool isEmpty()
    {
        return q.empty();
    }
};
int main()
{
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; // 30

    st.pop();

    cout << st.top() << endl; // 20
}