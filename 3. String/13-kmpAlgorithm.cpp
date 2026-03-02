// KMP Algorithm (Knuth–Morris–Pratt)
// Given:
//  Text txt
//  Pattern pat
// Find all occurrences of pat in txt efficiently
// Why KMP?
//  Naive pattern matching:
//      Time = O(n × m)
//  KMP improves it to:
//      O(n + m)
// By avoiding unnecessary comparisons.

// When mismatch occurs:
//  Don’t restart from beginning
//  Use information from pattern itself
// This is done using:
//  LPS Array (Longest Prefix Suffix)
//  LPS[i] =
//      Length of longest proper prefix
// which is also suffix for substring 0..i
// example -> pattern: A B A B C A B A B
//            LPS: 0 0 1 2 0 1 2 3 4

#include <bits/stdc++.h>
using namespace std;

// step 1: build LPS array
vector<int> buildLPS(string pat)
{
    int m = pat.length();
    vector<int> lps(m, 0);
    int len = 0; // previous longest prefix suffix
    int i = 1;
    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
// step 2: KMP search
vector<int> KMP(string txt, string pat)
{
    vector<int> lps = buildLPS(pat);
    vector<int> result;
    int i = 0; // pointer for txt
    int j = 0; // pointer for pat
    while (i < txt.length())
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == pat.length())
        {
            result.push_back(i - j); // match found
            j = lps[j - 1];
        }
        else if (i < txt.length() && txt[i] != pat[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    vector<int> matches = KMP(txt, pat);
    for (int idx : matches)
        cout << "Pattern found at index: " << idx << "\n";
    return 0;
}