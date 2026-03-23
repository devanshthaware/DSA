// Min Stack
// design a stack that supports
//  push(x), pop(), top(), getMin()
//  all operation must be O(1)

#include <bits/stdc++.h>
using namespace std;

// approach 1 -> two stack
//  main stack -> store elements
//  min stack -> stores minimum
// rule: if new elements <= current min -> push into min stack
class MinStack
{
    stack<int> st;
    stack<int> minSt;

public:
    void push(int x)
    {
        st.push(x);
        if (minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }
    void pop()
    {
        if (st.empty())
        {
            cout << "Stack Underfolw\n";
            return;
        }
        if (st.top() == minSt.top())
        {
            minSt.pop();
        }
        st.pop();
    }
    int top()
    {
        if (st.empty())
            return -1;
        return st.top();
    }
    int getMin()
    {
        if (minSt.empty())
            return -1;
        return minSt.top();
    }
};

// approach 2 -> optimized (sinle stack)
// save space
// store encode value:
//      if new value < min:
//          store: 2*x - min
//          update min = x
class MinStackOptimal
{
    stack<long long> st;
    long long minVal;

public:
    void push(int x)
    {
        if (st.empty())
        {
            st.push(x);
            minVal = x;
        }
        else if (x < minVal)
        {
            st.push(2LL * x - minVal);
            minVal = x;
        }
        else
        {
            st.push(x);
        }
    }
    void pop()
    {
        if (st.top() < minVal)
        {
            minVal = 2 * minVal - st.top();
        }
        st.pop();
    }
    int top()
    {
        if (st.top() < minVal)
            return minVal;
        return st.top();
    }
    int getMin()
    {
        return minVal;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);

    cout << st.getMin() << endl; // 3

    st.pop();

    cout << st.getMin() << endl; // 3

    st.pop();

    cout << st.getMin() << endl; // 5
    return 0;
}