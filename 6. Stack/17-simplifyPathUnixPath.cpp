// Simplify path (unix path)
// Given a string path, return the canonical path
// rules ->
// "." -> current directory -> ignore
// ".." -> go back one directory
// multiple / -> treat as a single /
// must start with /
// no trailing / (unless root)
// example ->   input: "/home//foo/"
//              output: "/home/foo"
//              input: "/a/./b/../../c/"
//              output: "/c"
#include <bits/stdc++.h>
using namespace std;

// brute force -> repeated string processing
// complexity -> time: O(n^2), space: O(1)
// keep modifying the string
// remove pattern repeatedly:
//  "//" -> /
//  "/./" -> /
//  "/dir/../" -> remove previous directory
// this simulates path cleanup using string operations only
string simplifyPath (string path) {
    // remove multiple slashes
    while ((path.find("//")) != string::npos)
        path.replace(path.find("//"), 2, "/");
    // remove "/./"
    while ((path.find("/./")) != string::npos)
        path.replace(path.find("/./"), 3, "/");
    // handle "/../"
    size_t pos;
    while ((pos = path.find("/../")) != string::npos) {
        if (pos == 0) {
            path.replace(0, 4, "/");
        }
        else {
            int prev = path.rfind('/', pos - 1);
            path.erase(prev, pos - prev + 4);
        }
    }
    if (path.size() > 1 && path.back() == '/')
        path.pop_back();
    return path;
}

// better approach -> vector instead of stack
// complexity -> time: O(n), space: O(n)
// split path using /
// store valid directories in vector
// handle ".." by popping last element
// join result
// same logic as stack but simpler structure
string simplifyPathBetter (string path) {
    vector<string> dirs;
    string temp;
    for (size_t i = 0; i <= path.size(); i++) {
        if (i == path.size() || path[i] == '/') {
            if (temp == "..") {
                if (!dirs.empty())
                    dirs.pop_back();
            }
            else if (temp != "" && temp != ".") {
                dirs.push_back(temp);
            }
            temp = "";
        }
        else {
            temp += path[i];
        }
    }
    string result = "/";
    for (size_t i = 0; i < dirs.size(); i++) {
        result += dirs[i];
        if (i != dirs.size() - 1)
            result += "/";
    }
    return result;
}

// optimal approach -> stack 
// complexity -> time: O(n), space: O(n)
// use stack because problem is naturally LIFO:
//  go into directory -> push
//  go back ("..")    -> pop
// logic:
//  split path by /
//  use stack
//  for each token:
//      ".." -> pop
//      "." or "" -> ignore
//      otherwise -> push
//  join stack with /
string simplifyPathOptimal (string path) {
    stack<string> st;
    string temp;
    for (size_t i = 0; i <= path.size(); i++) {
        if (i == path.size() || path[i] == '/') {
            if (temp == "..") {
                if (!st.empty())
                    st.pop();
            } 
            else if (temp != "" && temp != ".") {
                st.push(temp);
            }
            temp = "";
        }
        else {
            temp += path[i];
        }
    }
    vector<string> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    string ans = "/";
    for (size_t i = 0; i < result.size(); i++) {
        ans += result[i];
        if (i != (result.size() - 1))
            ans += "/";
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string path = "/a/./b/../../c/";
    cout << simplifyPathOptimal(path) << "\n";
    return 0;
}