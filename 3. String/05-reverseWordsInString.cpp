// Reverse words in string
// you are given a string containing words separated by spaces
// your task is to reverse the order of the words, but not the characters within the words
// given a string s, reverse the words in the string
//      a word is a sequence of non-space characters
//      the output string should not contain leading/trailing spaces
//      multiple spaces between words should be reduced to a single space
// example -> input: "the sky is blue"
//            output: "blue is sky the"

#include <bits/stdc++.h>
using namespace std;

// optimal approach - O(n)
// reverse entire string
// reverse each word
// clean extra spaces
void reverseString(string &s, int left, int right)
{
    while (left < right)
        swap(s[left++], s[right--]);
}
string reverseWords(string s)
{
    int n = s.length();
    reverseString(s, 0, n - 1);
    int start = 0, end = 0;
    while (start < n)
    {
        while (start < n && s[start] == ' ')
            start++;
        if (start >= n)
            break;
        end = start;
        while (end < n && s[end] != ' ')
            end++;
        reverseString(s, start, end - 1);
        start = end;
    }
    // Clean extra spaces
    string result = "";
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i >= n)
            break;
        if (!result.empty())
            result += " ";

        while (i < n && s[i] != ' ')
            result += s[i++];
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s = "the sky is blue";
    cout << '"' << reverseWords(s) << '"' << "\n";
    return 0;
}