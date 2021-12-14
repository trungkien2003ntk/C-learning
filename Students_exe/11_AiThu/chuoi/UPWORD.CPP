#include<bits/stdc++.h>

using namespace std;

string str;

void nhap()
{
	getline(cin,str);
}

bool la_chu_hoa(char kt)
{
	if ('A'<=kt && kt<='Z')
		return true;
	return false;
}

bool la_chu_thuong(char kt)
{
	if ('a'<=kt && kt<='z')
		return true;
	return false;
}

int dem_chu_hoa(string st)
{
	int tong=0;
	st=st+"a";
	for (int i=0;i<st.size();i++)
	{
		if (la_chu_hoa(st[i]) && la_chu_thuong(st[i+1]))
			tong++;
	}
	return tong;
}

void xuly()
{
	cout <<dem_chu_hoa(str);
}

int main()
{
	nhap();
	xuly();
	return 0;
}