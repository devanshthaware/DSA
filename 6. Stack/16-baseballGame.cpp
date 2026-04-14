// Baseball Game
// you are keeping score for a baseball game with a list of operations
// each operation can be:
//  integer -> record a new score
//  "+" -> record sum of previous scores
//  "D" -> record double of previous score
//  "C" -> invalidate previous score
// return the total score after all operation
// example ->   input: ["5", "2", "C", "D", "+"]
//              output: 30
// why? ->  "5" -> add 5
//              score: [5]
//          "2" -> add 2
//              score: [5, 2]
//          "C" -> remove last score
//              score: [5]
//          "D" -> double last score -> 10
//              score: [5, 10]
//          "+" -> sum last two -> 5 + 10 = 15
//              score: [5, 10, 15]
//          total = 5 + 10 + 15 = 30

#include <bits/stdc++.h>
using namespace std;

// brute force
// maintain an array of scores and compute total only at end
// use vector operations directly
// complexity -> time: O(n), space: O(n)
class Solution {
public:
    int calPoints (vector<string> &operation) {
        vector<int> scores;
        for (const string &op : operation) {
            if (op == "C") {
                if (!scores.empty())
                    scores.pop_back();
            }
            else if (op == "D") {
                if (!scores.empty())
                    scores.push_back(scores.back() * 2);
            }
            else if (op == "+") {
                int n = scores.size();
                if (n >= 2)
                    scores.push_back(scores[n - 1] + scores[n - 2]);
            }
            else {
                scores.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (int s : scores)
            sum += s;
        return sum;
    }
};

// better approach ->
// complexity -> time: O(n), space: O(n)
// instead of summing at the end, maintain running total
// this avoid an extra loop
class SoluionBetter {
public:
    int calPoints (vector<string> &operations) {
        vector<int> scores;
        int total = 0;
        for (string op : operations) {
            if (op == "C") {
                total -= scores.back();
                scores.pop_back();
            }
            else if (op == "D") {
                int val = scores.back() * 2;
                scores.push_back(val);
                total += val;
            }
            else if (op == "+") {
                int n = scores.size();
                int val = scores[n - 1] + scores[n - 2];
                scores.push_back(val);
                total += val;
            }
            else {
                int val = stoi(op);
                scores.push_back(val);
                total += val;
            }
        }
        return total;
    }
};

// optimal -> monotonic stack
// for each operation:
//  if number -> push
//  if C -> pop
//  if D -> push top * 2
//  if + -> push top + second_top
class SolutionOptimal {
public:
    int calPoints (vector<string> &operations) {
        stack<int> st;
        for (string op : operations) {
            if (op == "C") {
                st.pop();
            }
            else if (op == "D") {
                st.push(st.top() * 2);
            }
            else if (op == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            }
            else {
                st.push(stoi(op));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> operations = {"5", "2", "C", "D", "+"};
    SolutionOptimal obj;
    int result = obj.calPoints(operations);
    cout << "Final Score: " << result << "\n";
    return 0;
}