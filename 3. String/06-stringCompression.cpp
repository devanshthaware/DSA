// String compression problem
// this problem asks you to compress a character array in-place, replacing consecutive repeated characters with the character followed by the count
// given a character array chars, compress it in-place using the following rules:
// (1) if a character appears more than once consecutively, replace it with the character followed by the count
// (2) the final result should be stored in the original array and the function should return the new length of the  array
// (3) you must use only O(1) extra space
// example -> input: ['a','a','b','b','c','c','c']
//            output : [ 'a', '2', 'b', '2', 'c', '3' ] Return : 6

#include <bits/stdc++.h>
using namespace std;

// optimal approch - O(n)
// i -> read pointer
// index -> write pointer
// count consecuticve characters
// write character and count (digit by digit)
int compress(vector<char> &chars)
{
    int n = chars.size();
    int index = 0; // write pointer
    int i = 0;     // read pointer
    while (i < n)
    {
        char current = chars[i];
        int count = 0;
        // Count duplicates
        while (i < n && chars[i] == current)
        {
            i++;
            count++;
        }
        // Write character
        chars[index++] = current;
        // Write count if > 1
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char c : cnt)
                chars[index++] = c;
        }
    }
    return index;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);
    cout << "Compress: ";
    for (int i = 0; i < newLength; i++){
        cout << chars[i] << " ";
    }
    cout << "\nLength: " << newLength << "\n";
    return 0;
}