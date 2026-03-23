// Asteroid Collison
// given an array
// positive -> moving right ->
// negative -> moving left <-
// when two asteroid meet:
//  smaller one explodes
//  if equal -> both explode
//  same direction -> no collision
// example ->   input: [5, 10, -5]
//              output: [5, 10]
// why -> 10 vs -5 -> 10 survives
// collison happens only when:
//  right asteroid meets left asteroid
//  st.top() > 0 AND current < 0

#include <bits/stdc++.h>
using namespace std;

// optimal approach -> 
// use stack to simulate collision
// logic -> 
// for each asteroid:
//      while collision possible:
//          st.top() > 0 AND current < 0
//      compare sizes:
//          smaller explodes
//      handle equaal case
//      if current survives -> push
vector<int> asteroidCollision (vector<int> &ast) {
    stack<int> st;
    for (int x : ast) {
        bool destroyed = false;
        while (!st.empty() && st.top() > 0 && x < 0) {
            if (abs(st.top()) < abs(x)) {
                st.pop(); // stack asteroid destroyed
            }
            else if (abs(st.top()) == abs(x)) {
                st.pop();
                destroyed = true;
                break;
            }
            else {
                destroyed = true;
                break;
            }
        }
        if (!destroyed) {
            st.push(x);
        }
    }
    // convert stack to vector
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> ast = {5, 10, -5};
    vector<int> ans = asteroidCollision(ast);
    for (int x : ans)
        cout << x << " ";
    return 0;
}