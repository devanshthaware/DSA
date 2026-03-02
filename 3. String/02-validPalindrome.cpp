// Valid palindrome
// check if a string is a palindrome, considering only alphanumeric characters and ignoring cases
// example -> input: "A man, a plan, a canal: panama"
//            output: valid palindrome

#include <bits/stdc++.h>
using namespace std;

// brute force - t: O(n), s: O(n)
// create a new string
// kepp only alphanumeric characters
// convert to lowercase
// check if reversed string equals original
bool isPalindrome(string s)
{
    string filtered = "";
    for (char c : s)
    {
        if (isalnum(c))
            filtered += tolower(c);
    }
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}

// optimal approach - t: O(n), s:O(1)
// use two pointer (right, left) to scan from both ends
// skip non-alphanumeric characters
// compared lowercased characters
bool isPalindromeOptimal(string s)
{
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            left++;
        while (left < right && !isalnum(s[right]))
            right--;
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "A man, a plan, a canal: Panama";

    cout << "Palinndrome (brute): " << (isPalindrome(s) ? "Valid Palindrome" : "Not a Palindrome") << "\n";
    cout << "Palinndrome (optimal): " << (isPalindromeOptimal(s) ? "Valid Palindrome" : "Not a Palindrome");

    return 0;
}