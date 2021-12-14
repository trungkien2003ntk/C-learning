#include<bits/stdc++.h>

using namespace std;

int sochuoi;
string chuoi;

void nhap()
{
	cin >>sochuoi;
}

void xuly()
{
	int tong,cs=0,ans[102];
	cin.ignore();
	for (int i=1;i<=sochuoi;i++)
	{
		getline(cin,chuoi);
		tong=0;
		for (int j=1;j<chuoi.size();j++)
		{
			if (chuoi[j]!=' ' && chuoi[j-1]==' ')
				tong++;
		}
		cs++;
		ans[cs]=tong;
	}
	for (int i=1;i<=cs;i++)
	{
		cout <<ans[i] <<endl;
	}
}

int main()
{
	nhap();
	xuly();
	return 0;
}