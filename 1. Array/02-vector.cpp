#include <bits/stdc++.h>
// #include <vector>
using namespace std;

// vector is a dynamic array from STL(standard template library), It can grow or shrink automatically as you add or remove elements. No need to manually define the size like normal arrays!

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // create an empty vector
    vector<int> v;

    // add elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // loop on vector
    for (int num:v)
        cout << num << "\n";

    // access element safely
    cout << "Element at index 1: " << v.at(1) << "\n";

    // first and last element
    cout << "First element: " << v.front() << "\n";
    cout << "Second element: " << v.back() << "\n";

    // insert 15 at index 1
    v.insert(v.begin() + 1, 15);
    cout << "After insert: ";
    for (int num:v)
        cout << num << "\n";

    // erase element at index 2
    v.erase(v.begin() + 2);
    cout << "After erase: ";
    for (int num : v)
        cout << num << "\n";

    // remove last element
    v.pop_back();
    cout << "After pop_back: ";
    for (int num : v)
        cout << num << "\n";

    // resize vector to 5 elements
    v.resize(5);
    cout << "After resize to 5: ";
    for (int num : v)
        cout << num << "\n";

    // check if empty
    if (v.empty())
        cout << "vector is empty" << "\n";
    else
        cout << "vector is not empty" << "\n";

    // remove all elements
    v.clear();
    cout << "After clear, size: " << v.size() << "\n";

    // fill vector with 4 elements of 100
    v.assign(4, 100);
    cout << "After assign: ";
    for (int num : v)
        cout << num << "\n";

    // swap two vectors
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    v.swap(b);
    cout << "After swap, vector v: ";
    for (int num : v)
        cout << num << "\n";
    cout << "After swap, vector b: ";
    for (int num : b)
        cout << num << "\n";

    return 0;
}