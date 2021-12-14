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
	if (la_chu_hoa(kt))
		return kt+'a'-'A';
	return kt;
}

string viet_thuong_chuoi(string st)
{
	string chuoimoi="";
	for (int i=0;i<st.size();i++)
	{
		st[i]=viet_thuong(st[i]);
		chuoimoi+=st[i];
	}
	return chuoimoi;
}

void xuly()
{
	int count[123];
	str=viet_thuong_chuoi(str);
	fill_n(count,123,0);
	for (int i=0;i<str.size();i++)
	{
		count[str[i]]++;
	}
	for (int kitu='0';kitu<'z';kitu++)
	{
		if (count[kitu]!=0)
			cout <<(char)kitu << " " <<count[kitu] <<endl;	
	}
}

int main()
{
	nhap();
	xuly();
	return 0;
}