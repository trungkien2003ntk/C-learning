#include <bits/stdc++.h>

using namespace std;
string S,arr[1000];
void nhap_file()
{
	ifstream f;
	f.open(" XAUDX.INP");
	f>>S;
	f.close();	
}
string daoxau( string st)
{
	string st_dao=" ";
	for ( int i=st.	size()-1;i>=0;i--){
		st_dao+=st[i];
	}
	return st_dao;
	
}
bool xaudoixung( string st_new)
{
	string st_dx;
	st_dx=daoxau(st_new);
	if (st_dx==S)
		return true;
	return false;		
}
void dxhoanhao()
{
	
}
void xuat_file()
{
	ifstream f;
	f.open(" XAUDOIXUNG.OUT");
	f>>S;
	f.close();
}
int main()
{
	nhap_file();
	dxhoanhao();
	xuat_file();
	return 0;
}