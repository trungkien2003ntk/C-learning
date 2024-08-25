#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

const ll Max_N = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll base = 31;

long long n, m, k, A[10000001];
void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

bool check(int mid)
{
    int cnt = 0, pre = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] - A[pre] > mid || i - pre + 1 > k)
        {
            cnt++;
            pre = i;
        }
    }
    return cnt + 1 <= m;
}

void solve()
{
    sort(A, A + n);

    int l = 0, r = A[n - 1] - A[0];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << l;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("chiahet.INP","r",stdin);
    // freopen("chiahet.OUT","w",stdout);
    int t = 1; // cin >> t;
    while (t--)
    {
        input(), solve();
    }
}