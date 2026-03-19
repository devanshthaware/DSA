// Delete middle element of stack
// delete middle element of a stack without using extra data structure (in optimal)

#include <bits/stdc++.h>
using namespace std;

// brute force
// use another stack
// move element to temp stack
// skip middle elements
// push back remaining elements
// complexity -> time: O(n), space: O(n)
void deleteMiddle(stack<int> &st)
{
    stack<int> temp;
    int n = st.size();
    int mid = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (i == mid)
        {
            st.pop(); // skip middle
        }
        else
        {
            temp.push(st.top());
            st.pop();
        }
    }
    // restore
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

// better approach ->
// using vector
void deleteMiddleBetter(stack<int> &st)
{
    vector<int> v;
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    int mid = v.size() / 2;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (i != mid)
        {
            st.push(v[i]);
        }
    }
}

// optimal approach ->
// remove elements until middle reached
// skip middle element
// push remaining elements back
// use recursion with counter (k)
// complexity -> time: O(n), space: O(n) (recursion)
void solve(stack<int> st, int k)
{
    // base case: middle element
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st, k - 1);
    st.push(temp);
}
void deleteMiddleOptimal(stack<int> st)
{
    int n = st.size();
    // middle position
    int k = (n / 2) + 1;
    solve(st, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}