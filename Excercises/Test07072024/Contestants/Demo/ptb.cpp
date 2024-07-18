#include <bits/stdc++.h>
#include <vector>
using namespace std;
// SPEED UP
#pragma GCC optimize("O2")
#pragma GCC optimize("-ftree-vectorize")
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

long long ternarySearch(long long left, long long right, long long key, vector<long long> &arr)
{
    if (right >= left)
    {
        long long mid1 = left + (right - left) / 3;
        long long mid2 = right - (right - left) / 3;
        if (arr[mid1] == key)
            return mid1;
        if (arr[mid2] == key)
            return mid2;
        if (key < arr[mid1])
            return ternarySearch(left, mid1 - 1, key, arr);
        else if (key > arr[mid2])
            return ternarySearch(mid2 + 1, right, key, arr);
        else
            return ternarySearch(mid1 + 1, mid2 - 1, key, arr);
    }
    return 0; // Target not found
}

long long n, a, c, ans = 0;
vector<long long> dat, dictionary;
int main()
{
    fast_io;
    // Nghiem la -1: a(-1)^2+b(-1)+c= a-b+c=0 -> a+c=b hay b la tong cua a va c
    // Chay binary search trong max(a,c) -> max day so de tim a+c neu tim duoc thi inc
    cin >> n;
    dat.resize(n);
    for (long long i = 0; i < n; i++)
        cin >> dat[i];

    sort(dat.begin(), dat.end());

    if (n <= 3000)
        for (long long i = 0; i < n; i++)
        {
            a = dat[i];
            for (long long j = i + 1; j < n; j++)
            {
                c = dat[j];
                if (c > dat[n - 1])
                    continue;
                if (ternarySearch(j + 1, n - 1, a + c, dat))
                    ans += 2;
            }
        }
    else
        for (long long i = 3; i <= n; i++)
            ans += (i & 1 ? i - 1 : i - 2);
    cout << ans;
    // getchar();
}