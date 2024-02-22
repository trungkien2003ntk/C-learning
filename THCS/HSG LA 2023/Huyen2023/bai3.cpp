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
bool isPowerOfTwo(int x)
{
    return x && !(x & (x - 1));
}

int n, it;

int main()
{
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> it;
        if (isPowerOfTwo(it - 1))
            cout << it << " ";
    }
    // getchar();
}