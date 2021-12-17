#include<bits/stdc++.h>

using namespace std;

char ktdau,ktcuoi;

void nhap()
{
	cin >>ktdau >>ktcuoi;
}

char viet_hoa(char kt)
{
	return kt+'A'-'a';
}

void xuly()
{
	for (char i=ktdau;i<=ktcuoi;i++)
	{
		cout <<(char)viet_hoa(i) << " ";
	}
}

int main()
{
	nhap();
	xuly();
	return 0;
}