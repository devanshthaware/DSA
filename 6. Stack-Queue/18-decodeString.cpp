// Decode string
// given an encoded string, decode it
// encoding rule:
//  k[encoded_string]
// means:
//  repeat encoded_string k times
// example ->   input: "3[a]2[bc]"
//              output: "aaabcbc"
// example ->   input: "3[a2[c]]"
//              output: "accaccacc"
// example ->   input: "2[abc]3[cd]ef"
//              output: "abcabccdcdcdef"

#include <bits/stdc++.h>
using namespace std;

// brute force -> recursion
// complexity -> time: O(n * k) (k = maximum repitition), space: O(n)
// when we see "[", recursively decode inside
// repeat result k times
// return string
string decodeHelper (string &s, size_t &i) {
    string result;
    while (i < s.size() && s[i] != ']') {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i]))
                num = num * 10 + (s[i++] - '0');
            i++; // skip '['
            string decoded = decodeHelper(s, i);
            i++; // skip ']'
            while (num--)
                result += decoded;
        }
        else {
            result += s[i++];
        }
    }
    return result;
}
string decodeString (string s) {
    size_t i = 0;
    return decodeHelper(s, i);
}

// better approach -> two stacks
// complexity -> time: O(n), space: O(n)
// maintain:
//  stack<int> counts
//  stack<string> results
// when:
//  digit -> push number
//  '[' -> push current string
//  ']' -> pop and repeat
string decodeStringBetter (string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string current = "";
    int num = 0;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c == '[') {
            countStack.push(num);
            stringStack.push(current);
            num = 0;
            current = "";
        }
        else if (c == ']') {
            int repeat = countStack.top();
            countStack.pop();
            string temp = stringStack.top();
            stringStack.pop();
            while (repeat--)
                temp += current;
            current = temp;
        }
        else {
            current += c;
        }
    }
    return current;
}

// optimal approach -> single stack
// use one stack of string
// push evry thing until ']', then:
//  pop substring
//  pop [
//  pop digit
//  repeat substring
//  push back
string decodeStringOptimal (string s) {
    stack<string> st;
    for (char c : s) {
        if (c != ']') {
            st.push(string(1, c));
        }
        else {
            string substring = "";
            while (!st.empty() && st.top() != "[") {
                substring = st.top() + substring;
                st.pop();
            }
            st.pop(); // remove '['
            string numstr = "";
            while (!st.empty() && isdigit(st.top()[0])) {
                numstr = st.top() + numstr;
                st.pop();
            }
            int repeat = stoi(numstr);
            string expanded = "";
            while (repeat--)
                expanded += substring;
            st.push(expanded);
        }
    }
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "3[a2[c]]";
    cout << decodeStringOptimal(s);
    return 0;
}