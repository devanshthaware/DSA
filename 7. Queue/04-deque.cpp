// Deque - double ended queue
// a dequeue is a linear data structure where insertion and deletion can happen at both ends
// front <---- deque ----> rear
// insert/delete allowed on both sides

// operations is deque
//  insert front - add element at front
//  insert rear - add element at rear
//  delete front - remove element from front
//  delete rear - remove element from rear
//  get front - view front element
//  get rear - view rear element
//  isEmpty - check empty
//  isFull - check full

// types of deque
//  input restricted deque - insertion only at one end
//  output restricted deque - deletion only at one end
//  normal deque - both operations allowed at both ends

// circular deque core logic
//  the movement uses:
//  i = (i +- 1) mod n
//      +1 -> move forward
//      -1 -> move backward
//      n -> size of array

#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return (rear + 1) % size == front;
    }
    // Insert Front
    void insertFront(int x)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
    }
    // Insert Rear
    void insertRear(int x)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
    }
    // Delete Front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        cout << arr[front] << " removed\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    // Delete Rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        cout << arr[rear] << " removed\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Empty\n";
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Empty\n";
            return -1;
        }
        return arr[rear];
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque Empty\n";
            return;
        }
        int i = front;
        while (true)
        {
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
    Deque dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);
    dq.display();
    dq.deleteRear();
    dq.deleteFront();
    dq.display();
    return 0;
}