// File Nop Test
#include <bits/stdc++.h>

using namespace std;

long long n, ques, j = 0;
vector<long long> a, ProfitByDay, res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("VNI.INP", "r", stdin);
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}

	long long temptMaxPrice = a[n - 1];
	ProfitByDay.push_back(0);
	for (int i = n - 2; i >= 0; i--)
	{
		temptMaxPrice = max(temptMaxPrice, a[i]);
		ProfitByDay.push_back(temptMaxPrice - a[i] + ProfitByDay[j++]);
	}
	//	reverse(ProfitByDay.begin(),ProfitByDay.end());

	cin >> ques;
	int tempt;
	for (int i = 0; i < ques; i++)
	{
		cin >> tempt;
		res.push_back(ProfitByDay[n - tempt]);
		// cout << ProfitByDay[n-tempt] << endl;
	}
	fclose(stdin);

	freopen("VNI.OUT", "w", stdout);
	for (auto it : res)
		cout << it << endl;
	fclose(stdout);

	return 0;
}