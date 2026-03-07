// Pow(X, n) Power exponential problem --> to compute x^n efficiently, especially for large n

#include <bits/stdc++.h>
using namespace std;

// naive way O(n)
int power(int x, int n)
{
    int result = 1;
    for (int i = 0; i < n; i++)
        result *= x;
    return result;
}

// Binary exponentiation O(logn)
long long powerBinaryExponentiation(long long x, long long n)
{
    long long result = 1;

    while (n > 0)
    {
        if (n % 2 == 1) // if n is odd
            result *= x;

        x *= x; // square the base
        n /= 2; // halve the exponent
    }

    return result;
}

// Recursive version O(logn)
long long powerRsursive(long long x, long long n)
{
    if (n == 0)
        return 1;

    long long half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Power 2^8 (binary exponentiation): " << powerBinaryExponentiation(2, 8) << "\n";
    cout << "Power 2^8 (recursive version): " << powerRsursive(2, 8);

    return 0;
}