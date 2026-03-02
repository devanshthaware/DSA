// Group anagrams
// given an array of strings strs, group the anagrams together
// example ->   Input:  ["eat","tea","tan","ate","nat","bat"]
//              Output : [
//                          [ "eat", "tea", "ate" ],
//                          [ "tan", "nat" ],
//                          ["bat"]
//                       ]

#include <bits/stdc++.h>
using namespace std;

// better approach (sorting) - O(n * klogk) (k = length of string), space = O(nk)
// sort each string
// use sorted string as key in hashmap
// strings with same sorted form -> same group
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string s : strs)
    {
        string key = s;
        sort(key.begin(), key.end()); // sorted form
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &it : mp)
        result.push_back(it.second);
    return result;
}

// optimal approach - O(n * k), space = O(nk)
// count frequency of each character
// convert frequency array to string key
// use hashmap
vector<vector<string>> groupAnagramsOptimal(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string s : strs)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        string key = "";
        for (int i = 0; i < 26; i++)
        {
            key += "#";
            key += to_string(freq[i]);
        }
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto &it : mp)
        result.push_back(it.second);
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    for (auto &group : result)
    {
        cout << "[ ";
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}