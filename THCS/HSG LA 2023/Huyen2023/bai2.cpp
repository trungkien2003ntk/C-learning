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
set<char> s1ch, s2ch, sab, sba;
string s1, s2;

int main()
{
    fast_io;
    cin >> s1 >> s2;
    for (auto it : s1)
        s1ch.insert(it);
    for (auto it : s2)
        s2ch.insert(it);

    // for (auto it : s1ch)
    //     cout << it << " ";
    // cout << "\n";
    // for (auto it : s2ch)
    //     cout << it << " ";

    if (s1ch == s2ch)
        for (auto it : s1ch)
            cout << it;
    else
    {
        set_difference(s1ch.begin(), s1ch.end(), s2ch.begin(), s2ch.end(), inserter(sab, sab.begin()));
        set_difference(s2ch.begin(), s2ch.end(), s1ch.begin(), s1ch.end(), inserter(sba, sba.begin()));
        for (auto it : sab)
            cout << it;
        for (auto it : sba)
            cout << it;
    }

    // getchar();
}