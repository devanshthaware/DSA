// String compression II
// given a string s and an integer k, delete at most k characters so that the length of its run-length encoding is minimized
// run-length encoding rule:
//      "a" → "a" (length 1)
//      "aa" → "a2" (length 2)
//      "aaa" → "a3" (length 2)
//      "aaaaaaaaaa" → "a10" (length 3)
// example ->   input:  s = "aaabcccd", k = 2
//              output : 4
// why? ->  delete 'b' and 'd'
//          string → "aaaccc"
//          compression → "a3c3" → length = 4

#include <bits/stdc++.h>
using namespace std;

// optimal approach (DP + grouping + greedy counting)
// DP State
//  Let:
//      dp[i][k] = minimum compressed length
//      starting from index i
//      with k deletions left
// Choices at index i
// Delete s[i]
//  dp[i][k] = dp[i+1][k-1]
// Keep s[i] and try forming a group
//  Count how many same characters we can group
//  Track how many deletions needed to maintain continuity
//  Add compression cost of that group
int dp[101][101];
int getLength(int count)
{
    if (count == 1)
        return 1;
    if (count < 10)
        return 2;
    if (count < 100)
        return 3;
    return 4;
}
int solve(string &s, int i, int k)
{
    if (k < 0)
        return 1e9;
    if (i >= s.length())
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];
    // Option 1: Delete current char
    int res = solve(s, i + 1, k - 1);
    // Option 2: Keep current char and form group
    int count = 0;
    int deletions = 0;
    for (int j = i; j < s.length(); j++)
    {
        if (s[j] == s[i])
            count++;
        else
            deletions++;
        if (deletions > k)
            break;
        res = min(res,
                  getLength(count) +
                      solve(s, j + 1, k - deletions));
    }
    return dp[i][k] = res;
}
int getLengthOfOptimalCompression(string s, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(s, 0, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "aaabcccd";
    cout << "Length: " << getLengthOfOptimalCompression(s, 2);
    return 0;
}