// Minimum Window Substring
// given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window
// if no such substring exists → return ""
// example ->   Input:  s = "ADOBECODEBANC", t = "ABC"
//              Output : "BANC"

#include <bits/stdc++.h>
using namespace std;

// optimal approach - O(n)
// freq[128] -> store required frequency of characters
// required -> number of characters still needed
// left, right -> window pointers
// minLen -> track best window
string minWindow(string s, string t)
{
    if (t.length() > s.length())
        return "";
    vector<int> freq(128, 0);
    for (char c : t)
        freq[c]++;
    int left = 0, right = 0;
    int required = t.length();
    int minLen = INT_MAX;
    int startIndex = 0;
    while (right < s.length())
    {
        if (freq[s[right]] > 0)
            required--;
        freq[s[right]]--;
        right++;
        // Valid window found
        while (required == 0)
        {
            if (right - left < minLen)
            {
                minLen = right - left;
                startIndex = left;
            }
            freq[s[left]]++;
            if (freq[s[left]] > 0)
                required++;
            left++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window: " << minWindow(s, t);
    return 0;
}