// Created by Sang lớp 9
// Какого черта ты переводишь?
#include <bits/stdc++.h>
using namespace std;
#define Sang 1
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define FOR(i, a, b) for (__typeof(b) i = a, _b = b; i <= _b; ++i)
#define FORD(i, a, b) for (__typeof(a) i = a, _b = b; i >= _b; --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MASK(i) (1ll << (i))
#define BIT(t, i) (((t) >> (i)) & 1)
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

template <class T>
bool minimize(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool maximize(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

//   ****   ****
//  *     *     *
//  *    K.B    *
//    *       *
//       * *

string s, ans;
int n;

void add(string &a, string b)
{
    while ((int)a.size() < (int)b.size())
    {
        a = '0' + a;
    }
    while ((int)a.size() > (int)b.size())
    {
        b = '0' + b;
    }
    string ans = "";
    int du = 0;
    FORD(i, (int)a.size() - 1, 0)
    {
        int tmp = a[i] - '0' + b[i] - '0' + du;
        du = tmp / 10;
        tmp %= 10;
        ans = (char)(tmp + '0') + ans;
    }
    if (du)
        ans = (char)(du + '0') + ans;
    a = ans;
}

int C(int n, int k)
{
    int ans = 1;
    FOR(i, 1, k)
    {
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef Sang
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    cin >> s;
    n = (int)s.size();
    s = '0' + s;
    ans = "";
    FOR(x, 1, n)
    {
        if (s[x] == '0')
            continue;
        FOR(i, 0, n - x)
        {
            int cnt = C(n - x, i);
            if (i == n - x)
                cnt *= (1 << (x - 1)) - 1;
            else
                cnt *= (1 << (x - 1));
            int num = (s[x] - '0') * cnt;
            if (num == 0)
                continue;
            string NUM = to_string(num);
            int k = i;
            while (k--)
                NUM += '0';
            add(ans, NUM);
        }
    }
    // while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());
    cout << ans;

    return 0;
}