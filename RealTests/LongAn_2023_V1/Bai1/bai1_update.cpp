#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O3") // how good is this? lol
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
//============================================================================
// START PROGRAM
//============================================================================
int n, m, checkM, checkN;

int sDiv(int x)
{
    int kq = 0, i = 1;
    for (; i < sqrt(x); i++)
        if (x % i == 0)
            kq += i + (x / i);
    if (i * i == x)
        kq += i;
    return kq;
}

int main()
{
    fast_io;
    cin >> n;
    m = n + 1;
    checkM = sDiv(m);
    checkN = sDiv(n);
    while (checkM * n != checkN * m)
        checkM = sDiv(++m);
    cout << m;

    // getchar();
}