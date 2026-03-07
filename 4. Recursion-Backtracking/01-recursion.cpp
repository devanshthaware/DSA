// Recursion
// recursion is a programminng technique where a function calls itself directly or indirectly to solve a smaller subproblem of the original problem
// recursion is a method of solving a problem where the solution depends on solution to smaller instances of the same problem
// recursive function (structure):
//  a recursive function must have:
//      base case - the condition where recursion stop
//      recursive case - the part where the function calls itself
// call stack -> every time a function is called, it is pushed on the stack
// when the case is reached, the function are popped in reverse order
// recursion tree -> it is a tree-like diagram showing how recursive calls break a problem into subproblems
// math of recursion -> let's say a function f(n) calls itself with (f(n-1)) once and does O(1) work:
// time complexity = T(n) = T(n - 1) + O(1)
// solving gives: T(n) = O(n)
// recurrrence relation -> it express the time complexity of a recursive function:
// T(n) = T(n - 1) + O(1)

#include <bits/stdc++.h>
using namespace std;

int factorial (int n){
    if (n == 0 || n == 1)
        return 1; // base case
    return n * factorial(n - 1); // recursive case
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << factorial(5);

    return 0;
}