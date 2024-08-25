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
long long n, res = 0, limit = 9876543210;
string s;

bool checkDif(string x)
{
    set<char> dif;
    for (int i = 0; i < x.size(); i++)
        dif.insert(x[i]);
    if (dif.size() == x.length())
        return true;
    else
        return false;
}
int main()
{
    fast_io;
    // 9876543210
    cin >> n;
    limit = min(n, limit);
    for (int i = 5; i <= limit; i += 5)
    {
        if (checkDif(to_string(i)))
            res++;
    }
    cout << res;
    // getchar();
}