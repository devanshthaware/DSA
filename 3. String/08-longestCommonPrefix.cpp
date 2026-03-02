// Longest common prefix
// given a vector of strings strs, find the longest common prefix among them
// if none exists → return ""
// example ->   input:  ["flower","flow","flight"]
//              output : "fl"
//              input:  ["dog","racecar","car"]
//              output : ""

#include <bits/stdc++.h>
using namespace std;

// brute force (character by character) - O(n * m) (n = number of string, m = min length)
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        char ch = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
        {
            if (i >= strs[j].size() || strs[j][i] != ch)
                return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

// better approach (sorting) - O(nlogn + m)
// sort strings
// compare only first and last string
// common prefix of these two is answer
// because after sorting:
//  most different strings become far apart
string longestCommonPrefixBetter(vector<string> &strs)
{
    if (strs.empty())
        return "";
    sort(strs.begin(), strs.end());
    string first = strs.front();
    string last = strs.back();
    int i = 0;
    while (i < first.size() && i < last.size() && first[i] == last[i])
        i++;
    return first.substr(0, i);
}

// optimal approach (horizontal scanning) - O(n * m)
// start with prefix = first string
// compare with each string
// reduce prefix until match found
string longestCommonPrefixOptimal(vector<string> &strs)
{
    if (strs.empty())
        return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        while (strs[i].find(prefix) != 0)
        {
            prefix.pop_back();
            if (prefix.empty())
                return "";
        }
    }
    return prefix;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> s = {"flower", "flow", "flight"};
    cout << "Longest common prefix (brute): " << longestCommonPrefix(s) << "\n";
    cout << "Longest common prefix (better): " << longestCommonPrefixBetter(s) << "\n";
    cout << "Longest common prefix (optimal): " << longestCommonPrefixOptimal(s) << "\n";
    return 0;
}