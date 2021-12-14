#include<bits/stdc++.h>

using namespace std;

string str;
int sochudem;
char chudem[101];

void nhap()
{
	getline(cin,str);
	cin >>sochudem;
	for (int i=1;i<=sochudem;i++)
	{
		cin >>chudem[i];
	}
}

bool la_chu(char kt)
{
	if (('a'<=kt&&kt<='z') || ('A'<=kt&&kt<='Z'))
		return true;
	return false;
}

bool la_chu_hoa(char kt)
{
	if ('A'<=kt && kt<='Z')
		return true;
	return false;
}

char viet_thuong(char kt)
{
	if (la_chu_hoa(kt))
		return kt+'a'-'A';
	return kt;
}

void xuly()
{
	int count,res[101],cs=0;
	for (int i=1;i<=sochudem;i++)
	{
		chudem[i]=viet_thuong(chudem[i]);
		count=0;
		for (int j=0;j<str.size();j++)
		{
			str[j]=viet_thuong(str[j]);
			if (chudem[i]==str[j])
				count++;
		}
		cs++;
		res[cs]=count;
	}
	for (int i=1;i<=cs;i++)
	{
		cout <<res[i] <<endl;
	}
}

int main()
{
	nhap();
	xuly();
	return 0;
}