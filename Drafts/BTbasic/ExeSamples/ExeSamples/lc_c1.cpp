#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, countsp[100];
	string s[100];
	cin >> n;
	//Loai bo /n dau tien
	cin.ignore();

	for (int i = 1; i <= n; i++)
		getline(cin, s[i]);


	for (int i = 1; i <= n; i++)
	{
		countsp[i] = 0;
		while (s[i].length() > 0)
		{
			if (s[i][0] == ' ')
				countsp[i]++;
			while (s[i][0] == ' ' && s[i].length() > 0)
				s[i].erase(0, 1);
			while (s[i][0] != ' ' && s[i].length() > 0)
				s[i].erase(0, 1);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << countsp[i] << endl;
	return 0;
}