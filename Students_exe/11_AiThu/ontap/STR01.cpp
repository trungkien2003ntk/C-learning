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

char viet_thuong(char kt)
{
	return kt+'a'-'A';
}

void xuly()
{
	string chuoimoi="";
	for (int i=0;i<str.size();i++)
	{
		if (la_chu_hoa(str[i]))
		{
			str[i]=viet_thuong(str[i]);
			chuoimoi+=str[i];
		}
		else
			chuoimoi+=str[i];
	}
	cout <<chuoimoi;
}

int main()
{
	nhap();
	xuly();
	return 0;
}