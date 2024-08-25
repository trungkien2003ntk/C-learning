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
long long t, m, n, tempt, caseAns = 0, c_x1, k1, k2, pred, c_x, coins;
vector<pair<long long, long long>> dat;

int main()
{
    fast_io;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> tempt, dat.push_back({tempt, 0});
        for (int i = 0; i < n; i++)
            cin >> dat[i].second;
        sort(dat.begin(), dat.begin() + n);

        for (int i = 0; i < n; i++)
        {
            // Calculate for the stand alone members
            caseAns = max(caseAns, min(m / dat[i].first, dat[i].second) * dat[i].first);
            // Try if extendable with the next element is just 1 step beside the upper one
            if (i + 1 < n && dat[i + 1].first - dat[i].first == 1)
            {
                // Store the amount of i+1 petals
                c_x1 = dat[i + 1].second;
                // Calculate the maximum amount that can be taken into calculation for last element which have i petals
                k1 = min(m / dat[i].first, dat[i].second);
                // Store the current price paid for i element
                pred = dat[i].first * k1;
                // Update the current amount of i petals after being taken into calculation
                dat[i].second -= k1;
                // Update the remaining amount of coins for calculate with i+1 petals to buy further
                coins = m - pred;
                // Check if coins still valid >= dat[i+1].first
                if (coins >= dat[i + 1].first)
                {
                    // Valid, then now buy the i+1 petals with maximum available between valid coins and valid amount
                    k2 = min(coins / (dat[i + 1].first), c_x1);
                    // Update the current max value of petals we bought
                    pred += k2 * (dat[i + 1].first);
                    // Update the remaining amount of i+1 petals after being bought
                    c_x1 -= k2;
                    // Update the remaining amount of coins
                    coins = m - pred;
                }
                // Update caseAns for max in case we just take the i+1 element ???
                caseAns = max(caseAns, min(m / (dat[i + 1].first), c_x1));

                pred += min(min(coins, c_x1), k1);
                caseAns = max(pred, caseAns);
            }
        }
        cout << caseAns << "\n";
        // Reset caseAns
        caseAns = 0;
        dat.clear();
    }
}