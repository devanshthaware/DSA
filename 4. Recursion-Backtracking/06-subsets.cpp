// Subsets
// here, we return all subsets as a list (not just print them)
// example -> input: [1, 2, 3]
//            output: [
//                      [],
//                      [1],
//                      [2],
//                      [3],
//                      [1, 2],
//                      [1, 3],
//                      [2, 3],
//                      [1, 2, 3],
//                    ]

#include <bits/stdc++.h>
using namespace std;

// approach -> same recursive approach
// but instead of printing, store each subset in a result list
void backtrack (int index, vector<int>& arr, vector<int>& subset, vector<vector<int>>& result){
    if (index == arr.size()){
        result.push_back(subset);
        return;
    }
    // include arr[index]
    subset.push_back(arr[index]);
    backtrack(index + 1, arr, subset, result);
    // exclude arr[index]
    subset.pop_back();
    backtrack(index + 1, arr, subset, result);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(0, arr, subset, result);
    cout << "[";
    for (int i = 0; i < result.size(); i++){
        cout << "[";

        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        ;
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]" << "\n";
    return 0;
}