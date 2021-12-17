#include<bits/stdc++.h>

using namespace std;

string str[10000];
int sochuoi;

void nhap()
{
	cin >>sochuoi;
	cin.ignore();
	for (int i=1;i<=sochuoi;i++){
		getline(cin,str[i]);
	}
}

bool la_chu_thuong(char kt)
{
	if ('a'<=kt && kt<='z')
		return true;
	return false;
}

bool la_chu_hoa(char kt)
{
	if ('A'<=kt && kt <='Z')
		return true;
	return false;
}

char viet_thuong(char kt)
{
	return kt+'a'-'A';
}

char viet_hoa(char kt)
{
	return kt+'A'-'a';
}

string chuanhoa(string st)
{
	string chuoimoi="";
	for (int i=0;i<st.size();i++)
	{
		if (la_chu_thuong(st[0])&&i==0)
			chuoimoi+=viet_hoa(st[0]);
		else if (la_chu_hoa(st[i]) && st[i-1]!=' '&&i!=0)
			chuoimoi+=viet_thuong(st[i]);
		else if (la_chu_thuong(st[i]) && st[i-1]==' '&& i!=0)
			chuoimoi+=viet_hoa(st[i]);
		else 
			chuoimoi+=st[i];	
	}
	return chuoimoi;
}

void xuly()
{
	string res[10000],chuoi;
	int cs=0;
	for (int i=1;i<=sochuoi;i++)
	{
		chuoi=chuanhoa(str[i]);
		cs++;
		res[cs]=chuoi;
	}
	for (int i=1;i<=sochuoi;i++)
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

