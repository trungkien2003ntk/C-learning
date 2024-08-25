#include <bits/stdc++.h>
#include <vector>
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
int n, k, tempt, lf, rg, mid, target, cs = 0;
vector<pair<int, int>> a;

int main()
{
    fast_io;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> tempt;
        a.push_back({tempt, i + 1});
    }

    sort(a.begin(), a.end());

    for (; cs < n && target != a[mid].first; cs++)
    {
        target = 2 * k - a[cs].first;
        // Binary Search
        lf = cs + 1, rg = n - 1;
        while (lf <= rg)
        {
            mid = (lf + rg) / 2;
            if (target == a[mid].first)
            {
                cout << a[cs].second << " " << a[mid].second << endl;
                break;
            }

            if (a[mid].first > target)
                rg = mid - 1;
            else
                lf = mid + 1;
        }
    }

    if (cs == n)
        cout << "0 0";

    // getchar();
}