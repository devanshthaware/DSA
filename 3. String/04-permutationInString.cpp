// Permutation in string
// this is a sliding window + frequency map problem
// it checks if any permutation of one string is a substring of another
// given two string s1 and s2, return true if s2 contains a permutation of s1
// in other words, check if a substring of s2 is an anagram (permutation) of s1
// example -> input: s1 = "ab", s2 = "eidbaoo"
//            output: true
// why? -> one peermutation of "ab" is "ba", which is a substring of "eiddbaoo"

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n * klogk) (k = length of s1)
// generate all substrings of length s1.length() in s2
// sort substring and compare with sorted s1
bool checkInclusion(string s1, string s2)
{
    int k = s1.length();
    sort(s1.begin(), s1.end());
    for (int i = 0; i <= s2.length() - k; i++)
    {
        string temp = s2.substr(i, k);
        sort(temp.begin(), temp.end());
        if (temp == s1)
            return true;
    }
    return false;
}

// better approach (frequency count check) - O(26 * n) ~ O(n)
// maintain frequency arrays of size 26
// for each window of size k, compare frequency arrays
bool checkInclusionBetter(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;
    vector<int> freq1(26, 0), freq2(26, 0);
    for (char c : s1)
        freq1[c - 'a']++;
    int k = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        freq2[s2[i] - 'a']++;

        if (i >= k)
            freq2[s2[i - k] - 'a']--;

        if (freq1 == freq2)
            return true;
    }
    return false;
}

// optimal approach (sliding window + match count) - O(n)
// instead of comparing full arrays every time:
// keep a count of matching characters
// only update when sliding window changes
// avoid full array comparison
bool checkInclusionOptimal(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;
    vector<int> freq(26, 0);
    for (char c : s1)
        freq[c - 'a']++;
    int left = 0, right = 0;
    int required = s1.length();
    while (right < s2.length())
    {
        if (freq[s2[right] - 'a'] > 0)
            required--;
        freq[s2[right] - 'a']--;
        right++;
        if (required == 0)
            return true;
        if (right - left == s1.length())
        {
            if (freq[s2[left] - 'a'] >= 0)
                required++;

            freq[s2[left] - 'a']++;
            left++;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1 = "ab", s2 = "eidbaoo";
    cout<< "Permutation in string (brute): " << (checkInclusion(s1, s2) ? "True" : "False") << "\n";
    cout<< "Permutation in string (better): " << (checkInclusionBetter(s1, s2) ? "True" : "False") << "\n";
    cout<< "Permutation in string (optimal): " << (checkInclusionOptimal(s1, s2) ? "True" : "False") << "\n";
    return 0;
}