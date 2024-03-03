#include <bits/stdc++.h>

using namespace std;
// SPEED UP
// #pragma GCC optimize("O3") // how good is this? lol
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
// #pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
long long n, a[100008], res = 0, i, mid;

int main()
{
    fast_io;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    mid = (n & 1 ? (n >> 1) + 1 : n >> 1);

    for (i = n - 1; i >= mid; i--)
        res += 2 * a[i];

    if (n & 1)
        res += a[i];
    cout << res;
    // getchar();
}