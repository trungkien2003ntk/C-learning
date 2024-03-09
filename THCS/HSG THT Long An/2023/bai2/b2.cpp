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
long long n, a[100008];
long long cs = 0, pos, weight, cnt, ansCount = 0, ansPos = 0, ansWeight = 0;

int main()
{
    fast_io;

    // freopen("CA.INP", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (cs < n)
    {
        while (a[cs] < a[cs + 1] && cs + 1 < n)
            cs++;

        pos = cs, weight = a[cs], cnt = 0;

        while (weight > a[cs + 1] && cs + 1 < n)
            cnt++, weight += a[++cs];
        if (cnt > ansCount)
        {
            ansWeight = weight;
            ansPos = pos;
            ansCount = cnt;
        }
        cs++;
        // cout << pos << " " << weight << " " << cnt << " " << cs << "\n";
    }
    cout << ansPos + 1 << "\n";
    cout << ansWeight << "\n";
    // freopen("CA.OUT", "w", stdout);
    // getchar();
}