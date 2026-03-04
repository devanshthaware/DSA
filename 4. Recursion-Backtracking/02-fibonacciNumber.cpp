// fibonacci sequence is defined as:
// F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2) for n >= 2

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// better approach (memoization) - O(n)
int fibonacciBetter(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacciBetter(n - 1, dp) + fibonacciBetter(n - 2, dp);
}

// optimal approach - O(n)
int fibonacciOptimal(int n)
{
    if (n <= 1)
        return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}