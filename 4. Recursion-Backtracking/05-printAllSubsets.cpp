// Print all subsets
// print all subsets (the power set) of a givenn array
// example -> input: [1, 2, 3]
//            output: [], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]

#include <bits/stdc++.h>
using namespace std;

// approach -> start with an empty subsets
// for each element, decide -> include it or exclude it
// move to the next index
// when you reach the end, print the current subset
// backtrack (remove last added element) to explore other branches
void printSubset(int index, vector<int> &arr, vector<int> &subset)
{
    if (index == arr.size())
    {
        cout << "[";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i != subset.size() - 1)
                cout << ", ";
        }
        cout << "]" << "\n";
        return;
    }
    // include arr[index]
    subset.push_back(arr[index]);
    printSubset(index + 1, arr, subset);
    // exculde arr[index]
    subset.pop_back();
    printSubset(index + 1, arr, subset);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {1, 2, 3};
    vector<int> subset;
    printSubset(0, arr, subset);
    return 0;
}