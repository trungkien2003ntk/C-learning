#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, a[1000000], mark[1000000], cnt = 0, cnt2 = 0;
vector<ll> v;
void check()
{
	for (ll i = 0; i < n; i++)
	{
		if (mark[i] != 1)
		{
			v.push_back(a[i]);
			cnt++;
			mark[i] = 1;
			if (cnt == 3)
			{
				ll a = v[0], b = v[1], c = v[2];
				if (a - b + c == 0)
				{
					cnt2++;
				}
			}
			check();
			mark[i] = 0;
			v.pop_back();
			cnt--;
		}
	}
}
int main()
{
	// freopen("PTB2.INP", "r", stdin);
	// freopen("PTB2.OUT", "w", stdout);
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	check();
	cout << cnt2;
}