// Next greater element (left)
// for every element, find the greater elements on its left
// example -> input: [4, 5, 2, 10, 8]
//            output: [-1, -1, 5, -1, 10]

#include <bits/stdc++.h>
using namespace std;

// brute force -> O(n^2)
// for each element -> scan left side
vector<int> greaterElement (vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[i]) {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// optimal approach -> Monotonic stack
// traverse left -> right
// maintain decreasing stack
// while stack.top() <= current -> POP
// top = answer
// push curent
// complexity -> time: O(n), space: O(n)
vector<int> greaterElementOptimal (vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
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
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = greaterElementOptimal(arr);
    for (int val : ans) {
        cout << val << " ";
    }
    return 0;
}