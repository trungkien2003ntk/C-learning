#include <iostream>
#include <iomanip>
using namespace std;

int bai13c2()
{
	int n, i, j;
	cout << "Nhap n: ";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			cout << setw(5) << n * (i-1) + j;
		cout << endl;
	}
	return 0;
}