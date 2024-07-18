#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

const ll Max_N = 1e6+10;
const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll base = 31;

ll n, p, l, A[1000001], B[1000001];
double dp[1000001];

void input()
{
    cin >> n >> p >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i] >> B[i];
    }
}

double thoi_gian(int a, int b)
{
    ll weight = 0, min_speed = 1e9;
    for (int i = a; i <= b; i++)
    {
        if (weight + A[i] <= p)
        {
            min_speed = min(min_speed, B[i]);
            weight += A[i];
        }
        else return 1e9; 
    }

    return l/(min_speed*1.0);
}


void solve()
{
    for (int i = 0; i <= n; i++) dp[i] = 1e9;

    dp[1] = l/B[1];
    dp[0] = l/B[1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i-1; j++)
        {
            dp[i] = min(dp[i], (double) dp[j-1] + thoi_gian(j, i));
        }
    }

    cout << setprecision(2) << fixed << (double) dp[n];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("DOANXE.INP","r",stdin);
    freopen("DOANXE.OUT","w",stdout);
    int t = 1; //cin >> t;
    while (t--)
    {
        input(), solve();
    }
}