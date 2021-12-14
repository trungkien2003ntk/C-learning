#include<bits/stdc++.h>

using namespace std;

string xau;

void nhap()
{
	getline(cin,xau);
}

void xuly()
{
	long long tong=0;
	xau=" "+xau;
	for (int i=0;i<xau.size();i++)
	{
		if (xau[i]==' ' && xau[i+1]!=' ' && xau[i+1]!=(char)0)
			tong++;
	}
	cout <<tong <<endl;
	cout <<(char)0;
}

int main()
{
	nhap();
	xuly();
	return 0;
}