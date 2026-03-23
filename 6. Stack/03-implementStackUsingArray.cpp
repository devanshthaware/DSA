// Implement Stack using Array
//  Use an array + a pointer (top)
//  top = -1 -> stack empty
//  Insert -> ++top
//  Delete -> top--

#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top, capacity;

public:
    // Constructor
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[cap];
        top = -1;
    }

    // Push
    void push(int x)
    {
        if (top >= capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // Pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // Peek
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Size
    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack st(100);
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << endl;

    st.pop();

    cout << "Top after pop: " << st.peek() << endl;

    cout << "Size: " << st.size() << endl;
}