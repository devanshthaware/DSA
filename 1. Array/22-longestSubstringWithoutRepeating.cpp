// Longest substring without repeating
// given a string s, find the length of the longest substring without repeating characters
// example --> input:  "pwwkew"
//             output : 3
// why? --> ("wke")

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^3)
int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> freq(256, 0);
            bool valid = true;
            for (int k = i; k <= j; k++)
            {
                if (freq[s[k]] == 1)
                {
                    valid = false;
                    break;
                }
                freq[s[k]]++;
            }
            if (valid)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// better approach (sliding window + set) - O(2n)
// use two pointers and a set:
// expand right pointer
// if duplicate found → shrink from left
int lengthOfLongestSubstringBetter (string s)
{
    int n = s.length();
    int left = 0, right = 0;
    int maxLen = 0;
    unordered_set<char> st;
    while (right < n)
    {
        if (st.find(s[right]) == st.end())
        {
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        else
        {
            st.erase(s[left]);
            left++;
        }
    }
    return maxLen;
}

// optimal approach (sliding window + hash map) - O(n)
// instead of removing characters one-by-one
// directly jump the left pointer using last seen index
int lengthOfLongestSubstringOptimal(string s)
{
    vector<int> lastIndex(256, -1);
    int left = 0;
    int maxLen = 0;
    for (int right = 0; right < s.length(); right++)
    {
        if (lastIndex[s[right]] >= left)
        {
            left = lastIndex[s[right]] + 1;
        }
        lastIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}