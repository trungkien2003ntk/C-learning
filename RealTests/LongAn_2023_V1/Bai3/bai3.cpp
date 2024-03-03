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
long long dat[1296], n, ini;
bool sig = 0;
string st;

void roll(long long x)
{
    if (!dat[x])
    {
        st = to_string(x);
        for (char ch : st)
            dat[x] += dat[ch - '0'];

        if (dat[x] == 1)
            sig = 1;
        else
            roll(dat[x]);
    }
}

int main()
{
    fast_io;
    cin >> n;
    for (int i = 1; i < 10; i++)
        dat[i] = i * i;

    while (!sig)
    {
        ini = 0;
        st = to_string(++n);
        for (char ch : st)
            ini += dat[ch - '0'];
        roll(ini);
    }

    cout << n;
    // getchar();
}