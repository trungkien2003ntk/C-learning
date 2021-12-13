#include <bits/stdc++.h>

using namespace std;
string st;
//void nhap(){
//	ifstream f;
//	f.open("XAUDX.INP");
//	cin>>f;
//	f.close();
//}
void nhap(){
	getline(cin,st);
}
bool lachuhoa(char kt){
	if('A'<=kt&&kt<='Z')
		return 1;
	return 0;	 
}
char viet_thuong(char kt){
	return kt+'a'-'A';
}
void xuli(){
	string st1="";
	for(int i=st.size()-1;i>=0;i++)
			st1[i]=st[i];
	}
	for(int j=0;j<st1.size();j++){
		if(viet_thuong(st[j])==viet_thuong(st1[j]))
			cout << "YES";
		else
			cout << "NO";
	}
}
int main(){
	nhap();
	xuli();
	return 0;
}