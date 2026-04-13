// Queue using linked list
// why use linked list for queue:
//  Advantages over qrray queue:
//      no fixed size
//      no overflow until memory is full
//      dynamic memory allocation
//      efficient insertion and deletion

// queue  representation using linked list
//     front        rear
//       ^           ^
//      10 -> 20 -> 30 -> NULL
// we maintain:
//  Node* front;
//  Node* rear;

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node (int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node *front;
    Node *rear;
public:
    Queue () {
        front = rear = NULL;
    }
    // check if queue is empty
    bool isEmpty () {
        return front == NULL;
    }
    // enqueue operation
    void enqueue (int x) {
        Node *newNode = new Node(x);
        // if queue is empty
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    // dequeue operation
    void dequeue () {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node *temp = front;
        cout << temp->data << " removed\n";
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
    // peek operation
    int peek () {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }
    // display queue
    void display () {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        Node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue: ";
    q.display();
    q.dequeue();
    cout << "After Dequeue: ";
    q.display();
    cout << "Front Element: " << q.peek() << endl;
    return 0;
}