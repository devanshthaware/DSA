// Queue using stack
// A queue follows: FIFO
// A stack follows: LIFO
// so to implement a queue using stack, we must reverse order using stacks

// approaches ->
//  using two stacks (costly dequeue)
//  using two stacks (costly enqueue)
//  using one stack (recusion)

#include <bits/stdc++.h>
using namespace std;

// aproach 1 - using two stacks (costly dequeue)
// enqueue:
//  push into stack1
// dequeue:
//  move all elements from Stack1 -> Stack2
//  Pop from Stack2
//  move back to Stack1
class Queue {
    stack<int> s1;
    stack<int> s2;
public:
    // enqueue
    void enqueue (int x) {
        s1.push(x);
    }
    // dequeue
    void dequeue () {
        if (s1.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        cout << s2.top() << " removed\n";
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    // peek
    int peek () {
        if (s1.empty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int front = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }
    bool isEmpty () {
        return s1.empty();
    }
};

// approach 2 - using two stacks (costly enqueue)
//  enqueue:
//  move s1 -> s2
//  push new element into s1
//  move s2 -> s1
//  dequeue: pop from s1
class QueueA2 {
    stack<int> s1;
    stack<int> s2;
public:
    // enqueue (costly)
    void enqueue (int x) {
        // move s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // push new element
        s1.push(x);
        // move back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    // dequeue
    void dqueue () {
        if (s1.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << s1.top() << " removed\n";
        s1.pop();
    }
    // peek
    int peek() {
        if (s1.empty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return s1.top();
    }
    bool isEmpty () {
        return s1.empty();
    }
};

// approach 3 - using one stack (recursion)
// pop all elements recursively
// insert new element at bottom
// push elements back
class QueueA3 {
    stack<int> s;
public:
    void pushBottom (int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }
        int temp = s.top();
        s.pop();
        pushBottom(x);
        s.push(temp);
    }
    // enqueue
    void enqueue (int x) {
        pushBottom(x);
    }
    // dequeue
    void dequeue () {
        if (s.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << s.top() << " removed\n";
        s.pop();
    }
    int peek() {
        if (s.empty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return s.top();
    }
    bool isEmpty() {
        return s.empty();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Approach 1:\n";
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    cout << "Front: " << q.peek();
    return 0;
}