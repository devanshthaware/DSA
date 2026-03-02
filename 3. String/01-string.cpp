// Strings and character array
// a character array is a sequence of characters terminated by '\o' (null character)
// stored as char name[] = "devansh"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // character array
    char name[] = "devansh";
    cout << "Name: " << name << "\n";

    // string class (C++ STL)
    // more powerful and safer than character arrays
    // automatically manages memory
    // no need for '\o'
    string a = "Hello";
    a += " World";
    cout << a << "\n";

    // common operation on string
    string s = "Open AI";
    cout << "Length: " << s.length() << "\n";
    cout << "Substring: " << s.substr(0, 4) << "\n";
    cout << "Find: " << s.find("AI") << "\n";
    cout << "Front: " << s.front() << "\n";
    s.insert(0, "hi ");
    s.erase(0, 3); // erase "hi"
    s.replace(0, 4, "Close"); // replace "Open" with close
    cout << "Modified: " << s << "\n";

    // convert between string and character array
    // string -> char array
    string st = "Devansh";
    char ch[100];
    strcpy(ch, s.c_str()); // copy string to char array
    // char array -> string
    char arr[] = "coder";
    string c(arr);

    // looping through strings
    string d = "Code";
    for (char c : d)
        cout << c << " ";

    return 0;
}