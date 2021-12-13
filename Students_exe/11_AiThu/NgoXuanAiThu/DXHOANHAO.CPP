#include<bits/stdc++.h>

using namespace std;

string st;

void nhapfile()
{
	ifstream f;
	f.open("XAUDX.INP");
	getline(f,st);
	f.close();
}

string reverse(string str)
{
	string chuoidao="";
	for (int i=str.size()-1;i>=0;i--)
	{
		chuoidao+=str[i];
	}
	return chuoidao;
}

bool check_chan(string str)
{
	string st_rev=reverse(st);
	string st1,st2,st_rev1,st_rev2;
	// if (st.size()%2==0){
	st1=st.substr(0,st.size()/2);
	st_rev1=st_rev.substr(0,st_rev.size()/2);
	st_rev1=reverse(st_rev1);
	st2=st.substr(st.size()/2,st.size()-st.size()/2+1);
	st_rev2=st_rev.substr(st_rev.size()/2,st_rev.size()-st_rev.size()/2+1);
	st_rev2=reverse(st_rev2);
	if ((st1==st_rev1)&&(st2==st_rev2))
		return true;
	else
		return false;
}

bool check_le(string str)
{
	string st_rev=reverse(st);
	string st1,st2,st_rev1,st_rev2;
	// if (st.size()%!=0){
	st1=st.substr(0,st.size()/2+1);
	st_rev1=st_rev.substr(0,st_rev.size()/2+1);
	st_rev1=reverse(st_rev1);
	st2=st.substr(st.size()/2,st.size()-st.size()/2+1);
	st_rev2=st_rev.substr(st_rev.size()/2,st_rev.size()-st_rev.size()/2+1);
	st_rev2=reverse(st_rev2);
	if ((st1==st_rev1)&&(st2==st_rev2))
		return true;
	else
		return false;	
}

//void xuly()
//{
//	string st_rev=reverse(st);
//	string st1,st2,st_rev1,st_rev2;
//	if (st.size()%2==0){
//		st1=st.substr(0,st.size()/2);
//		st_rev1=st_rev.substr(0,st_rev.size()/2);
//		st2=st.substr(st.size()/2,st.size()-st.size()/2+1);
//		st_rev2=st_rev.substr(st_rev.size()/2,st_rev.size()-st_rev.size()/2+1);
//		if ((st1==st_rev1)&&(st2==st_rev2))
//			cout << "YES";
//		else
//			cout << "NO";
//	}
//	else
//	{
//		st1=st.substr(0,st.size()/2+1);
//		st_rev1=st_rev.substr(0,st_rev.size()/2+1);
//		st2=st.substr(st.size()/2,st.size()-st.size()/2+1);
//		st_rev2=st_rev.substr(st_rev.size()/2,st_rev.size()-st_rev.size()/2+1);
//		if ((st1==st_rev1)&&(st2==st_rev2))
//			cout << "YES";
//		else
//			cout << "NO";	
//	}
//}

void xuat_file()
{
	ofstream f;
	f.open("XAUDX.OUT");
	if (st.size()%2==0 && check_chan(st))
		f << "YES";
	else if (st.size()%2!=0 && check_le(st))
		f << "YES";
	else
		f << "NO";
	f.close();
}

int main()
{
	nhapfile();
	// xuly();
	xuat_file();
	cout <<reverse(st);
	return 0;
}

