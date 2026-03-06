// Palindrome partitioning
// palindrome partitioning is the classic backtracking + string problem
// the goal is to split a string such that every substring in the partition is the palindrome
// given a string s, return all possible palindrome partitioning of s
// each partition should contain only palindromic substrings
// example -> Input: s = "aab"
//            Output:
//                      [
//                          ["a","a","b"],
//                          ["aa","b"]
//                      ]
// Explanation
//      a | a | b   → all palindromes
//      aa | b      → all palindromes
// This problem uses Backtracking.
// At each index:
//  Try every substring starting from index
//  If substring is palindrome
//  Add it to current partition
//  Recurse for remaining string
//  Backtrack

#include <bits/stdc++.h>
using namespace std;

// approach
//  Start from index 0
//  Try substring [index → i]
//  If palindrome:
//  add substring
//  recurse from i+1
//  Remove substring (backtrack)
bool isPalindrome(string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
void solve(int index, string &s,
           vector<string> &path,
           vector<vector<string>> &result)
{
    if (index == s.size())
    {
        result.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, path, result);
            path.pop_back(); // backtrack
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> path;
    solve(0, s, path, result);
    return result;
}
// time complexity -> O(N * 2^N)
// Reason:
//      There are 2^(N-1) possible partitions
//      Each palindrome check costs O(N)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (auto &v : ans)
    {
        cout << "[ ";
        for (auto &str : v)
            cout << str << " ";
        cout << "]\n";
    }
    return 0;
}