// Remove k digits
// given a number as a string num and and an integer k, remove k digit so that the resulting number is smallest possible

#include <bits/stdc++.h>
using namespace std;

// brute force -> only for understanding
// try removing every possible combination of k digits and pick the smallest result
// generate all subsequences of length n - k
// convert each to number
// track minimum
// complexity -> time: O(2^n), space: large
// not practical for large inputs
void solve (string num, int k, int idx, string curr, string &ans) {
    if (k < 0)
        return;
    if (idx == num.size()) {
        if (k == 0) {
            if (k == 0) {
                if (ans == "" || curr < ans)
                    ans = curr;
            }
            return;
        }
        // take
        solve(num, k, idx + 1, curr + num[idx], ans);
        solve(num, k - 1, idx + 1, curr, ans);
    }
}

// better approach -> Simulation
// remove one digit at a time, k times
// each time:
//  find first position where num[i] >  num[i + 1]
//  remove it
// if not found -> remove last digit
// example -> 1432219, k = 3
// step 1: 4 > 3 -> remove 4 -> 132219
// step 2: 3 > 2 -> remove 3 -> 12219
// step 3: 2 > 1 -> remove 2 -> 1219
// complexity -> time: O(n^2), space: O(1)
string removeKDigits (string num, int k) {
    while (k--) {
        int i = 0;
        while (i < num.size() - 1 && num[i] <= num[i + 1])
            i++;
        num.erase(i, 1);
    }
    // remove leading zeros
    while (num.size() > 1 && num[0] == '0')
        num.erase(0, 1);
    return num.empty() ? "0" : num;
}

// optimal approach -> greedy + stack
// complexity -> time: O(n), space: O(n)
// if a digit is bigger than the next digit, removing it makes the number smaller
// so:
//  remove bad peaks immediately
//  use stack to maintain increasing order
// steps:
//  traverse digits
//  while:
//      stack not empty
//      current < top
//      k > 0
//      POP
// push current digit
// if k > 0 -> remove from end
// remove leading zeros
string removeKDigitsOptimal (string num, int k) {
    stack<char> st;
    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    // remove leading zeros
    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    res = res.substr(i);
    return res == "" ? "0" : res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}