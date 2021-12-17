#include <iostream>
#include <string>

using namespace std;

int lc_sol2()
{
	int n, countsp[100];
	string s[100];
	cin >> n;

	cin.ignore();
	for (int i = 1; i <= n; i++)
		getline(cin, s[i]);
	for (int i = 1; i <= n; i++)
	{
		countsp[i] = 0;
		for (int j = 0; j <= s[i].length(); j++)
			if (s[i][j] == ' ' && s[i][j + 1] != ' ')
				countsp[i]++;
	}
	for (int i = 1; i <= n; i++)
		cout << countsp[i] << endl;
	return 0;
}