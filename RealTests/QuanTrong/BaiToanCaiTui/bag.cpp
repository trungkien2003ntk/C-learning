// Bai Toan cai tui: https://v1study.com/giai-thuat-va-lap-trinh-phan-3-quy-hoach-dong-%C2%A732-bai-toan-cai-tui.html
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
int n, M, W[100], V[100], bangPA[101][101], bangLuuPA[101][101];

void nhap()
{
	ifstream f("bag.inp");
	f >> n >> M;
	for (int i = 1; i <= n; i++)
		f >> W[i] >> V[i];
	f.close();

	// cout << n << " " << M << endl;
	// for (int i=1;i<=n;i++)
	// 	cout << W[i] << " " << V[i] << endl;
}

void khoiTao()
{
	for (int i = 0; i <= n; i++)
		bangPA[0][i] = 0;
}

void xuly()
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= M; j++)
			// Thuc hien thuat toan quy hoach dong xac dinh bang quy hoach dong
			if (j - W[i] >= 0)
				bangPA[i][j] = max(bangPA[i - 1][j], V[i] + bangPA[i - 1][j - W[i]]);
			else
				bangPA[i][j] = bangPA[i - 1][j];
}

void xuatbangPA()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= M; j++)
			cout << bangPA[i][j] << " ";
		cout << endl;
	}
}

void trackPA()
{
	cout << bangPA[n][M] << endl;
	int i = n;
	int j = M;
	while (i > 0)
	{
		if (bangPA[i][j] != bangPA[i - 1][j])
		{
			cout << i << " ";
			j -= W[i];
		}
		i -= 1;
	}
}

int main()
{
	nhap();
	khoiTao();
	xuly();
	// xuatbangPA();
	trackPA();
	return 0;
}