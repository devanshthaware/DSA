// Stock span problem
// for each day
//      number of consecutive days before it (including today)
//      where price <= today's price
// example ->   input: [100, 80, 60, 70, 60, 75, 85]
//              output: [1, 1, 1, 2, 1, 4, 6]
// explanation:
//      day 0 -> 100 --> no previous -> 1
//      day 1 -> 80  --> previous: [100] -> stop -> 1
//      day 2 -> 60  --> previous: [80]  -> stop -> 1
//      day 3 -> 70  --> previous: [60] -> count -> stop at 80 -> 2
//      day 5 -> 75  --> previous: [60, 70] -> count -> stop at 80 -> 4
//      day 6 -> 85  --> previous: [75, 60, 70, 60, 80] -> count -> stop at 100 -> 6

// find disstnce to previous greater element

#include <bits/stdc++.h>
using namespace std;

// brute force
// for each element -> go left util greater element found
// complexity -> time: O(n^2)
vector<int> stockSpan (vector<int> &price) {
    int n = price.size();
    vector<int> span(n);
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (price[j] <= price [i])
                count++;
            else
                break;
        }
        span[i] = count;
    }
    return span;
}

// optimal approach -> Monotonic stack
// use stack to store indices
// find previous greater element
// while price[stack.top()] <= current -> POP
// span = i - stack.top()
// if empty -> span = i + 1
// complexity -> timme: O(n), space: O(n)
vector<int> stockSpanOptimal (vector<int> &price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> st;  // store indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }
        if (st.empty())
            span[i] = i + 1;
        else
            span[i] = i - st.top();
        st.push(i);
    }
    return span;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stockSpanOptimal(price);
    for (int val : span)
        cout << val << " ";
    return 0;
}