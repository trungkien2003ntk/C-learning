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

int tongUoc(int x)
{
    int res = 0;
    for (int i = 1; i < sqrt(x); i++)
    {
        if (x % i == 0)
            res += (i + (x / i));
    }
    return res;
}

int k;

int main()
{
    fast_io;
    cin >> k;

    for (int i = 1; i < k; i++)
        for (int j = i + 1; j <= k; j++)
            if (tongUoc(i) == tongUoc(j))
                cout << i << " " << j << "\n";

    // getchar();
}