#include<bits/stdc++.h>

using namespace std;

string str;

void nhap()
{
	getline(cin,str);
}

bool la_so(char kt)
{
	if ('0'<=kt && kt<='9')
		return true;
	return false;
}

bool la_chu(char kt)
{
	if (('A'<=kt && kt<='Z') || ('a'<=kt && kt<='z'))
		return true;
	return false;
}

int dem_so(string st)
{
	int tong=0;
	st=st+"a";
	for (int i=0;i<st.size();i++)
	{
		if (la_so(st[i]) && la_chu(st[i+1]))
			tong++;
	}
	return tong;
}

void xuly()
{
	cout <<dem_so(str);
}

int main()
{
	nhap();
	xuly();
	return 0;
}