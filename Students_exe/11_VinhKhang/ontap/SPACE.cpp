#include <bits/stdc++.h>

using namespace std;
int T,tong;
int cs=0;
int kq[101];
string st;
void nhap(){
	cin>>T;
	cin.ignore();

}
void xuli(){
	for(int i=1;i<=T;i++){
		tong=0;
		getline(cin,st);
		for(int j=0;j<st.size();j++){
			if(st[j]==' '&&st[j+1]!=' ')
				tong++;
	 	}
		cs++;
		kq[cs]=tong;
	}
	for(int i=1;i<=T;i++){
		cout << kq[i] << endl;
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}