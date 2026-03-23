// Next greater element (right)
// for each element find the next greater element on the right
// example -> input: [4, 5, 2, 25]
//            output: [5, 25, 25, -1]

#include <bits/stdc++.h>
using namespace std;

// brute force
// for eah elements -> check each elements to its right
// complexity -> time: O(n^2), space: O(1)
vector<int> nextGreater (vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                ans[i] = ans[j];
                break;
            }
        }
    }
    return ans;
}

// optimal approach -> monotonic stack
// traverse from right -> left
// maintain decreasing stack
// while stack.top() <= current -> POP
// top = answer
// push current
// complexity -> time: O(n), space: O(n)
vector<int> nextGreaterOptimal (vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans = nextGreaterOptimal(arr);
    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}