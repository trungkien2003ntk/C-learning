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
long long n, tempt, base, exponent;
const long long MOD = 1e9 + 7;

int main()
{
    fast_io;
    scanf("%lld", &n);

    exponent = n, tempt = 1, base = 2;

    // Calculate 2^n % MOD
    while (exponent > 0)
        if (exponent & 1)
        {
            tempt = (tempt * base) % MOD;
            exponent--;
        }
        else
        {
            base = (base * base) % MOD;
            exponent >>= 1;
        }

    printf("%lld", ((tempt * (3 + tempt) + 2) / 2) % MOD);
    // getchar();
}
