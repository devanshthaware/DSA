// Basic Calculator
// evaluate a string expression containing:
//  +, -, *, /, spaces, integers
// constraints:
//  no parentheses
//  must respect operator precedennce
//  division truncates toward zero
// example -> input: s = "3+2*2"
//            output: 7
//            input: s = " 3/2 "
//            output: 1
//            input: s = " 3+5 / 2 "
//            output: 5

// idea ->
//  we process numbers immediately for * and /
//  store results for + and - in stack
//  finally sum the stack
// algorithm ->
//  traverse string
//  build number
//  when operator found:
//      apply previous operator
//  push result into stack
//  sum stack
// why stack ->
//  + and - -> push number
//  * and / -> compute immediately
// so precedence is handled naturally

#include <bits/stdc++.h>
using namespace std;

int calculate(string s)
{
    stack<int> st;
    int num = 0;
    char op = '+';
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') ||
            i == s.size() - 1)
        {
            if (op == '+')
                st.push(num);
            else if (op == '-')
                st.push(-num);
            else if (op == '*')
            {
                int top = st.top();
                st.pop();
                st.push(top * num);
            }

            else if (op == '/')
            {
                int top = st.top();
                st.pop();
                st.push(top / num);
            }
            op = c;
            num = 0;
        }
    }
    int result = 0;
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "3+2*2";
    cout << calculate(s);
    return 0;
}