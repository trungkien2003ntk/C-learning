#include <iostream>
#include <iomanip>

using namespace std;

int bai13()
{
	int n,i,j;
	cout << "Nhap n: ";
	cin >> n;
	for (j = 1; j <= n*n; j++)
	{
		cout << setw(5) << j;
		if (j % n == 0)
			cout << endl;
	}
	return 0;
}