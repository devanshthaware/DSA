// Valid Paranthesis
// given a string containing -> ( ) { } [ ]
// check if it is valid
// rules:
//  every o[pening bracket must have a matching closing bracket
//  correct order must be maintained
//  no unmatched bracket

#include <bits/stdc++.h>
// #include <stack>
using namespace std;

// optimal approach ->
// traverse string
// if opening -> push
// if closing:
//  stack empty -> invalid
//  mismatch -> invalid
//  else pop
// at end -> stack must be empty
bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        // opening bracket
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            // check empty
            if (st.empty())
                return false;
            char top = st.top();
            // mismatch
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

bool isValidOptimized (string s)
{
    stack<char> st;
    unordered_map<char, char> mp = {
        {')', '('},
        {'}', '{'},
        {']', '['}};
    for (char c : s)
    {
        if (mp.count(c) == 0)
        {
            st.push(c);
        }
        else
        {
            if (st.empty() || st.top() != mp[c])
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "{([])}";
    cout << (isValid(s) ? "True" : "False") << "\n";
    return 0;
}