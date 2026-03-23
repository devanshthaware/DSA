// Daily Tempratures
// given temperatures, find:
// for each days -> how many days until a warmer temperature
// if none -> 0
// example ->   input: [73, 74, 75, 71, 69, 72, 76, 73]
//              output: [1,  1,  4,  2,  1,  1,  0,  0]
// find next greater element on right (but return distance)

#include <bits/stdc++.h>
using namespace std;

// brute force -> O(n^2)
// for each day -> check all future days
vector<int> dailyTemperature (vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temperatures[j] > temperatures[i]) {
                ans[i] = j - i;
                break;
            }
        }
    }
    return ans;
}

// Optimal approach -> Monotonic stack
// traverse right -> left
// store indices in stack
// while temperatures[stack.top()] <= current -> pop
// ans = stack.top() - i
// if empty -> 0
vector<int> dailyTemperatureOptimal (vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;  // store indices
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }
        if (!st.empty())
            ans[i] = st.top() - i;
        else
            ans[i] = 0;
        st.push(i);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatureOptimal(temperatures);
    for (int val : ans)
        cout << val << " ";
    return 0;
}