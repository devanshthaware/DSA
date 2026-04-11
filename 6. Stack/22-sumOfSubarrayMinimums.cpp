// Sum of subarray minimums
// given an array:
//      arr = [3, 1, 2, 4]
// return:
//      sum of minimum element of every subarray
// example -> input: [3, 1, 2, 4]
//         subarrays:   [3] -> 3
//                      [3, 1] -> 1
//                      [3, 1, 2] -> 1
//                      [3, 1, 2, 4] -> 1
//                      [1] -> 1
//                      [1, 2] -> 1
//                      [1, 2, 4] -> 1
//                      [2] -> 2
//                      [2, 4] -> 2
//                      [4] -> 4
//                  output: 17
// instead of generating all subarrays:
//  count how many subarray use arr[i] as minimum
// formula:
//  contribution of arr[i] =
//      arr[i] * left * right
// where:
//  left = distance to previous smaller element
//  right = distance to next smaller element

#include <bits/stdc++.h>
using namespace std;

// optimal - single pass stack
// complexity -> time: O(n), space: O(n)
// process contributions immediately when popping
int sumSubarrayMinsOptimal (vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
            int mid = st.top();
            st.pop();
            int left;
            if (st.empty())
                left = mid + 1;
            else
                left = mid - st.top();
            int right = i - mid;
            sum += (long long)arr[mid] * left * right;
        }
        st.push(i);
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {3, 1, 2, 4};
    cout << "Optimal: "
         << sumSubarrayMinsOptimal(arr)
         << "\n";
    return 0;
}