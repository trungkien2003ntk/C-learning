#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a, b, c, i = 2, d = 1, o = 0, z[100000];
unordered_map<ll, ll> mp1, mp2, mp3, mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    while (a > 1)
    {
        while (a % i == 0)
        {
            mp1[i]++;
            a /= i;
            if (mp[i] == 0)
            {
                mp[i] = 1;
                o++;
                z[o] = i;
            }
        }
        i++;
    }
    i = 2;
    while (b > 1)
    {
        while (b % i == 0)
        {
            mp2[i]++;
            b /= i;
            if (mp[i] == 0)
            {
                mp[i] = 1;
                o++;
                z[o] = i;
            }
        }
        i++;
    }
    i = 2;
    while (c > 1)
    {
        while (c % i == 0)
        {
            mp3[i]++;
            c /= i;
            if (mp[i] == 0)
            {
                mp[i] = 1;
                o++;
                z[o] = i;
            }
        }
        i++;
    }
    for (ll i = 1; i <= o; i++)
        for (ll j = 1; j <= (max(mp1[z[i]], max(mp2[z[i]], mp3[z[i]])) + 1) / 2; j++)
            d *= z[i];
    cout << d;
}
