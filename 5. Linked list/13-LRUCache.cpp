// LRU cache
// Least recently used cache
// an LRU Cache stores a limited number of key-value pairs and removes the least recently used item when the cache is full
// example ->
// Cache capacity = 2
// Operations:
//  put(1,1)
//  put(2,2)
//  get(1)
//  put(3,3)
//  get(2)
// Step-by-step:
//  put(1,1) → {1}
//  put(2,2) → {1,2}
//  get(1)   → {2,1}   (1 becomes most recently used)
//  put(3,3) → {1,3}   (2 removed because it was least used)
//  get(2)   → -1

// to achieve O(1) operation
//  hash map - fast key lookup
//  doubly linked list - maintain usage order

// Structure
// HashMap
// key -> node address
// Doubly Linked List
// Most Recent <=> ... <=> Least Recent
// Example:
// HEAD <- 3 <- 1 <- 2 -> TAIL
// Head side = most recently used
// Tail side = least recently used

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache
{
    struct Node
    {
        int key, value;
        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    unordered_map<int, Node *> mp;
    int capacity;

    Node *head;
    Node *tail;

public:
    LRUCache(int cap)
    {
        capacity = cap;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        Node *node = mp[key];
        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            remove(mp[key]);
        }

        Node *node = new Node(key, value);
        insert(node);
        mp[key] = node;

        if (mp.size() > capacity)
        {
            Node *lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LRUCache cache(2); // capacity = 2

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // returns 10

    cache.put(3, 30); // removes key 2 (least recently used)

    cout << cache.get(2) << endl; // returns -1 (not found)

    cache.put(4, 40); // removes key 1

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 30
    cout << cache.get(4) << endl; // 40

    return 0;
}