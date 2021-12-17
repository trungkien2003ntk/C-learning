#include<bits/stdc++.h>

using namespace std;

string n;

void nhap()
{
	cin >>n;
}

void xuly()
{
	bool check=0;
	string sodadao="";
	for (int i=n.size()-1;i>=0;i--)
	{
		if (!check && n[i]=='0')
		{
			if (n[i-1]!='0')
				check=1;
		}
		else
			sodadao+=n[i];
	}
	cout <<sodadao;
}

int main()
{
	nhap();
	xuly();
	return 0;
}