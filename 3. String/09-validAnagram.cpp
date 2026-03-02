// Valid anagram
// given two strings s and t, return true if t is an anagram of s, else return false
// an anagram means:
//  same characters
//  same frequency
//  order does NOT matter
// example ->   input:  s = "anagram", t = "nagaram"
//              output : true
//              input:  s = "rat", t = "car"
//              output : false

#include <bits/stdc++.h>
using namespace std;

// brute force approach - O(nlogn)
// sort both string
// compare
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// optimal approach (frequency count) - O(n)
// count characters in s
// subtract using t
// if all counts become zero -> anagram
bool isAnagramOptimal(string s, string t)
{
    if (s.length() != t.length())
        return false;
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;
    for (char c : t)
    {
        freq[c - 'a']--;
        if (freq[c - 'a'] < 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "anagram";
    string t = "nagaram";
    cout << "Is anagram (brute): " << (isAnagram(s, t) ? "True" : "False") << "\n";
    cout << "Is anagram (optimal): " << (isAnagramOptimal(s, t) ? "True" : "False") << "\n";
    return 0;
}