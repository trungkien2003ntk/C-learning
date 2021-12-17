#include<bits/stdc++.h>

using namespace std;

int sochuoi;
string xau[101];

void nhap()
{
	cin >>sochuoi;
	for (int i=1;i<=sochuoi;i++)
		getline(cin,xau[i]);
}

bool la_chu(char kt)
{
	if (('A'<=kt && kt<='Z') || ('a'<=kt && kt<='z'))
		return true;
	return false;
}

bool la_space(char kt)
{
	if (kt==' ')
		return true;
	return false;
}

void xuly()
{
	for (int i=1;i<=sochuoi;i++)
	{
		
	}
}