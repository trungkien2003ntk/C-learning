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
const long double eps = 1e-9;

int t, n = 200006;
long long cnt;
bool sig;
long double a[200008], res, need, k;
int main()
{
    fast_io;
    cin >> t;
    while (t--)
    {
        // Case Indicator - Remember to declare cs=0 first
        // cout << "Case " << t << ": " << endl;

        // Reset all
        memset(a, 0, n + 1);
        sig = false;

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 1; i < n; i++)
            if (a[i] == 1 && a[i - 1] > 1)
            {
                sig = true;
                break;
            }

        if (sig)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            for (int i = 0; i < n; i++)
                a[i] = log(log(a[i]));
            res = 0;

            for (int i = 1; i < n; i++)
            {
                if (a[i - 1] > a[i])
                {
                    need = a[i - 1] - a[i];
                    if (need > eps)
                    {
                        cnt = 1 + (need - eps) / log(2);
                        res += cnt;
                        a[i] += cnt * log(2);
                    }
                }
            }
            cout << fixed << setprecision(0) << res << '\n';
        }
    }
    // getchar();
}