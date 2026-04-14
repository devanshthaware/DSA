// Queue using array
// queue -> a queue is a linear data structure that follows:
//      FIFO - first in first out
// example -> insert: 10, 20, 30
//            queue: front -> 10, 20, 30 <- rear
//            remove: 10 remove first
// operations in queue
//  enqueue - insert element
//  dequeue - remove element
//  peek/front - get front element
//  isEmpty - check if queue empty
//  isFull - check if queue full
//  display - print queue

// array representation
//  index:   0   1   2  3  4
//  queue: [10, 20, 30, -, -]
//  front = 0
//  rear = 2

#include <bits/stdc++.h>
using namespace std;

// queue using array (simple implementation - linear queue)
class Queue {
    int arr[100];
    int front;
    int rear;
    int size;
public:
    Queue (int n) {
        size = n;
        front = -1;
        rear = -1;
    }
    // check empty
    bool isEmpty () {
        return front == -1;
    }
    // check full
    bool isFull () {
        return rear == size - 1;
    }
    // enqueue - O(1)
    void enqueue (int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = x;

        cout << x << " inserted\n";
    }
    // dequeue - O(1)
    void dequeue () {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " removed\n";
        front++;
        if (front > rear)
            front = rear = -1;
    }
    // peek - O(1)
    int peek () {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }
    // display - O(n)
    void display () {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// problem with simple queue
// after deletions:
//  initial: [10, 20, 30, 40, 50]
//  after removing 3 elements: [-, -, -, 40, 50]
//  front = 3
//  rear = 4
// now:
//  rear == size - 1
// queue shows full even though space exists
// this is called: false overflow

// better version - circular queue using array
//  rear = (rear + 1) % size
//  front = (front + 1) % size
class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue (int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    bool isEmpty () {
        return front == -1;
    }
    bool isFull () {
        return (rear + 1) % size == front;
    }
    void enqueue (int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
        cout << x << " inserted\n";
    }
    void dequeue () {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " removed\n";
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }
    int peek () {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[front];
    }
    void display () {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front: " << q.peek();
    cout << "\nCircular Queue:\n";
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cq.dequeue();
    cq.display();
    return 0;
}