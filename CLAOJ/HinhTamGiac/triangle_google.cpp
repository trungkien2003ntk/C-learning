#include <bits/stdc++.h>

using namespace std;
// SPEED UP
// #pragma GCC optimize("O3") //how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
long long n, tempt, res;
const long long MOD = 1e9 + 7;

// Efficient modular multiplication to avoid overflow issues
long long mod_mul(long long a, long long b)
{
    long long res = 0;
    a %= MOD; // Reduce a to its residue Modulo mod

    while (b > 0)
    {
        if (b & 1)
        {
            res = (res + a) % MOD;
        }
        a = (a * 2) % MOD;
        b >>= 1; // Right shift b by 1 (equivalent to division by 2)
    }

    return res;
}

// Modular exponentiation using binary exponentiation (square-and-multiply)
long long powMod(long long base, long long exponent)
{
    long long result = 1;
    base %= MOD; // Ensure base is within modulo range

    while (exponent > 0)
    {
        if (exponent & 1)
            // Check if exponent's least significant bit is 1
            result = mod_mul(result, base);
        exponent >>= 1;             // Right shift exponent by 1 (divide by 2)
        base = mod_mul(base, base); // Square base efficiently
    }

    return result;
}

int main()
{
    fast_io;
    cin >> n;

    tempt = powMod(2, n);
    res = ((tempt * (3 + tempt) + 2) / 2) % MOD;
    cout << res;
    // getchar();
}