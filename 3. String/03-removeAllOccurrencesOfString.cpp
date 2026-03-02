// Remove all occurrences of a string
// given a string and a part, remove all occurrences of that part from the original string
// example -> s = "daabcbaabcbc", part = "abc"
//            output: "dab"
// why? --> daabcbaabcbc
//          dabaabcbc
//          dababc
//          dab

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
// keep finding substring using find() and erase it
string removeOccurrences(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

// better approach - O(n * m) (m = lenght of part), space = O(n)
// build string character by character
// after adding a character, check if the end matches part
// if yes -> remove it
string removeOccurrencesBetter(string s, string part)
{
    string result = "";
    int m = part.length();
    for (char c : s)
    {
        result += c;

        if (result.length() >= m &&
            result.substr(result.length() - m) == part)
        {
            result.erase(result.length() - m);
        }
    }
    return result;
}

// optimal approach (KMP based) - O(n + m), space = O(n + m)
// use KMP (prefix function / LPS array)
// to efficiently detect matches while building result
// this avoids repeated substring comparisons
vector<int> computeLPS(string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m;)
    {
        if (pattern[i] == pattern[len])
        {
            lps[i++] = ++len;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

string removeOccurrencesOptimal(string s, string part)
{
    vector<int> lps = computeLPS(part);
    string result = "";
    vector<int> matchLen; // track current match length
    int j = 0;
    for (char c : s)
    {
        result += c;
        while (j > 0 && c != part[j])
            j = lps[j - 1];

        if (c == part[j])
            j++;

        matchLen.push_back(j);
        if (j == part.length())
        {
            result.erase(result.length() - part.length());
            matchLen.resize(matchLen.size() - part.length());

            j = matchLen.empty() ? 0 : matchLen.back();
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << "After removal (brute): " << removeOccurrences(s, part) << "\n";
    cout << "After removal (better): " << removeOccurrencesBetter(s, part) << "\n";
    cout << "After removal (optimal): " << removeOccurrencesOptimal(s, part) << "\n";
    return 0;
}