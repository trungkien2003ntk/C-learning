#include <bits/stdc++.h>

using namespace std;
string st;
void nhap(){
	ifstream f;
	f.open("XAUDX.INP");
	f>>st;
	f.close();
}
bool xet_doi_xung(string st){
	string st1="";
	for(int i=st.size()-1;i>=0;i--){
		st1+=st[i];
	}
	if(st1==st)
		return 1;
	return 0;
}
bool xet_dx(string st){
	string st2="";
	string st3;
	for(int i=0;i<st.size();i--){
		if(st.size()%2==0)
			st3=st.substr(0,st.size()/2);
		else
			st3=st.substr(0,st.size()/2+1);
	}
	for(int i=st3.size()-1;i>=0;i--){
		st2+=st3[i];
	}
	if(st2==st3)
		return 1;
	return 0;
}
void xuat(){
	ofstream f;
	f.open("XAUDX.OUT");
	if(xet_doi_xung(st)&&xet_dx(st))
		f<<"YES";
	else
		f<<"NO";
	f.close();
}
int main(){
	nhap();
	xuat();
	return 0;
}