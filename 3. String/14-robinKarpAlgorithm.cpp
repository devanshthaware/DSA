// Robin Karp
// find all occurrences of a pattern pat in a text txt
// Instead of comparing characters one by one (like Naive),
// we:
//  Compute hash of pattern
//  Compute hash of first window of text
//  Slide window using rolling hash
//  If hash matches → verify characters

// When To Use
//  Multiple pattern matching
//  Large text search
//  Competitive programming string problems

// Average case: O(n + m)
// Best for multiple pattern matching
// Used in plagiarism detection, substring search

// Rolling Hash Formula
// For string:
//  hash = (s[0]*d^(m-1) + s[1]*d^(m-2) + ... + s[m-1]) % q
// Where:
//  d = number of characters (usually 256 for ASCII)
//  q = large prime number (to reduce collisions)

// Algorithm steps
//  Compute pattern hash
//  Compute first window hash
//  Slide window:
//  Remove leading char
//  Add trailing char
//  If hash matches → verify substring

#include <bits/stdc++.h>
using namespace std;

#define d 256 // number of characters

void rabinKarp(string txt, string pat, int q)
{
    int n = txt.length();
    int m = pat.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;
    // Compute h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;
    // Compute initial hash values
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    // Slide window
    for (int i = 0; i <= n - m; i++)
    {
        // If hash matches, verify characters
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index: " << i << endl;
        }
        // Compute next window hash
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";
    int q = 101; // prime number

    rabinKarp(txt, pat, q);
    return 0;
}