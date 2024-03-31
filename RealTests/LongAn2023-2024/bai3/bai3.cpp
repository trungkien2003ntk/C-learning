#include <bits/stdc++.h>
#include <vector>
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
string s;
long long n, res;
int main()
{
    fast_io;
    cin >> s;
    n = s.size();

    long long res = 0;
    for (int i = 0; i < n; i++)
        res += (s[i] - '0') * (pow(2, i) * pow(11, n - i - 1) - pow(10, n - i - 1));
    cout << res;
    // getchar();
}