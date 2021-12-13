#include <bits/stdc++.h>

using namespace std;
int T;
string st;
int tong,cs=0,so=0;
int kq[100000];
void nhap()
{
	cin>>T;
	cin.ignore();
}
void xuli(){
	for(int i=1;i<=T;i++){
		getline(cin,st);
		tong=0;
		for(int j=0;j<st.size();j++){
			so=st[j]-'0';
			tong+=so;
		}
		cs++;
		kq[cs]=tong;
	}
	for (int i=1;i<=T;i++){
		cout << kq[i] <<endl;
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}