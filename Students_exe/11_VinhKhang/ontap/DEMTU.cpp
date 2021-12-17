#include <bits/stdc++.h>

using namespace std;

string st;
int tong=0;
void nhap(){
	getline(cin,st);
}
void xuli(){
	st=st+" ";
	for(int i=0;i<st.size();i++){
		if(st[i]!=' '&&st[i+1]==' '&&st[i+1]!=(char)0)
			tong++;
	}
	cout << tong;
}
int main(){
	nhap();
	xuli();
	return 0;
}